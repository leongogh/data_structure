/**
 *  逐位整除问题：定义前高i位能被i整除, 输出n位逐位整除数
 *  回溯设计：
 *      a[1]: 存最高位数字; a[2]: 存次高位数字
 *      判断已取的i位数是否能被i整除
 *
 */
#include<cstdio>

int main() {
    // a[1000][1000] -> a[1200][1200]内存溢出
    int m = 0, i,j,k,d,n,r, g, a[3000][30], b[3000][30];

    n = 24;

    g = 9;
    for(i = 1; i <= g; i++) {
        a[i][1] = i;
    }

    for(k = 2; k <= n; k++) {
        m = 0;
        for(i = 1; i <= g; i++) {
            // 循环变量使用 i,j默认随处可用, 用完即释放
            for(j = 0; j <= 9; j++) {
                a[i][k] = j;

                for(r = 0, d = 1; d <= k; d++) {
                    r = r * 10 + a[i][d]; r = r % k;
                }

                if (r == 0) {
                    m++;
                    for(d = 1; d <= k; d++) {
                        b[m][d] = a[i][d];
                    }
                }
            }
        }

        g = m;
        for(i = 1; i <= g; i++)
            for(d = 1; d <= k; d++)
                a[i][d] = b[i][d];
    }

    if (g > 0) {
        for(i = 1; i <= g; i++) {
            printf("\n%d: ", i);
            for(j = 1; j <= n; j++) {
                printf("%d", a[i][j]);
            }
        }
    } else {
        printf("无解！");
    }

    return  0;
}