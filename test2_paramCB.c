#include "stdio.h"

// 写回调 square(int x) 输出平方。

void square(int num)
{
    printf("%d 的平方是 %d\n", num, num * num);
}

void process(int num, void (*callback)(int))
{
    callback(num);
}

int main()
{
    process(10, square);
    return 0;
}
