#include "determinant.h"

int main(){

	int i, j;


	int matrixSize = readFileSizeByPath("./matrix.txt");
	double* matrix = readMatrix("./matrix.txt", matrixSize);

	if(matrix != NULL){
		if(matrixSize != -1){
			for(i = 0; i < matrixSize; i++){
				for(j = 0; j < matrixSize; j++){
					printf("%.2lf\t", ELEMENT(matrix, matrixSize, i, j));
				}
				printf("\n");
		    }
        }
	}

	printf("\n\nDeterminant: %.2lf\n", calculateDeterminant(matrix, matrixSize));

    free(matrix);



	return 0;
}
