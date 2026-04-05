#include <stdio.h>

typedef void (* Callback)(int, void *);

void traverse(int arr[], int len, Callback cb, void * ctx)
{
	for(int i = 0;i < len;i++)
	{
		cb(arr[i], ctx);
	}
}

void maxCb(int num, void *ctx)
{
	int *max = (int *)ctx;
	
	if(*max < num)
	{
		int tmp = *max;
		*max = num;
		num = tmp;
	}
}

int main()
{
	int arr[] = {2,5,8,1,33};
	int ctx = 0; // 记录最大值
	
	traverse(arr, 5, maxCb, &ctx);    
	printf("最大值为 %d\n", ctx);

    return 0;
}
