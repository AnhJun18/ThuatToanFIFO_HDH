#pragma once
#ifndef CL_DEF
#define CL_DEF

#include "winbgim.h"
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))

enum mauChinh
{
	MAU_BG			= COLOR(34,33,73),
	MAU_KHUNG		= COLOR(235, 243, 255)
};

#endif
