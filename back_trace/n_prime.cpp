/**
 *  n项素数和环问题：从1~n选取若干整数围成环, 环相邻2数之和为素数
 */
#include<cstdio>
#include<cmath>

int main() {
    int m = 0,i,j,t,n, a[2000], b[100];
    n = 20;

    for(i = 1; i <= 2 * n; i++) {
        b[i] = 0;
    }
    b[2]= 1;
    for(i = 3; i <= 2 * n; i+=2) {
        for(t = 1, j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                t = 0;
                break;
            }
        }
        b[i] = t ? 1 : 0;
    }

    a[1] = 1; i = 2; a[i] = 2;
    while(1) {
        t = 1;
        for (j = 1; j < i; j++) {
            if (a[j] == a[i] || b[a[i] + a[i-1]] != 1) {
                t = 0;
                break;
            }
        }
        if (t && i == n && b[a[n] + 1] == 1) {
            printf("%d: ", ++m);
            for(j = 1; j <= n; j++){
                printf("%3d", a[j]);
            }
            printf("\n");
            if (m == 3) return 0;
        }

        if (t && i < n) {
            a[++i] = 2;
            continue;
        }
        while(a[i] == n && i > 1) i--;
        if (i > 1) a[i]++;
        else break;
    }
    return  0;
}