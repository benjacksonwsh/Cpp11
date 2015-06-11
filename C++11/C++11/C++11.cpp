// C++11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdint.h>
#include <Windows.h>
#include <type_traits>

__pragma(pack(push, 4))
union Color
{
	struct {
		uint8_t b;
		uint8_t g;
		uint8_t r;
		uint8_t alpha;
	}RGBA;
	uint32_t value;
};

Color operator"" _argb(const char* agrb) {
	Color color;
	char* endPtr = nullptr;
	color.value = strtol(agrb, NULL, 0);
	return color;
}

Color operator"" _argb(const char* agrb, std::size_t size) {
	Color color;
	char* endPtr = nullptr;
	color.value = strtol(agrb, NULL, 0);
	return color;
}
__pragma(pack(pop))



int _tmain(int argc, _TCHAR* argv[])
{
	Color color = std::move("0x12345678"_argb);

	printf("r:%02x g:%02x b:%02x a:%02x", color.RGBA.r, color.RGBA.g, color.RGBA.b, color.RGBA.alpha);
	getchar();
	return 0;
}
