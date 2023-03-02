
#include<stdio.h>
#include<math.h>
#include "gaussEliminationLS.h"
#include "printMatrix.h"

int main() {
    //# of data-points
    int count;
    //degree of polynomial
    int n;
    printf("Enter the no. of data-points:\n");
    scanf_s("%d", &count);
    //arrays to store the c and y-axis data-points
    double* x = new double[count];
    double* y = new double[count];
    printf("Enter the x-axis values:\n");
    int i, j;
    for (i = 0;i < count;i++) {
        scanf_s("%lf", &x[i]);
    }
    printf("Enter the y-axis values:\n");
    for (i = 0;i < count;i++) {
        scanf_s("%lf", &y[i]);
    }
    printf("Enter the degree of polynomial to be used:\n");
    scanf_s("%d", &n);
    // an array of size 2*n+1 for storing count, Sig xi, Sig xi^2, ...., etc. which are the independent components of the normal matrix
    double* X = new double[2 * n + 1];
    for (i = 0;i <= 2 * n;i++) {
        X[i] = 0;
        for (j = 0;j < count;j++) {
            X[i] = X[i] + pow(x[j], i);
        }
    }
    //the normal augmented matrix 
    double** B = new double* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        B[i] = new double[n + 2];
    }
    // rhs
    double* Y = new double[ n + 1];
    for (i = 0;i <= n;i++) {
        Y[i] = 0;
        for (j = 0;j < count;j++) {
            Y[i] = Y[i] + pow(x[j], i) * y[j];
        }
    }
    for (i = 0;i <= n;i++) {
        for (j = 0;j <= n;j++) {
            B[i][j] = X[i + j];
        }
    }
    for (i = 0;i <= n;i++) {
        B[i][n + 1] = Y[i];
    }
    double* A = new double[n + 1];
    printf("The polynomial fit is given by the equation:\n");
    printMatrix(n + 1, n + 2, B);
    gaussEliminationLS(n + 1, n + 2, B, A);
    for (i = 0;i <= n;i++) {
        printf("%lfx^%d+", A[i], i);
    }
}