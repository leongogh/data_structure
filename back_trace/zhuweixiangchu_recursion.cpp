/**
 *  逐位整除问题：定义前高i位能被i整除, 输出n位逐位整除数
 *  回溯设计：
 *      a[1]: 存最高位数字; a[2]: 存次高位数字
 *      判断已取的i位数是否能被i整除
 *
 */
#include<cstdio>

int main() {
    int m = 0, i,j,d,t,n, a[100];

    n = 24;
    t = 0; i = 1; a[1] = 1;
    while(a[1] <= 9) {
        if (0 == t && i < n) {
            a[++i] = 0;
        }

        for (d = 0, j = 1; j <= i; j++) {
            d = d * 10 + a[j]; d = d % i; // 这样做目的防止d过大, 超过int范围
        }

        if (d == 0) {
            t = 0;
            if (i == n) {
                printf("%d: ", ++m);
                for(j = 1; j <= n; j++)
                    printf("%d", a[j]);
                printf("\n");
                a[i]++;
            }
        } else {
            t = 1;
            a[i]++;
            while(a[i] > 9 && i > 1) {
                a[--i]++;
            }
        }
    }
    return  0;
}