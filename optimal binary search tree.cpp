#include <stdio.h>
#include <limits.h>

int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
    for (int chainLen = 2; chainLen <= n; chainLen++) {
        for (int i = 0; i <= n - chainLen; i++)
		 { 
            int j = i + chainLen - 1;
            cost[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                int currentCost = ((k > i) ? cost[i][k - 1] : 0) +((k < j) ? cost[k + 1][j] : 0) +sum(freq, i, j);

                if (currentCost < cost[i][j]) {
                    cost[i][j] = currentCost;
                }
            }
        }
    }
    return cost[0][n - 1];
}

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    int result = optimalBST(keys, freq, n);
    printf("Cost of optimal BST is %d\n", result);
    return 0;
}

