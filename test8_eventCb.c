#include <stdio.h>

typedef void (*Event_Callback)(void);

// 定义按键结构体
typedef struct
{
	char button_name[15];
	Event_Callback onClick;
	
}Button; 

void onClick_A(void)
{
	printf("Button-A is Clicked\n");
}

void onClick_B(void)
{
	printf("Button-B is Clicked\n");
}

void onClick_C(void)
{
	printf("Button-C is Pressed\n");
}

int main() {
    Button btnA = {"A", onClick_A};
    Button btnB = {"B", onClick_B};
    Button btnC = {"C", onClick_C};

    // 模拟点击
    btnA.onClick();
    btnB.onClick();
    // 模拟按下 
    btnC.onClick(); 
    
    return 0;
}
