/*
 * @Descripttion: 
 * @Author: JaRyon
 * @version: 
 * @Date: 2026-04-05 11:19:20
 */
#include <stdio.h>

typedef void (*Callback)(int);

void print(int num)
{
    printf(" %d", num);
}

void square(int num)
{
    printf(" %d", num * num);
}

void cube(int num)
{
    printf(" %d", num * num * num);
}

// 遍历数组对每一个值进行某操作
void traverse(int arr[], int len, Callback cb)
{
    for (int i = 0; i < len; i++)
    {
        cb(arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    
    traverse(arr, 5, print);
    printf("\n");
    traverse(arr, 5, square);
    printf("\n");
    traverse(arr, 5, cube);

    return 0;
}
