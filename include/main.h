
/*
	Current Projects - VERSION 0.8.1
	
	(do we need it?) PROJECT: Create a text object
		ADDITIONAL INFO: class Text: used to save("Text") to and object to allow
										text print attached to a tab
						 needs a Show, hide and draw function.  It is basically a
										string object that is a derision of Control

*/

#ifndef raguna_main_h
#define raguna_main_h

// includes
#include <vector>

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
void loadMatch(int matchNum);
int readMatch();
void writeMatch(int matchNum);
int readDS();


#endif