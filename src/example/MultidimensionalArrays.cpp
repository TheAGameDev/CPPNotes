#include "header/Headers.h"

//multi-dimensional arrays are simply arrays of arrays (2 for 2D, 3 for 3D)
//a 2Dimensional array requires a pointer of pointers (int** is a pointer pointing to a pointer)
//below example allocated 50 arrays, and each array's location is stored in the "a2d" array
//in a multi-dimensional array, you must not forget to delete the elements of the main array before deleteing the main array, or else you will have a memory leak
void multidimensionalArrayExample() {
    int** a2d = new int* [50];
    for (int i = 0; i < 50; i++)
        a2d[i] = new int[50];
    for (int i = 0; i < 50; i++)
        delete[] a2d[i];
    delete[] a2d;
}

//a 3Dimension array would be adding another pointer, thus be having an array of pointers to pointers
//every additional dimension is simply another for loop of arrays
//instead of using multidimensional arrays, you can have the same code work in a single array and be much more optimal
void multidimensionalArrayExample2() {
    int*** a3d = new int** [50];
    for (int i = 0; i < 50; i++) {
        a3d[i] = new int* [50];
        for (int j = 0; j < 50; j++) {
            a3d[i][j] = new int[50];
        }
    }
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }
    delete[] a3d;
}
