
#include <PA9.h>
#include "main.h"
#include "model.h"

extern struct MATCH MatchList[kMaxMatches];
extern int maxMatches;

InitData::InitData()
: DSNum(readDS())
, MatchNum(readMatch())
, AllianceColor(0)
{
	Loadmatches();
	if(MatchNum > maxMatches)
		MatchNum = 1;
	TeamNum = MatchList[MatchNum-1].RobotNo[DSNum-1];
}

InitData::~InitData()
{
}

HydData::HydData()
: HasHybrid(false)
, UsesKINECT(false)
, ScoreType(-1)
, TopP(0)
, MidP(0)
, LowP(0)
{
}

HydData::~HydData()
{
}

TeleData::TeleData()
: Disabled(false)
, DisabledCounter(0)
, Bridge(false)
, Bar(false)
, BallsPU(0)
, TopP(0)
, MidP(0)
, LowP(0)
{
}

TeleData::~TeleData()
{
}

BrdgData::BrdgData()
: BalanceType(-1)
, BalanceAmount(-1)
{
}

BrdgData::~BrdgData()
{
}

EndData::EndData()
: Defensive(false)
, Assist(false)
, Technical(0)
, Regular(0)
, YellowPenalty(false)
, RedPenalty(false)
, Finish(false)
{
}

EndData::~EndData()
{
}

GameData::GameData()
{
	HydData HydInfo;
	TeleData TeleInfo;
	BrdgData BrdgInfo;
	EndData EndInfo;
}

GameData::~GameData()
{
}

MatchData::MatchData()
{
	InitData InitInfo;
	GameData GameInfo;
}

MatchData::~MatchData()
{
}
