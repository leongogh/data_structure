#include<cstdio>
#include<cstring>

/**
 * 乘号插入问题
 * f[i][k] = max(f[j][k-1]*a[j][i])  k<=j<i
 *
 * input: 847313926
 * output: 8*4*731*3*92*6=38737152
 */
void insert_multiplication()
{
    char sr[] = "847313926";
    double f[15][15], d;
    int i, j, n, k, u, r, b[15], t[15], c[15][15];

    n = (int)strlen(sr);
    r = 5;

    for(j = 0; j <= n-1; j++)
        b[j] = sr[j] - 48;
    // 边界值
    for(d=0, j = 1; j <= n; j++)
    {
        d = d * 10 + b[j-1];
        f[j][0] = d;
    }

    // 递推公式：f[i][k] = max(f[j][k-1]*a(j+1, i))
    for(k = 1; k <= r; k++)        // k=1,...,r
        for(i = k+1; i <= n; i++)  // i=k+1,...,n
            for(j = k; j < i; j++) // j=k,...i-1
            {
                for(d=0, u=j+1; u <= i; u++)
                    d = d * 10 + b[u-1];

                if (f[i][k] < f[j][k-1] * d)
                {
                    f[i][k] = f[j][k-1] * d;
                    c[i][k] = j;
                }
            }

    t[r] = c[n][r]; // f[n][r]最大时，第r个乘号位置是第j个数字位置后面
    for(k=r-1; k>=1; k--)
        t[k] = c[t[k+1]][k]; // 1~j(t[r])=> f[j][r-1]最大时第r-1个乘号位置
    t[0] = 0; t[r+1] = n;

    for(j=1; j <= r+1; j++) // 0~1个乘号之间为第一个数字，r到r+1乘号之间是最后一个数字
    {
        for(u = t[j-1]+1; u <= t[j]; u++)
            printf("%c", sr[u-1]);

        if (j < r+1) printf("*");
    }

    printf("=%.0f", f[n][r]);
}

int main() {
    insert_multiplication();
    return 0;
}