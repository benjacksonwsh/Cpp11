// C++11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdint.h>
#include <Windows.h>
#include <type_traits>
#include <string>
#include <functional>
using std::string;
using std::placeholders::_1;

bool check_size(const string & s, string::size_type sz)
{
	return s.size() > sz;
};

auto check6 = std::bind(check_size, _1, 6);

int _tmain(int argc, _TCHAR* argv[])
{
	check6("hello");
	getchar();
	return 0;
}