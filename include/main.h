

#ifndef raguna_main_h
#define raguna_main_h

// includes
#include "model.h"

// constants
const int kMaxMatches = 200;

struct TeamList
{
	int MatchNo;
	int RobotNo[6];
};

enum
{
	kRedAlliance = 0,
	kBlueAlliance = 1
};

// functions
int Loadmatches(void);
void Loadrobotpic(int robotnum);
void writeInfo(MatchData* MatchInfo);
void loadMatch(const MatchData& MatchToLoad);
void saveMatch(MatchData* MatchToSave);
int readMatch();
void writeMatch(int matchNum);
int readDS();
bool switchMatch(int referenceMatch);


#endif