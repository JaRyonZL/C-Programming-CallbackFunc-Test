#include <stdio.h>
#include <string.h>

typedef int (*Cmp)(const void*, const void*);

int intAsc(const void* a, const void* b);
int intDesc(const void* a, const void* b); 

void mySort(void* base, int n, int size, Cmp cmp) 
{
    char * arr = (char *)base;
	for(int i = 0; i < n - 1;i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(cmp(arr+j*size, arr+(j+1)*size) > 0)
			{
				// ½»»»
				char tmp[size];
				memcpy(tmp, arr+j*size, size);
				memcpy(arr+j*size, arr+(j+1)*size, size);
				memcpy(arr+(j+1)*size, tmp, size);
			}
		}
	} 
}

int main() 
{
    int a[] = {3,1,4,2};
    
    printf("ÉýÐòÅÅÁÐ: \n");
	mySort(a,sizeof(a)/sizeof(a[0]), sizeof(int), intAsc);
    for(int i=0; i<4; i++) printf("%d ",a[i]);
    printf("\n");
    
    printf("½µÐòÅÅÁÐ: \n");
    mySort(a,sizeof(a)/sizeof(a[0]), sizeof(int), intDesc);
	for(int i=0; i<4; i++) printf("%d ",a[i]);
	printf("\n");
    
    return 0;
}

// ÕûÐÍÉýÐò 
int intAsc(const void* a, const void* b)
{
	// >0 ÉýÐò <0 ½µÐò
	return *(int *)a - *(int *)b; 
}

// ÕûÐÍ½µÐò
int intDesc(const void* a, const void* b)
{
	// >0 ÉýÐò <0 ½µÐò
	return *(int *)b - *(int *)a; 
}
