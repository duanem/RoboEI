
#ifndef _game_Model_h
#define _game_Model_h

struct InitData
{
	InitData();
	
	~InitData();
	
	int DSNum;
	int MatchNum;
	int TeamNum;
	bool AllianceColor;
	
};

struct HydData
{
	HydData();
	
	~HydData();
	
	bool HasHybrid;
	bool UsesKINECT;
	bool LowerBridge;
	bool Assist;
	bool Other;
	int TopP;
	int MidP;
	int LowP;
	
};

struct TeleData
{
	TeleData();
	
	~TeleData();
	
	bool Disabled;
	int DisabledCounter;
	bool Bridge;
	bool Bar;
	int BallsPU;
	int TopP;
	int MidP;
	int LowP;

};

struct BrdgData
{
	BrdgData();
	
	~BrdgData();
	
	int BalanceType;
	int BalanceAmount;

};

struct EndData
{
	EndData();
	
	~EndData();
	
	bool Defensive;
	bool Assist;
	int Technical;
	int Regular;
	bool YellowPenalty;
	bool RedPenalty;
	bool Finish;
	
};
	
struct GameData
{
	GameData();
	
	~GameData();
	
	HydData HydInfo;
	TeleData TeleInfo;
	BrdgData BrdgInfo;
	EndData EndInfo;

};

struct MatchData
{
	MatchData();
	
	~MatchData();
	
	InitData InitInfo;
	GameData GameInfo;
	
};

#endif
