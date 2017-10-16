#include "determinant.h"

int main(){

	int i, j;

	double* matrix = readMatrix("./matrix.txt");
	int matrixSize = readFileSizeByPath("./matrix.txt");

	if(matrix != NULL){
		if(matrixSize != -1){
			for(i = 0; i < matrixSize; i++){
				for(j = 0; j < matrixSize; j++){
					printf("%.2lf\t", *i	((matrix + i) + j));
				}
				printf("\n");
		    }
        }
	}

    free(matrix);



	return 0;
}
