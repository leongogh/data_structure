/**
 *  动态规划 点数值三角形 & 边数组三角形
 */
#include<cstdio>
#include<cstring>

void dot_triangle() {
    int i,j,n = 7,m = 7;
    int a[8][8] = {{0},
                   {0,22},
                   {0,14,19},
                   {0,30,25,10},
                   {0,8,20,12,27},
                   {0,6,25,32,6,4},
                   {0,6,10,10,6,2,32},
                   {0,32,29,2,13,15,3,24}};
    int b[10][10];
    char stm[10][10];

    for(j=1; j<=m; j++) b[n][j] = a[n][j];
    for(i = n-1; i>= 1; i--) {
        for(j = 1; j <=i; j++) {
            if (b[i+1][j+1] < b[i+1][j]) {
                b[i][j] = a[i][j] + b[i+1][j+1]; stm[i][j] = 'R';
            } else {
                b[i][j] = a[i][j] + b[i+1][j]; stm[i][j] = 'L';
            }
        }
    }

    printf("点数值三角形为：\n");
    for(i = 1;i < 8;i++) {
        for(j = 1; j <= i; j++) {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    printf("最小路径和：%d\n", b[1][1]);
    printf("最小路径为：%d", a[1][1]);
    j=1;
    for(i=2; i<=n; i++) {
        if (stm[i-1][j] =='R') {
            printf("-R-%d", a[i][j+1]); j++;
        } else {
            printf("-L-%d", a[i][j]);
        }
    }
}

void edge_triangle() {
    int r[][6] = {
            {0},
            {0, 10, 12, 39, 13, 28},
            {0, 42, 27, 25, 19, 17},
            {0, 34, 39, 24, 35, 10},
            {0, 21, 22, 37, 30, 30},
            {0, 10, 41, 35, 36, 27},
    };
    int d[][7] = {
            {0},
            {0, 30, 16, 39, 32, 19, 34},
            {0, 16, 31, 21, 40, 22, 22},
            {0, 20, 41, 25, 32, 31, 42},
            {0, 26, 40, 27, 35, 34, 18}
    };

    int i, j, n = 5, m = 6;
    int a[10][10];
    char st[10][10];

    for(i = n-1; i >= 1; i--) {
        a[i][m] = a[i+1][m] + d[i][m]; st[i][m] = 'd';
    }
    for (j = m - 1; j >= 1; j--) {
        a[n][j] = a[n][j+1] + r[n][j]; st[n][j] = 'r';
    }

    for(i = n - 1; i >= 1; i--) {
        for(j = m - 1; j >= 1; j--) {
            if (a[i+1][j] + d[i][j] > a[i][j+1] + r[i][j]) {
                a[i][j] = a[i+1][j] + d[i][j];
                st[i][j] = 'd';
            } else {
                a[i][j] = a[i][j+1] + r[i][j];
                st[i][j] = 'r';
            }
        }
    }

    printf("最多路径和：%d", a[1][1]);
    printf("\n最多路径为：(1,1)");
    j=1;i=1;
    while (i < n || j < m) {
        if(st[i][j] == 'd') {
            printf("-%d-", d[i][j]);
            i++;
            printf("(%d,%d)", i, j);
        } else {
            printf("-%d-", r[i][j]);
            j++;
            printf("(%d,%d)", i, j);
        }
    }
}

int main() {
    edge_triangle();
    return 0;
}