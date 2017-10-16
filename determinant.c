#include "determinant.h"

int readFileSizeByPath(const char* path){
	FILE* matrixFile = fopen(path, "r");
	return readFileSize(matrixFile);
}

int readFileSize(FILE* fp){
	int matrixSize;

	FILE* matrixFile = fp;

	if( fp != NULL){
		fscanf(matrixFile, "%d", &matrixSize);
	}else{
		return -1;
	}

	return matrixSize;
}


double* readMatrix(const char* path){

	FILE* matrixFile = fopen(path, "r");
	double* matrix;
	int matrixSize;

	if(matrixFile != NULL){
		matrixSize = readFileSize(matrixFile);
		if(matrixSize != -1){
		 	matrix = (double*) malloc(sizeof(double) * matrixSize * matrixSize);
			int i = 0;
			while(i < 16){
				fscanf(matrixFile, "%lf", &matrix[i]);
				i++;
			}
		}else{
			return NULL;
		}
	}

	if(fclose(matrixFile) == EOF){
		printf("Error occured during closing file");
		return NULL;
	}


	return matrix;

}
