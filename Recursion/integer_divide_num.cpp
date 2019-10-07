/**
 * 划分数问题：设n的最大零数不超过m的划分数为q(n,m)
 * 递归设计：
 *  1）q(n,m) = 1, n = 1 or m =1
 *  2）q(n,m) = 0, n < 1 or m < 1;
 *  3) q(n,m) = q(n, n), n < m
 *  4）q(n,m) = q(n, m-1) + 1, n == m
 *  5) q(n,m) = q(n, m-1) + q(n-m, m), m < n
 *
 *  递推设计:
 *   1) q(n,m) = q(n, m-1) + q(n-m, m) 1 <= m < n <= s
 *   2) q(n-m, m) = q(n - m, n - m), n -m < m
 *   3) q(n, 1) = q(1, m) = 1
 *
 *  n个0与m个1排序问题, a[k]=i(0,1), m+n个,判断0个数
 */

#include<cstdio>

int main() {
    int m, n, s, q[100][100];

    s = 6; // res: 11

    for(m = 1; m <= s; m++) {
        q[m][0] = 0; q[m][1] = 1; q[1][m] = 1;
    }

    for(n = 2; n <= s; n++) {
        for(m = 1; m <= n - 1; m++) {
            if (n - m < m) q[n-m][m] = q[n-m][n-m];
            q[n][m] = q[n][m-1] + q[n-m][m];
        }
        q[n][n] = q[n][n-1] + 1;
    }

    printf("划分数：%d", q[s][s]);
    return  0;
}