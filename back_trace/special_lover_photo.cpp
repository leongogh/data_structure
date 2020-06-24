/**
 *  情侣排队问题, 条件：情侣男左女右、不相邻、第i对情侣之间有i个人,队列左端情侣编号小于右端
 *  回溯设计
 *  情侣编号: 1,n+1,2,n+2,i,i+n
 *  a[i] = j,a[i+n] = j+i+1
 *  b[j] = i, b[j+i+1] = i+n;
 */
#include<cstdio>

void lover_photo_1(int n) {
    int i, j, g, s, a[30];

    // 1. 元素初值
    s = 0, i = 1;
    a[i] = 1;
    while (1) {
        // 2. 约束条件1
        for (g = 1, j = 1; j < i; j++) {
            // a[i] = k, k表示第k对情侣 a[j]%n == a[i]%n 表示a[i]、a[j]是一对情侣
            // a[j]>a[i](j < i) 男左女右判断；  a[j]=k表示第k对情侣, 之间有k+2个人
            if (a[i] == a[j] || a[j] % n == a[i] % n && (a[j] > a[i] || a[j] + 2 != i - j)) {
                g = 0;
                break;
            }
        }

        if (g && i == 2 * n && a[1] % n < a[2 * n] % n) {
            printf("%d: ", ++s);
            for (j = 1; j <= 2 * n; j++) {
                printf("%d", a[j] % n + 1);
            }
            printf("\n");
        }

        // 情侣编号0~n-1对  3.取值点
        if (g && i < 2 * n) {
            a[++i] = 0;
            continue;
        }
        // 4. 回溯点
        while (a[i] == 2 * n - 1 && i > 0)i--;

        if (i > 0)a[i]++;
        else break;
    }
}

void lover_photo_2(int n) {
    int i, j, g, m, t, s, a[200], b[200];

    m = 2 * n;
    for (j = 0; j <= m; j++)a[j] = b[j] = 0;
    t = 1;
    s = 0;
    i = 1;
    a[1] = 1;
    a[n + 1] = 3;
    b[1] = b[3] = 1;
    while (i > 0) {
        if (t == 1) {
            i++;
            for (g = 0, j = 1; j <= m - i - 1; j++) {
                if (b[j] == 0 && b[i + j + 1] == 0) {
                    a[i] = j;
                    a[n + i] = j + i + 1;
                    b[j] = b[j + i + 1] = i;
                    g = 1;
                    break;
                }
            }
            if (g == 0) {
                t = 0;
                i--;
            }
        }

        if (1 == t && n == i && b[1] < b[m]) {
            printf("%d: ", ++s);
            for (j = 1; j <= m; j++)printf("%d", b[j]);
            printf("\n");
            b[a[n]] = b[a[m]] = 0;
            t = 0;
            i--;
        }

        if (t == 0) {
            b[a[i]] = b[a[i] + i + 1] = 0;
            for (g = 0, j = a[i] + 1; j <= m - i - 1; j++) {
                if (b[j] == 0 && b[j + i + 1] == 0) {
                    a[i] = j;
                    a[n + i] = j + i + 1;
                    b[j] = b[i + j + 1] = i;
                    g = 1;
                    t = 1;
                    break;
                }
            }
            if (g == 0) {
                i--;
            }
        }
    }
}

int main() {
    // 8: 150
    lover_photo_2(8);
    return 0;
}