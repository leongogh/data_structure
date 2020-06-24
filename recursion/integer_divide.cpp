/**
 * 整数划分递推关系：
 *  1）和数k-1划分式前加一个零数"1"都是和数k的划分式
 *  2）和数k-1划分式前2个零数比较, 如果第1个零数小于第2个零数, 则第1个零数加1后成为和数k的划分式
 *
 */
#include<cstdio>

static int a[21][800][21];

void divide_integer_1(int s) {
    int i, j, k, u, t;

    // 初始条件
    a[2][1][1] = 1; a[2][1][2] = 1; a[2][2][1] = 2;
    u = 2;

    for(k = 3; k <= s; k++) {
        // 和数k-1划分式前加一个零数"1"都是和数k的划分式
        for(j = 1; j <= u; j++) {
            a[k][j][1] = 1;
            for(t = 2; t <= k; t++) {
                a[k][j][t] = a[k-1][j][t-1];
            }
        }

        // 和数k-1划分式前2个零数比较, 如果第1个零数小于第2个零数, 则第1个零数加1后成为和数k的划分式
        for(i = u, j = 1; j <= u; j++) {
            if (a[k-1][j][1] < a[k-1][j][2]) {
                i++;
                a[k][i][1] = a[k-1][j][1] + 1;

                for(t = 2; t <= k-1; t++) {
                    a[k][i][t] = a[k-1][j][t];
                }
            }
        }

        i++; a[k][i][1] = k; u = i;
    }

    // 打印
    for(j = 1; j <= u; j++) {
        printf("%d: ", j);
        for(i = 1; a[s][j][i] > 0; i++) {
            printf("%-3d", a[s][j][i]);
        }
        printf("\n");
    }
}

static int b[1600][25];

void divide_integer_2(int s) {
    int i, j, k, u, t;

    // 初始条件
    b[1][1] = 1; b[1][2] = 1; b[2][1] = 2;
    u = 2;

    for(k = 3; k <= s; k++) {
        for(j = 1; j <= u; j++) {
            for(i = k-1; i >= 1; i--) {
                b[j][i+1] = b[j][i];
            }
            b[j][1] = 1;
        }

        for(t = u, j = 1; j <= u; j++) {
            if (b[j][2] < b[j][3]) {
                t++;
                b[t][1] = b[j][2] + 1;
                for(i = 3; b[j][i] > 0; i++) {
                    b[t][i-1] = b[j][i];
                }
            }
        }
        t++; b[t][1] = k; u = t;
    }

    // 打印
    for(j = 1; j <= u; j++) {
        printf("%d: ", j);
        for(i = 1; b[j][i] > 0; i++) {
            printf("%-3d", b[j][i]);
        }
        printf("\n");
    }
}

int main() {
    // input->output: 12->77, 20->627
    divide_integer_2(12);
    return  0;
}