

#ifndef raguna_main_h
#define raguna_main_h

// includes
#include "model.h"

// constants
const int kMaxMatches = 200;

struct MATCH
{
	int MatchNo;
	int RobotNo[6];
};

// functions
int Loadmatches(void);
void Loadrobotpic(int robotnum);
void writeInfo();
void loadMatch(const MatchData& MatchToLoad);
void saveMatch(MatchData* MatchToSave);
int readMatch();
void writeMatch(int matchNum);
int readDS();


#endif