#include <stdio.h>
#include <unistd.h>

typedef void (*Timer_Callback)(int);

void setTimeout(int ms, Timer_Callback tim_cb, int id)
{
	sleep(ms / 1000);
	tim_cb(id);
} 

void task(int tim_id)
{
	if(tim_id == 1)
	{
		printf("Task1 run after delay!\n");
	}
	else if(tim_id == 2)
	{
		printf("Task2 run after delay!\n");
	}
}


int main() 
{
    setTimeout(1000, task, 1);
    setTimeout(3000, task, 2);
    
	return 0;
}
