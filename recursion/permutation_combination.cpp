/**
 * 排列 permutation：设数组a存在n个整数1~n.递归函数p(k)从1开始,当k<=m,a[k]取i(1~n),并标记u=0.
 * 组合 combination：对于指定的整数m,n(1<m<=n), 从n个不同元素任取m个. 加上排序是排列.
 */

#include<cstdio>

int a[5], n = 4, r = 2, m = 2, s = 0;

void p(int k) {
    int i, j, u;

    if (k <= m) {
        for(i = 1; i <= n; i++) {
            a[k] = i;
            for(u = 0, j = 1; j <= k-1; j++) {
                if (a[j] == a[k]) {
                    u = 1;
                    break;
                }
            }

            if (u) continue;

            if (k == m) {
                s++;
                for (j = 1; j <= k; j++) {
                    printf("%3d", a[j]);
                }
                printf("\n");
            } else p(k+1);
        }
    }
}

void c(int k) {
    int i, j, u;

    if (k <= m) {
        for(i = 1; i <= n; i++) {
            a[k] = i;
            for(u = 0, j = 1; j <= k-1; j++) {
                if (a[j] >= a[k]) {
                    u = 1;
                    break;
                }
            }
            if (u) continue;

            if (k == m) {
                s++;
                for (j = 1; j <= k; j++) {
                    printf("%3d", a[j]);
                }
                printf("\n");
            } else c(k+1);
        }
    }
}

// 减少循环次数
void comb(int k) {
   int i, j;

   if (k <= m) {
       a[0] = 0;
       for(i = a[k-1] + 1; i <= n - (m - k); i++) {
           a[k] = i;

           if (k == m) {
               s++;
                for(j = 1; j <= k; j++) {
                    printf("%3d", a[j]);
                }
               printf("\n");
           } else comb(k+1);
       }
   }
}

// 复杂排列, 从n个取r(1<r<=n)个与m个相同元素排列, 1~n, m个0. 当k<=r+m,a[k]=i(0~n).标志量u=0.
// input: n: 4 , r: 2, m: 2 output: 72
void p_c(int k) {
    int i, j, u, z_s;

    if (k <= r + m) {
        for(i = 0; i <= n; i++) {
            a[k] = i;

            for(u = 0, j = 1; j <= k - 1; j++) {
                if (a[j] && a[k] == a[j]) {
                    u = 1;
                    break;
                }
            }
            if (u) continue;

            if (k == r+m) {
                for (z_s = 0, j = 1; j <= k; j++) {
                    if (a[j] == 0) z_s++;
                }
                if (z_s == m) {
                    s++;
                    for (j = 1; j <= k; j++) {
                        printf("%3d", a[j]);
                    }
                    printf("\n");
                }
            } else p_c(k+1);
        }
    }
}

int main() {
    //排列 p(1);
    //组合 comb(1);
    p_c(1);
    printf("总数为: %d", s);
    return  0;
}