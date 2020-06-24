/**
 *  数码古珠问题： n个整数, 其和s, 部分和完全覆盖[1~s]
 *  回溯设计：
 *    a[0] = 0, a[n] = s, a[1] = 1
 *    a[i] = a[i-1] + 1 ~ s-1 - (n-1-i)
 *    b[t] = a[j] - a[k]， b[t]完全覆盖[1, s-1]
 *
 *
 */
#include<cstdio>

int main() {
    int s, m = 0, i,j,k,d, u,t,n, a[30], b[500];

    s = 31; n = 6;
    a[0] = 0; a[n] = s; a[1] = 1;

    i = 2; a[i] = 2;
    while(1) {
        if (i < n - 1) {
            i++; a[i] = a[i-1]+1; continue;
        } else {
            for(j = n + 1; j <= 2 * n - 1; j++) {
                a[j] = a[j-n] + s;
            }

            for (t = 0, k = 0; k <= n - 1; k++)
                for(j = k + 1; j <= k + n - 1; j++) {
                    b[++t] = a[j] - a[k];
                }

            for(u = 0, d = 1; d <= s-1; d++)
                for(j = 1; j <= t; j++) {
                    if (d == b[j]) {
                        u++;
                        break;
                    }
                }

            if (u == s-1) {
                printf("%d:", ++m);
                for(j = 1; j <= n; j++) {
                    printf("%3d", a[j] - a[j-1]);
                }
                printf("\n");
            }
        }

        while(a[i] == s - 1 - (n - 1 - i) && i > 1)i--;
        if (1 == i) break;
        else a[i]++;
    }

    return  0;
}