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
		if(fclose(fp) == EOF){
			printf("Error occured during closing file");
			return -1;
		}
	}else{
		return -1;
	}

	return matrixSize;
}


double* readMatrix(const char* path, int matrixSize){
	double* matrix;

	FILE* matrixFile = fopen(path, "r");
	fseek(matrixFile, 1, 0);
	if(matrixFile != NULL){
		if(matrixSize != -1){
		 	matrix = (double*) malloc(sizeof(double) * matrixSize * matrixSize);
			int i, j;
			for(i = 0; i < matrixSize; i++){
				for(j = 0; j < matrixSize; j++){
				fscanf(matrixFile, "%lf", &ELEMENT(matrix, matrixSize, i, j));
				}
			}
		}
	}else{
			return NULL;
		}

	if(fclose(matrixFile) == EOF){
		printf("Error occured during closing file");
		return NULL;
	}
	return matrix;

}

double calculateDeterminant(double *matrix, unsigned int matrixSize){
	double determinant = 0;

	if(matrixSize > 2){
		int x;
		double helper;

		double* minor;
		for(x = 0; x < matrixSize; x++){
			minor = createMinor(matrix, matrixSize, x, 0);
			helper = ELEMENT(matrix, matrixSize, x, 0) * pow(-1, x + 1);
			determinant += helper * calculateDeterminant(minor, matrixSize - 1);
		}
		free(minor);
		return determinant;
	}

	if(matrixSize == 2){
		return ELEMENT(matrix, matrixSize, 0, 0) * ELEMENT(matrix, matrixSize, 1, 1)
					- ELEMENT(matrix, matrixSize, 0, 1) * ELEMENT(matrix, matrixSize, 1, 0);
	}
	return determinant;
}

double* createMinor(double *matrix, unsigned int matrixSize, unsigned int x, unsigned int y){
	int i,j, minorIndex = 0;
	double* minor = (double*) malloc(sizeof(double) * (matrixSize-1) * (matrixSize-1));

	for(i = 0; i < matrixSize; i++){
		for(j = 0; j < matrixSize; j++){
			if(i != x){
				if(j != y){
					minor[minorIndex] = ELEMENT(matrix, matrixSize, i, j);
					minorIndex++;
				}
			}
		}
	}

	return minor;
}
