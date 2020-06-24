#include<cstdio>

void move(char a, char c) {
    printf("%c --> %c \n", a, c);
}

void fib(int n, char a, char b, char c)
{
    if (n == 1) {
        move(a, c);
        return;
    }
    fib(n-1, a, c, b);
    move(a, c);
    fib(n-1, b, a, c);
}

int main()
{
    fib(3, 'A', 'B', 'C');
    return  0;
}