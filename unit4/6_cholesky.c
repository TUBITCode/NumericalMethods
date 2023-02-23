//Write a Program to implement Cholesky Method.
#include <stdio.h>
#include <math.h>

void cholesky(double a[][10], int n)
{
    double s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (i+1); j++)
        {
            s = 0;
            for (int k = 0; k < j; k++)
                s += a[i][k] * a[j][k];

            if (i == j)
                a[i][j] = sqrt(a[i][i] - s);
            else
                a[i][j] = (1.0 / a[j][j] * (a[i][j] - s));
        }
    }
}

int main()
{
    double a[10][10];
    int n;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of matrix: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);

    cholesky(a, n);

    printf("The Cholesky factorization of matrix is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%.2lf ", a[i][j]);
        printf("\n");
    }

    return 0;
}
