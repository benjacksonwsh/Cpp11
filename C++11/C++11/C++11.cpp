// C++11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdint.h>
#include <Windows.h>
#include <tchar.h>
#include <type_traits>
#include <string>

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
	
	color.value = strtoul(agrb, NULL, 0);
	return color;
}

Color operator"" _argb(const char* argb, std::size_t size) {
	Color color;
	char* endPtr = nullptr;
	
	std::string strColor(argb,size);
	
	int signPos = strColor.find('#');
	if (signPos >= 0)
	{
		strColor.replace(signPos, 1, "0x");
	}

	color.value = strtoul(strColor.c_str(), NULL, 0);
	return color;
}
__pragma(pack(pop))

void draw(const Color&  color)
{
	printf("r:%02x g:%02x b:%02x a:%02x", color.RGBA.r, color.RGBA.g, color.RGBA.b, color.RGBA.alpha);
}


int _tmain(int argc, _TCHAR* argv[])
{
	Color color = 0xFFEEBBDD_argb;
	printf("r:%02x g:%02x b:%02x a:%02x\n", color.RGBA.r, color.RGBA.g, color.RGBA.b, color.RGBA.alpha);

	color = "#FEBBDDAA"_argb;
	printf("r:%02x g:%02x b:%02x a:%02x", color.RGBA.r, color.RGBA.g, color.RGBA.b, color.RGBA.alpha);

	draw(0xFFEEBBDD_argb);

	getchar();
	return 0;
}
