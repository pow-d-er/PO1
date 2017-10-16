#ifndef determinant_h
#define determinant_h
#include <stdio.h>
#include <stdlib.h>

int readFileSizeByPath(const char* path);
int readFileSize(FILE* fp);
double* readMatrix(const char* path);

#endif
