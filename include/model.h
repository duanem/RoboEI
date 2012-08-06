
#ifndef _game_Model_h
#define _game_Model_h

typedef struct
{
	int DSNum;
	int MatchNum;
	int TeamNum;
	bool AllianceColor;
	
} InitData;

typedef struct
{
	bool HasHybrid;
	bool UsesKINECT;
	int ScoreType;
	int TopP;
	int MidP;
	int LowP;
	
} HydData;

typedef struct
{
	bool Disabled;
	bool Bridge;
	bool Bar;
	int BallsPU;
	int TopP;
	int MidP;
	int LowP;

} TeleData;

typedef struct
{
	int BalanceType;
	int BalanceAmount;

} BrdgData;

typedef struct
{
	bool Defensive;
	bool Assist;
	int Technical;
	int Regular;
	bool YellowPenalty;
	bool RedPenalty;
	
} EndData;

typedef struct
{
	HydData HydInfo;
	TeleData TeleInfo;
	BrdgData BrdgInfo;
	EndData EndInfo;
	
} GameData;
	
typedef struct
{
	InitData InitInfo;
	GameData GameInfo;
	
} MatchData;

#endif
