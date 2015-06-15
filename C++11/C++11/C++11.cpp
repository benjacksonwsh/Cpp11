// C++11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdint.h>
#include <Windows.h>
#include <tchar.h>
#include <memory>

class A
{
public:
	A()
	{

	}

	~A()
	{
		printf("A deconstructor");
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	std::shared_ptr<int> sharePtr(new int{0});//increase ptr use count
	std::unique_ptr<int> uniquePtr(new int{ 0 });
	std::weak_ptr<int> weakPtr = sharePtr;//increase weak usecount
	std::weak_ptr<int> weakPtr1 = weakPtr;

	std::weak_ptr<A> weak;
	{
		std::shared_ptr<A> shareA( new A );
		weak = shareA;
	}//A deconstructor

	if (weak.lock()) 
	{
		printf("expire\n");
	}

	printf("%d",*(weakPtr1.lock()));
	getchar();
	return 0;
}
