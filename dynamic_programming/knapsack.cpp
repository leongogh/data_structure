/**
 *  动态规划 点数值三角形 & 边数组三角形
 */
#include<cstdio>
#include<cstring>

#define  N 9

/**
 *
 * 装载问题：载重c1, 载重c2,  n个集中箱wi(i=1,2,...,n)
 * 动态规划设计：
 *  数据结构：
 *  m(i,j)还可载重j, 还可取集中箱编号i,i+1,...,n时最大载重
 *
 *  递推关系：
 *  m(i,j) = w[i] <= j && m(i+1, j-w[i])+w[i] > m(i+1, j)
 *  ? m(i+1, j-w[i])+w[i] > m(i+1, j) :  m(i+1, j)   i=n-1,...,1; j=0,1,...,c1
 *
 *  初始值：
 *  m(n,j) = w[n] > j ? 0 : w[n];
 */
void load() {
    int i,j,s,cw,sw;
    int c1 = 120, c2 = 126;
    int n = 15, w[] = {0, 26, 19, 24, 13, 10,  20, 15, 12, 6, 5,  22, 7, 17, 27, 20};
    int m[N][N]; // N >= max(w[i])

    for(j = 0; j < w[n]; j++)m[n][j] = 0;
    for(j = w[n]; j <= c1; j++)m[n][j] = w[n];

    for(i = n - 1;  i >= 1; i--)
        for(j = 0; j <= c1; j++) {
            if (w[i] <= j && m[i+1][j-w[i]] + w[i] > m[i+1][j]) {
                m[i][j] = m[i+1][j-w[i]] + w[i];
            } else {
                m[i][j] = m[i+1][j];
            }
        }

    // output: 120
    printf("maxcl=%d", m[1][c1]);

    s = 0;
    for(i = 1; i <= n; i++) {
        s += w[i];
    }
    cw = m[1][c1];
    if (s - cw > c2) {
        printf("无解");
    }

    // C1:  15,  12,  22,   7,  17,  27,  20
    printf("\nC1: ");
    for(sw = 0, i = 1; i <= n-1; i++) {
        if (m[i][cw-sw] > m[i+1][cw-sw]) {
            sw += w[i];
            printf("%3d, ", w[i]);
        }
    }
    if (cw - sw == w[n]) {
        printf("%3d", w[n]);
    }
}

/**
 *
 * 0-1背包问题：背包容纳c重量, n个物品 重量w[i], 价值p[i]
 * 动态规划设计：同装载问题
 *    m(i,j)还可载重j, 还可取集中箱编号i,i+1,...,n时最大价值
 *    m(i,j) = w[i] <= j && m(i+1, j-w[i])+p[i] > m(i+1, j) ? m(i+1, j-w[i])+p[i] : m(i+1, j)
 *    初始值：
 *    m(n,j) = w[n] > j ? 0 : p[n];
 */
void knapsack() {
    int i,j,sw;
    int c = 60;
    int n = 6;
    int w[] = {0, 15, 17, 20, 12, 9, 14};
    int p[] = {0, 32, 37, 46, 26, 21, 30};
    int m[N][N]; // N >= max(w[i])

    for(j = 0; j < w[n]; j++)m[n][j] = 0;
    for(j = w[n]; j <= c; j++)m[n][j] = p[n];

    //cw = 0;
    for(i = n - 1;  i >= 1; i--)
        for(j = 0; j <= c; j++) {
            if (w[i] <= j && m[i+1][j-w[i]] + p[i] > m[i+1][j]) {
                m[i][j] = m[i+1][j-w[i]] + p[i];
               // cw += w[i];
            } else {
                m[i][j] = m[i+1][j];
            }
        }

    // output: 134
    printf("maxp=%d", m[1][c]);

    // 2,3,5,6
    printf("\nC1: ");
    for(sw = 0, i = 1; i <= n-1; i++) {
        if (m[i][c-sw] > m[i+1][c-sw]) {
            sw += w[i];
            printf("%3d", i);
        }
    }
    if (c - sw == w[n]) {
        printf("%3d", n);
    }
}

/**
 *
 * 二维约束条件0-1背包问题：背包容纳c重量、d容积, n个物品 重量w[i], 体积v[i], 价值p[i]
 * 动态规划设计：
 *    m(i,j,k) = w[i] <= j && v[i] <= d && m(i+1, j-w[i], k-v[i]) + p[i] > m(i+1, j, k) ?
 *    m(i+1, j-w[i], k-v[i]) + p[i] : m(i+1, j, k)
 *
 *    初始值：
 *    m(n, j, k) = w[n] > j || v[n] > k ? 0 : p[n]
 */
void knapsackv() {
    int i, j, k;
    int w[] = {0, 8, 6, 11, 13, 5, 15, 12, 9};
    int v[] = {0, 14, 10, 19, 22, 9, 25, 20 ,15};
    int p[] = {0, 20, 14, 28, 31, 12, 37, 27, 22};
    int m[N][5*N][8*N];

    int c = 40, d = 70, n = 8;

    for(j = 0; j <= c; j++)
        for(k = 0; k <= d; k++) {
            if (w[n] <= j && v[n] <= k) {
                m[n][j][k] = p[n];
            } else m[n][j][k] = 0;
        }

    for(i = n-1; i >= 1; i--)
        for(j = 0; j <= c; j++)
             for(k = 0; k <= d; k++) {
                  if (w[i] <= j && v[i] <= k && m[i+1][j-w[i]][k-v[i]] + p[i] > m[i+1][j][k]) {
                      m[i][j][k] = m[i+1][j-w[i]][k-v[i]] + p[i];
                  } else {
                      m[i][j][k] = m[i+1][j][k];
                  }
             }

    // 99
    printf("%d\n", m[1][c][d]);

    int sp = 0, sw = 0, vw = 0;
    for(i = 1; i <= n-1; i++) {
        if (m[i][c-sw][d-vw] > m[i+1][c - sw][d - vw]) {
            sw+=w[i];
            vw+=v[i];
            sp+=p[i];
            printf("%d,", i);
        }
    }
    if (m[1][c][d] - sp == p[n]) {
        sw+=w[n];
        vw+=v[n];
        sp+=p[n];
        printf("%d", n);
    }
    printf("\nmaxw: %d, maxv: %d, maxp: %d", sw, vw, sp);
}

int main() {
    knapsackv();
    return 0;
}