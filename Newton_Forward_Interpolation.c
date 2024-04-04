//   This C program finds the Newton's Fortward Intyerpolation , and its difference table ...
#include <stdio.h>

int main() {
    int i,j,n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n], xi, result = 0, term, diff[n][n];

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the interpolating point: ");
    scanf("%f", &xi);

    // Constructing the difference table
    for (i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];
        }
    }

    // Calculating the result using Newton's forward interpolation formula
    term = 1;
    result = diff[0][0];
    for (i = 1; i < n; i++) {
        term *= (xi - x[i - 1]) / (i * 1.0);
        result += term * diff[0][i];
    }

    // Print the difference table
    printf("\nDifference Table:\n");
    printf("x\t");
    for (i = 0; i < n; i++) {
        printf("y%d\t", i);
    }
    printf("\n");
    for ( i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (j = 0; j < n - i; j++) {
            printf("%.2f\t", diff[i][j]);
        }
        printf("\n");
    }

    // Print the result
    printf("\nInterpolated value at x = %.2f is: %.2f\n", xi, result);

    return 0;
}
