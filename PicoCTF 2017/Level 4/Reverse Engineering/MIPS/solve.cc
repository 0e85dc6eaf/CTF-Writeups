#include <iostream>
#include <stdint.h>

bool isValidInput(uint32_t a0)
{
	uint32_t a2 = 0xff000000;
	a2 = a2 & a0;
	uint32_t s0 = 0xff0000;
	s0 = s0 & a0;
	uint32_t a3 = a0 & 0xff00;
	a0 = a0 & 255;
	uint32_t v1 = static_cast<int32_t>(a2) >> 24;
	uint32_t v0 = 0;
	v1 = v1 - 169;
	uint32_t a1 = 0;
	v0 = 14;
	v1 = v1 - 6;
	a1 = v1 << 24;
	s0 = static_cast<int32_t>(s0) >> 16;
	v0 = s0 - 81;
	uint32_t t0 = v0 << 6;
	v1 = v0 << 8;
	v1 = v1 - t0;
	v1 = v0 - v1;
	a3 = static_cast<int32_t>(a3) >> 8;
	v0 = a0 << 1;
	v0 = v0 + 3;
	v1 = v1 << 16;
	if(a3==v0)
	{
		v0 = 94;
	}
	else
	{
		v0 = 165;
	}
	v0 = v0 - 94;
	v0 = v0 << 8;
	a2 = a2 >> 24;
	s0 = a2 - s0;
	a0 = a0 - s0;
	v1 = a1 + v1;
	v1 = v0 + v1;
	s0 = a0 + v1;
	if(s0==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	for(int64_t i=0;i<4294967296;i++)//valid value is 2941370206
	{
		if(isValidInput(i))
		{
			std::cout << "0x" << std::hex << i << std::endl;
			break;
		}
	}
	return 0;
}
