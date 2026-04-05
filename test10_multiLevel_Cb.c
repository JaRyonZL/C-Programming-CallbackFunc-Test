// 筛选 >3 的数，输出立方。

#include <stdio.h>

// 回调
typedef int (*Condition_Callback)(int);
typedef void (*Proc_Callback)(int, void*);

// 结果数据结构体
typedef struct
{
	int data[10];
	int data_len;
}ResContext; 

// 处理
void Process(int arr[], int len, Condition_Callback EvtCb, Proc_Callback ProcCb, void* ctx)
{
	for(int i = 0; i < len; i++)
	{
		if(EvtCb(arr[i]))
		{
			ProcCb(arr[i], ctx);
		}
	}
} 

int isGreater3(int num)
{
	return num > 3;
}

void Cube(int num, void *ctx)
{
	ResContext *res_cxt = (ResContext *)ctx;
	
	res_cxt->data[res_cxt->data_len] = num * num * num;
	res_cxt->data_len++;
}

int main()
{
	int arr[]={1,2,3,4,5,6};
	ResContext cxt = {0};
	
	Process(arr, sizeof(arr)/sizeof(arr[0]), isGreater3, Cube, &cxt);
		
	printf("大于3的数有 %d 个\n", cxt.data_len);
	printf("它们的立方数分别为: ");
	for(int i = 0; i < cxt.data_len; i++)
	{
		printf("%d ", cxt.data[i]);
	}
	printf("\n");
	
	return 0;
} 

 
