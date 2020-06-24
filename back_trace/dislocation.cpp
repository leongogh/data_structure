/**
 * n个信封对应n个信封,全部错位情形 递推+递归
 *
 */
#include<cstdio>

void all_dislocation() {
    int i,j,t,s,n,h, a[30];

    n = 5; s = 0;
    i = 1; a[i] = 2;
    while(1) {
        t = 1;
        if (a[i] != i) {
            for(j = 1; j < i; j++) {
                if (a[j] == a[i]) {
                    t = 0;
                    break;
                }
            }
        } else t = 0;

        if (t && i == n) {
            printf("%d: ", ++s);
            for(j = 1; j <= n; j++)
                printf("%d", a[j]);
            printf("\n");
        }

        if (t && i < n) {
            a[++i] = 1; continue;
        }
        while(a[i] == n && i > 0) i--;
        if (i > 0) a[i]++;
        else break;
    }
}

int n = 5;
int a[30];
int s = 0;
void put(int k) {
    int i,j,u;
    if (k <= n) {
        for(i = 1; i <= n; i++) {
            a[k] = i;

            if (a[k] != k) {
                for(u = 0, j = 1; j <= k-1; j++) {
                    if (a[k] == a[j]) {
                        u = 1;
                        break;
                    }
                }
            } else continue;

            if (u == 0) {
                if (k == n) {
                    printf("%d: ", ++s);
                    for(j = 1; j <= n; j++)
                        printf("%d", a[j]);
                    printf("\n");
                } else put(k+1);
            }
        }
    }
}

int main() {
    put(1);
    return  0;
}