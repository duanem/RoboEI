#include <PA_BgStruct.h>

extern const char BGEnd_Tiles[];
extern const char BGEnd_Map[];
extern const char BGEnd_Pal[];

const PA_BgStruct BGEnd = {
	PA_BgNormal,
	256, 192,

	BGEnd_Tiles,
	BGEnd_Map,
	{BGEnd_Pal},

	7616,
	{1536}
};
