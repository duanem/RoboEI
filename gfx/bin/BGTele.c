#include <PA_BgStruct.h>

extern const char BGTele_Tiles[];
extern const char BGTele_Map[];
extern const char BGTele_Pal[];

const PA_BgStruct BGTele = {
	PA_BgNormal,
	256, 192,

	BGTele_Tiles,
	BGTele_Map,
	{BGTele_Pal},

	9472,
	{1536}
};
