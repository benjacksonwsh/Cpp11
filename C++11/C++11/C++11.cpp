// C++11.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdint.h>
#include <Windows.h>
#include <string>

enum Color_C{
	RED,
	GREEN,
	BLUE,
};

enum class Color:char{
	RED,
	GREEN,
	BLUE,
};

int _tmain(int argc, _TCHAR* argv[])
{
	printf("sizeof enum color:char:%d\n", sizeof(Color));
	printf("sizeof enum color_c:%d\n", sizeof(Color_C));
	getchar();
	return 0;
}
