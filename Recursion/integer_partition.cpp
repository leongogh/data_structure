/**
 *
 * 拆分零数取自连续区间：指定整数ss,拆分连续1~ms之和, 拆分零数个数为m. 组合思想
 * 拆分零数取自指定整数：指定整数ss,拆分b[1~ms]之和, 拆分零数个数为m. 组合思想
 */

#include<cstdio>

int ss = 20, ms = 8, m, s, a[20];
void partition(int k) {
    int i, j, t;

    if (k <= m) {
        a[0] = 0;
        for(i = a[k-1] + 1; i <= ms - (m - k - 1) - 1; i++) {
            a[k] = i;

            if (k == m) {
                 for(t =0, j = 1; j <= k; j++) {
                    t = t + a[j];
                 }
                if (t == ss) {
                    s++;
                    for(j = 1; j <= k; j++) {
                        printf("%3d", a[j]);
                    }
                    printf("\n");
                }
            } else partition(k+1);
        }
    }
}

int ss1 = 15, ms1 = 5, b[20] = {0,1,3,4,7,8};
void partition_n(int k) {
    int i, j, t;

    if (k <= m) {
        a[0] = 0;

        for (i = a[k-1] + 1; i <= ms1 + m - k; i++) {
            a[k] = i;

            if (k == m) {
                for(t = 0, j = 1; j <= k; j++) {
                    t = t + b[a[j]];
                }
                if (t == ss1) {
                    s++;
                    for(j = 1; j <= k; j++) {
                        printf("%3d", b[a[j]]);
                    }
                    printf("\n");
                }
            } else partition_n(k+1);
        }
    }
}

void partition_test() {
    int i, h, wmin = 0, wmax = 0;
    for(h = 0, i = 1; i <= ms; i++) {
        h = h + i;
        if (h > ss) {
            wmax = i - 1;
            break;
        }
    }

    for(h = 0, i = ms; i >= 1; i--) {
        h = h + i;
        if (h > ss) {
            wmin = ms - i;
            break;
        }
    }

    for(m = wmin; m <= wmax; m++) {
        partition(1);
    }
    printf("wmin=%d, wmax=%d, sum=%d", wmin, wmax, s);
}

int main() {
    int i, h, wmin = 0, wmax = 0;
    for(h = 0, i = 1; i <= ms1; i++) {
        h = h + b[i];
        if (h > ss1) {
            wmax = i - 1;
            break;
        }
    }
    for(h = 0, i = ms1; i >= 1; i--) {
        h = h + b[i];
        if (h > ss1) {
            wmin = ms1 - i;
            break;
        }
    }

    for(m = wmin; m <= wmax; m++) {
        partition_n(1);
    }

    printf("wmin=%d, wmax=%d, sum=%d", wmin, wmax, s);
    return  0;
}