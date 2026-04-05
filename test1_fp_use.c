#include "stdio.h"

// 打印GoodBye!
void bye(void)
{
    printf("GoodBye!\n");
}

void run(void (*func)())
{
    func();
}

int main()
{
    run(bye);
    
    return 0;
}
