#include <stdio.h>
#define MAX_N 100
long long int memo[MAX_N + 1][MAX_N + 1];
long long int binomialCoeff(int n, int k) 
{
    if (k == 0 || k == n)
        return 1;
    if (memo[n][k] != -1)
        return memo[n][k];
    memo[n][k] = binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
    return memo[n][k];
}
int main() {
    int n, k;
    for (int i = 0; i <= MAX_N; i++) {
        for (int j = 0; j <= i; j++) {
            memo[i][j] = -1;
        }
    }
    printf("Enter the values of n and k: ");
    scanf("%d %d", &n, &k);
    if (n < 0 || k < 0 || k > n) {
        printf("Invalid input\n");
    } else {
        long long int result = binomialCoeff(n, k);
        printf("The binomial coefficient C(%d, %d) is %lld\n", n, k, result);
    }
    return 0;
}

