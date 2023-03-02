#include "printMatrix.h"
#include<stdio.h>


//Function that prints the elements of a matrix row-wise, each row is printed in a seperate line
//m=rows in matrix, n= columns in matrix

void printMatrix(int m, int n, double** matrix) {
    int i, j;
    for (i = 0;i < m;i++) {
        for (j = 0;j < n;j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}