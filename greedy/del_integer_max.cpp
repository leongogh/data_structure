#include<cstdio>

/**
 * 删除k个数字使剩下数字组成的数最大
 *
 * input: 762191754639820463; k=6
 * output: 975639820463
 */
void del_integer_max()
{
    int i, k, n, del, pre;
    char b[]="762191754639820463";
    int a[50];
    k = 6;

    for(n = 0, i = 0; b[i] != '\0'; i++) {
        n++;
        a[i] = b[i] - 48;
    }

    printf("删除%d个数字：", k);
    del = 0; pre = 0; i = 1;
    while(k > del && i <= n)
    {
        if (pre >= 0 && a[pre] < a[i])
        {
            printf("%d", a[pre]);
            a[pre] = -1;
            while(pre >= 0 && a[pre] == -1) pre--;
            del++;
        }
        else
        {
            pre = i++;
        }
    }

    printf("\n删除后所得最大数：");
    for(i = 0; i < n; i++)
    {
        if (a[i] != -1)
            printf("%d", a[i]);
    }
}

int main() {
    del_integer_max();
    return 0;
}