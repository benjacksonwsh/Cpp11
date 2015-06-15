// C++11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdint.h>
#include <Windows.h>

constexpr int Fibonacci(uint32_t n) {
	return 0==n ? 0 : (n<3) ? 1 : (Fibonacci(n-1)+Fibonacci(n-2));
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint32_t fib[] = {
		Fibonacci(11ul),Fibonacci(12ul),
		Fibonacci(13ul),Fibonacci(14ul),
		Fibonacci(15ul),Fibonacci(16ul),
		Fibonacci(17ul),Fibonacci(18ul), 
	};

	for (uint32_t i : fib) {
		printf("%d\n", i);
	}

	char buff[Fibonacci(20)] = { 0 };
	getchar();
	return 0;
}
