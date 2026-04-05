/*
 * @Descripttion: 筛选 >5 的数
 * @Author: JaRyon
 * @version: 
 * @Date: 2026-04-05 11:29:05
 */
#include "stdio.h"

typedef int (*Callback)(int);

int isGreater5(int num)
{
    return (num > 5) ? 1 : 0;
}

void process(int arr[], int len, Callback cb)
{
    for (int i = 0; i < len; i++)
    {
        if (cb(arr[i]))
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    process(arr, 9, isGreater5);

    return 0;
}
