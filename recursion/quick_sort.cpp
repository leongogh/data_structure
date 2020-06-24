/**
 * 快速排序+第k小问题
 */

#include<cstdio>

int arr[] = {0, 1, 12, 4, 3, 9, 7, 11, 8, 10, 5};

void qk(int m1, int m2) {
    int i,j;
    if (m1 >= m2) return;
    i = m1; j = m2;

    arr[0] = arr[i];
    while(i != j) {
        while(i < j && arr[0] <= arr[j])j--;
        if (i < j)arr[i++] = arr[j];
        while(i < j && arr[i] <= arr[0])i++;
        if (i < j)arr[j--] = arr[i];
    }
    arr[i] = arr[0];

    qk(m1, i-1);
    qk(i+1, m2);
}

// 第n小元素
int smk(int k, int m1, int m2) {
    int i, j;
    if (m1 > m2) return -1;
    i = m1; j = m2;

    arr[0] = arr[i];
    while(i != j) {
        while(i < j && arr[0] <= arr[j])j--;
        if(i < j) arr[i++] = arr[j];
        while(i < j && arr[i] <= arr[0])i++;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = arr[0];

    if (i == k) {
        return  arr[i];
    } else if(i > k) {
        return  smk(k, m1, i-1);
    } else {
        return smk(k, i+1, m2);
    }
}

int main() {
    int i;
    qk(1, 10);
    for(i = 1; i <= 10; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");

    printf("min n: %d \n", smk(5, 1, 10));
    return  0;
}