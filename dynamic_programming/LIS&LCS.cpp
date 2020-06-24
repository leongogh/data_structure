/**
 *  动态规划 最大非降子序列&最长公共子序列
 */
#include<cstdio>
#include<cstring>

#define N 50

void Lis() {
    int i,j,n,lmax,max,x;
    int a[15] = {0,45,39,10,27,34,63,62,35,47,16,52,13,0,0};
    int b[15] = {0};

    n = 12;
    lmax = 0;
    b[n] = 1;

    for(i = n-1; i>=1; i--) {
        max = 0;
        for(j = i+1; j <=n; j++) {
            if (a[i] <= a[j] && b[j] > max) {
                max = b[j];
            }
        }
        b[i] = max+1;
        lmax = b[i] > lmax ? b[i] : lmax;
    }

    x = lmax;
    for(i = 1 ; i <= n; i++) {
        if (b[i] == x) {
            printf("%3d", a[i]);
            x--;
        }
    }
}

void Lcs() {
    int i,j,m,n,w,t,max,lmax,c[N][N],s[N][N];
    char *x = "sbafdreghsbacdba";
    char *y = "acdbegshbdrabsa";
    m = strlen(x);
    n = strlen(y);

    for(i=0; i<=m; i++)c[i][n]=0;
    for(i=0; i<=n; i++)c[m][i]=0;

    for(i=m-1;i>=0;i--) {
        for(j=n-1; j>=0; j--) {
            if(x[i] == y[j]) {
                c[i][j] = c[i+1][j+1] + 1;
                s[i][j] = 1;
            } else {
                c[i][j] = c[i+1][j] > c[i][j+1] ? c[i+1][j] : c[i][j+1];
                s[i][j] = 0;
            }
        }
    }

    printf("length: %d\n", c[0][0]);
    for(w=0,t=0,i=0; i<=m; i++) {
        for(j=t; j <=n; j++) {
            if(c[i][j] == c[0][0]-w && s[i][j] == 1) {
                printf("%c", x[i]);
                w++;
                t=j+1;
            }
        }
    }
}

int main() {
    Lcs();
    return 0;
}