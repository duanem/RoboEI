#include <PA_BgStruct.h>

extern const char BGHybrid_Tiles[];
extern const char BGHybrid_Map[];
extern const char BGHybrid_Pal[];

const PA_BgStruct BGHybrid = {
	PA_BgNormal,
	256, 192,

	BGHybrid_Tiles,
	BGHybrid_Map,
	{BGHybrid_Pal},

	8192,
	{1536}
};
