#include "header/Headers.h"

struct ProfileResult {
    std::string name;
    long long Start, End;
    uint32_t ThreadID;
};

struct InstrumentationSession {
    std::string Name;
};

class Instrumentor {
private:
    InstrumentationSession* m_CurrentSession;
    std::ofstream m_OutputStream;
    int m_ProfileCount;
public:
    Instrumentor() : m_CurrentSession(nullptr), m_ProfileCount(0) {
    }

    void BeginSession(const std::string& name, const std::string& filePath = "results.json") {
        m_OutputStream.open(filePath);
        WriteHeader();
        m_CurrentSession = new InstrumentationSession{ name };
    }

    void EndSession() {
        WriteFooter();
        m_OutputStream.close();
        delete m_CurrentSession;
        m_CurrentSession = nullptr;
        m_ProfileCount = 0;
    }

    void WriteProfile(const ProfileResult& result) {
        if (m_ProfileCount++ > 0)
            m_OutputStream << ",";

        std::string name = result.name;
        std::replace(name.begin(), name.end(), '"', '\'');

        m_OutputStream << "{";
        m_OutputStream << "\"cat\":\"function\",";
        m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
        m_OutputStream << "\"name\":\"" << name << "\",";
        m_OutputStream << "\"ph\":\"X\",";
        m_OutputStream << "\"pid\":0,";
        m_OutputStream << "\"tid\":" << result.ThreadID << ",";
        m_OutputStream << "\"ts\":" << result.Start;
        m_OutputStream << "}";

        m_OutputStream.flush();
    }

    void WriteHeader() {
        m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
        m_OutputStream.flush();
    }

    void WriteFooter() {
        m_OutputStream << "]}";
        m_OutputStream.flush();
    }

    static Instrumentor& Get() {
        static Instrumentor instance;
        return instance;
    }
};

class InstrumentationTimer {
private:
    const char* m_Name;
    bool m_Stopped;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
public:
    InstrumentationTimer(const char* name) : m_Name(name), m_Stopped(false) {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer() {
        if (!m_Stopped)
            Stop();
    }

    void Stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        std::cout << m_Name << ": " << (end - start) << "ms\n";
        uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
        ProfileResult result = { m_Name, start, end };
        Instrumentor::Get().WriteProfile(result);
        m_Stopped = true;
    }
};

static void Function1() {
    InstrumentationTimer timer("Function1");
    for (int i = 0; i < 1000; i++) {
        std::cout << "Hello World #" << i << std::endl;
    }
}

static void Function2() {
    InstrumentationTimer timer("Function2");
    for (int i = 0; i < 1000; i++) {
        std::cout << "Hello World #" << sqrt(i) << std::endl;
    }
}

//Use chrome tracing to visualize how long a function takes
//chrome requires a .json, so this is how we supply it
//everything between the beginning and end is put in that specific Profiling file
//Once again cannot access files due to XCode not have a solution sandbox like VS...
//Unfortunately cannot demonstrate other features due to the problem :(
void visualBenchmarkingExample() {
    Instrumentor::Get().BeginSession("Profile");
    Function1();
    Function2();
    Instrumentor::Get().EndSession();
}
