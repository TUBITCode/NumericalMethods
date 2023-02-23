// Write a Program to implement Gauss Elimination Method with pivoting
#include <stdio.h>
#include<math.h>
void gaussElimination(double a[][10], double x[], double b[], int n)
{
    double temp;
    int k;

    for (int i = 0; i < n; i++)
    {
        // Pivoting
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[k][i]))
                k = j;
        }

        if (k != i)
        {
            for (int j = 0; j < n; j++)
            {
                temp = a[i][j];
                a[i][j] = a[k][j];
                a[k][j] = temp;
            }
            temp = b[i];
            b[i] = b[k];
            b[k] = temp;
        }

        // Gaussian elimination
        for (int j = i + 1; j < n; j++)
        {
            temp = a[j][i] / a[i][i];
            b[j] -= temp * b[i];
            for (int k = i; k < n; k++)
                a[j][k] -= temp * a[i][k];
        }
    }

    // Back substitution
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }
}

int main()
{
    double a[10][10], x[10], b[10];
    int n;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix A: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);

    printf("Enter the elements of matrix B: ");
    for (int i = 0; i < n; i++)
        scanf("%lf", &b[i]);

    gaussElimination(a, x, b, n);

    printf("The solution is: \n");
    for (int i = 0; i < n; i++)
        printf("X[%d] = %lf\n", i, x[i]);

    return 0;
}
