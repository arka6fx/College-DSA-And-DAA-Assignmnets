//25/02/25
#include <stdio.h>
#include <limits.h>


void matrixChainOrder(int p[], int n) {
    int m[n][n], s[n][n], i,L,k;

    for (i = 1; i < n; i++) m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            } 
        }
    }
    
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
}

int main() {
    int n,i;
    printf("Enter the total no. of dimensions: ");      
    scanf("%d",&n);
    int p[n];
    for ( i = 0; i <n; i++){
        scanf("%d",&p[i]);
    }
    matrixChainOrder(p, n);

    return 0;
}
