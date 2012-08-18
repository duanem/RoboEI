
#include <PA9.h>
#include "main.h"
#include "model.h"

extern struct MATCH MatchList[kMaxMatches];

InitData::InitData()
: DSNum(readDS())
, MatchNum(readMatch())
, TeamNum(MatchList[MatchNum-1].RobotNo[DSNum-1])
, AllianceColor(DSNum < 4 && DSNum > 0 ? kRedAlliance : kBlueAlliance)
{
}

InitData::~InitData()
{
}

HydData::HydData()
: HasHybrid(false)
, UsesKINECT(false)
, LowerBridge(false)
, Assist(false)
, Other(false)
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
}

GameData::~GameData()
{
}

MatchData::MatchData()
{
}

MatchData::~MatchData()
{
}
