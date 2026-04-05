#include <stdio.h>
#include <string.h>

//筛选以 'a' 开头的字符串

typedef int (*Callback)(const char*);

void filterStr(const char *str[], int len, Callback cb)
{
	for(int i = 0; i < len ;i++)
	{
		if(cb(str[i]))
		{
			puts(str[i]);
		}
	}
}

int isA(const char* str)
{
	return str[0] == 'a' ? 1 : 0;
}

int main() 
{
    const char* s[] = {"hi", "apperence", "ok", "apple"};
    filterStr(s,4, isA);
    return 0;
}
