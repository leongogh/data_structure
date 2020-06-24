/**
 *  *  n阶德布鲁因环：2^n个0、1组成环（0、1个数相同）, 形成2^n个相邻n个组成一个二进制数且只出现一次, 如2阶：0011 形成4个二进制数0,1,2,3 且都出现一次
 *
 */
#include<cstdio>
#include<cmath>

int main() {
    int m = 0,i,j,t,k,s,n,h,d,m1,m2,x, a[200];

    n = 5;
    m = (int)pow(2, n);
    s = 0;

    for(k = 0; k <= m+n; k++) a[k] = 0;

    a[n] = 1; a[m-1] = 1;
    i = n + 1;

    while(1) {
        if (i == m - 2) {
            for(h = 0, j = n +1; j <= m - 2; j++)
                if (a[j] == 0)h++;

            if (h == m/2 - n) {
                for(t = 0, k = 0; k <= m-2; k++) {
                    for (j = k + 1; j <= m-1; j++) {
                        d = 1; m1 = 0; m2 = 0;
                        for(x = n-1; x >= 0; x--) {
                            m1 = m1 + a[k+x]*d;
                            m2 = m2 + a[j+x]*d;
                            d = d * 2;
                        }
                        if (m1 == m2){ t=1; break; }
                    }
                }

                if (t == 0) {
                    ++s;
                    if (n <= 4 || (n > 4 && s <= 3)) {
                        printf("%d: ", s);
                        for(j =0; j <= m-1; j++) {
                            printf("%d", a[j]);
                        }
                        printf("\n");
                    }
                }
            }
        }

        if (i < m-1) {
            a[++i] = 0; continue;
        }
        while(a[i] == 1 && i > n+1) i--;
        if (a[i] == 1 && i == n+1) break;
        else a[i] = 1;
    }
    return  0;
}