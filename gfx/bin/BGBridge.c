#include <PA_BgStruct.h>

extern const char BGBridge_Tiles[];
extern const char BGBridge_Map[];
extern const char BGBridge_Pal[];

const PA_BgStruct BGBridge = {
	PA_BgNormal,
	256, 192,

	BGBridge_Tiles,
	BGBridge_Map,
	{BGBridge_Pal},

	7232,
	{1536}
};
