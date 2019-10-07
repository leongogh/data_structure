/**
 * 古尺问题：36寸, 刻度8条, 仍能测试1~36
 * 回溯设计：
 *    长度s, 刻度数m
 *    初值: a[0]=0,a[1]=1,a[n+1]=s,a[2]=2
 *    a[i]:表示第i条刻度到左端长度, a[i] ~ {a[i-1], ..., s-1-(n-i)}
 *    b[t]:存放a[i],a[j]之差
 *    约束条件: a[1~m]赋值后, 检查b[t]是否包括1~s
 *
 */
#include<cstdio>

int main() {
    int d, i, j, k, t ,u ,s, n, a[30], b[300], num = 0;

    s=36; n=8;
    a[0] = 0; a[1] = 1; a[n+1] = s;
    i = 2; a[i] = 2;
    while(1) {
        if (i < n) {
            i++;
            a[i] = a[i-1] + 1;
            continue;
        } else {
            for(t = 0, k = 0; k <= n; k++)
                for(j = k+1; j <= n+1; j++)
                {
                    b[++t] = a[j] - a[k];
                }

            for(u = 0, d = 1; d <= s; d++)
                for(k = 1; k <= t; k++)
                    if (d == b[k]) {
                        u++;
                        break;
                    }
            if (u == s) {
                num++;
                printf("%d: ", num);
                for(k = 1; k <= n+1; k++) {
                    printf("%3d", a[k]);
                }
                printf("\n");
            }
        }

        while(a[i] == s - 1 - (n - i) && i > 1)i--; // 回溯点
        if (i > 1)a[i]++;
        else break;
    }

    return  0;
}