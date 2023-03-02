#include "gaussEliminationLS.h"
#include<stdio.h>
#include<math.h>
/*******
 Function that performs Gauss-Elimination and returns the Upper triangular matrix and solution of equations by
passing the augmented matrix (a) as the parameter, and calculate and store the upperTriangular(Gauss-Eliminated Matrix) in it
x is a pointer that represents the solution vector
********/
void gaussEliminationLS(int m, int n, double** a, double* x) {
    int i, j, k;
    //looping through the rows of the augmented matrix
    for (i = 0;i < m - 1;i++) {
        //Partial Pivoting
        for (k = i + 1;k < m;k++) {
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if (fabs(a[i][i]) < fabs(a[k][i])) {
                //Swap the rows
                for (j = 0;j < n;j++) {
                    double temp;
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
        //Begin Gauss Elimination
        for (k = i + 1;k < m;k++) {
            double  term = a[k][i] / a[i][i];
            for (j = 0;j < n;j++) {
                a[k][j] = a[k][j] - term * a[i][j];
            }
        }

    }
    //Begin Back-substitution
    for (i = m - 1;i >= 0;i--) {
        x[i] = a[i][n - 1];
        for (j = i + 1;j < n - 1;j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

}