#include "header/Headers.h"

struct OldCityRecord {
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;
};

struct CityRecord {
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;
};

namespace std {
	template<>
	struct hash<CityRecord> {
		size_t operator()(const CityRecord& keyIn) {
			return hash<std::string>()(keyIn.Name);
		}
	};
}

void mapsExamples() {
	std::vector<OldCityRecord> cities;
	cities.emplace_back("London", 5000000, 2.4, 9.4);
	cities.emplace_back("Berlin", 5000000, 2.4, 9.4);
	cities.emplace_back("Paris", 5000000, 2.4, 9.4);
	cities.emplace_back("Bejing", 5000000, 2.4, 9.4);
	cities.emplace_back("Tokyo", 5000000, 2.4, 9.4);
	for (const auto& city : cities) {
		if (city.Name == "Berlin") {
			city.Population;
			break;
		}
	}
	std::unordered_map<std::string, CityRecord> cityMap; //std::map & std::unordered_map can be used.
	cityMap["London"] = CityRecord{ "London", 5000000, 2.4, 9.4 };
	cityMap["Berlin"] = CityRecord{ "Berlin", 5000000, 2.4, 9.4 };
	cityMap["Paris"] = CityRecord{ "Paris", 5000000, 2.4, 9.4 };
	cityMap["Bejing"] = CityRecord{ "Bejing", 5000000, 2.4, 9.4 };
	cityMap["Tokyo"] = CityRecord{ "Tokyo", 5000000, 2.4, 9.4 };
	CityRecord& berlinData = cityMap["Berlin"];

	std::unordered_map<CityRecord, uint32_t> foundedMap; //Map using custom keys need hash
	CityRecord londonRecord = CityRecord{ "London", 5000000, 2.4, 9.4 };
	foundedMap[londonRecord] = 43;
	uint32_t londonFounded = foundedMap[londonRecord];

	const auto& newCityMap = cityMap;
	if (newCityMap.find("Paris") != newCityMap.end()) {
		const CityRecord& parisData = newCityMap.at("Paris"); //use .at() when trying to retrieve something without editing the value.
	}

	for (auto& [name, city] : cityMap) { //How to iterate through a map (Vectors are more cache friendly).
		std::cout << name << "\n Population: " << city.Population << std::endl;
	}
}