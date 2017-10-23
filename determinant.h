#ifndef determinant_h
#define determinant_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ELEMENT(matrix, matrixSize, i, j) *((matrix + i*(matrixSize)) + j)

int readFileSizeByPath(const char* path);
int readFileSize(FILE* fp);
double* readMatrix(const char* path, int matrixSize);
double calculateDeterminant(double *matrix, unsigned int matrixSize);
double* createMinor(double *matrix, unsigned int matrixSize, unsigned int x, unsigned int y);

#endif
