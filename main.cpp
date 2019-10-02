#include<cstdio>
/**
 * 排队购票问题：m人手持50元,n人手持100元,排队购票,约定面值相同交换位置为同一种排队
 * 递归公式：f(m,n) = f(m-1,n) + f(m, n-1)
 * 递归出口：m < n, f(m, n) = 0; n = 0, f(m, 0) = 1;
 */

long queue_for_ticket(int m, int n)
{
    if (m < n) return 0;
    if (n == 0) return 1;
    return queue_for_ticket(m-1, n) + queue_for_ticket(m, n-1);
}

int main()
{
    long sum1, sum2;
    sum1 = queue_for_ticket(15,12);
    sum2 = queue_for_ticket(20,10);
    printf("sum: %ld, %ld\n", sum1, sum2);
    return  0;
}