#include <PA_BgStruct.h>

extern const char BGBlank_Tiles[];
extern const char BGBlank_Map[];
extern const char BGBlank_Pal[];

const PA_BgStruct BGBlank = {
	PA_BgNormal,
	256, 192,

	BGBlank_Tiles,
	BGBlank_Map,
	{BGBlank_Pal},

	64,
	{1536}
};
