
/////////////////////////////
//  C++ NDSRAF and RoboEI  //
/////////////////////////////


// Includes
#include <PA9.h>
#include <fat.h>
#include "all_gfx.h"

/// NDSRAF includes
#include "raguna.h"

#include "Controller.h"

#include "View.h"
#include "Control.h"

#include "Tab.h"
#include "CheckBox.h"
#include "RadioButton.h"
#include "NumberSprite.h"

/// game includes
#include "main.h"
#include "IncludeTabs.h"
#include "Controllers.h"

// constants
const char* kMatchesFilename = "matches.txt";
const char* kDSFilename = "DS.txt";
const char* kCurMatchFilename = "savedmatch.txt";

// globals
struct MATCH MatchList [kMaxMatches];
int dsnumber = 0;
int maxMatches = 0;

bool matchnotfinished = false;

int main()
{
	// Initialize PAlib
	PA_Init();
	PA_InitVBL();
	fatInitDefault();
	
	PA_LoadBackground(kTopScreen, 3, &BGWhite);
	//1st # on screen
	NumberSprite Debugger(kTopScreen, 100, 0, Debug_Sprite);
	Debugger.show();

	View Everything;
	
	Everything.add(initGameTabs());
	
	Everything.show();
	// Infinite loop to keep the program running
	while(true)
	{
		// Put your game logic here
		Everything.handle();
		
		Debugger.set_mFrame(5);
		Debugger.draw();
		
		Everything.draw();
		
		Debugger.set_mFrame(6);
		Debugger.draw();
		
		Everything.update();
		
		Debugger.set_mFrame(7);
		Debugger.draw();
		
		// Wait until the next frame.
		// The DS runs at 60 frames per second.
		PA_WaitForVBL();
		Debugger.set_mFrame(8);
		Debugger.draw();
		PA_WaitForVBL();
	}
}

int Loadmatches()
{
	
	FILE* testRead = fopen (kMatchesFilename, "rb")	;	// rb = read mode
	int result = 0;
	int i = 0;
	
	if(testRead)	// loads data
	{
		while(i < kMaxMatches)
		{
			result = fscanf(testRead, "%d,%d,%d,%d,%d,%d,%d,\n\r",
			&MatchList[i].MatchNo,
			&MatchList[i].RobotNo[0],
			&MatchList[i].RobotNo[1],
			&MatchList[i].RobotNo[2],
			&MatchList[i].RobotNo[3],
			&MatchList[i].RobotNo[4],
			&MatchList[i].RobotNo[5]);
			
			++i;
		}
	}
	else			// cant load data
		PA_Print(kTopScreen, "Unable to load data");
	
	fclose(testRead);
	
	// done with reading the matches, now assign DS number
	
	testRead = fopen(kDSFilename, "rb");
	if(testRead)
	{
		result = fscanf(testRead, "%d\n\r", &dsnumber);
	}
	fclose(testRead);
	
	return i - 1;
	
}
	
void Loadrobotpic(int robotnum)
{
	//PA_InitText(1, 0);
	//PA_OutputText(1, 0, 23, "Team:%d", MatchList[Matchinfo.InitInfo.MatchNum-1].RobotNo[dsnumber-1] );
	
 	char* imgName = "Images/0000.gif";
	sprintf(imgName, "Images/%d.gif", robotnum);
	FILE* imgFile = fopen (imgName, "rb");

	if(imgFile)  // Make sure there is a file to load
	{
		PA_Init16bitBg(1, 1); /* Changed to 16 bit image */
		u32 imgSize;
		fseek (imgFile, 0, SEEK_END);
		imgSize = ftell (imgFile);
		rewind (imgFile);
		
		char * buffer;
		buffer = (char*) malloc (sizeof(char)*imgSize);
		fread (buffer, 1, imgSize, imgFile);
		
		// close the file
		fclose (imgFile);
		PA_LoadGif(1, (void *)buffer); // Show GIF on top screen
		free ((void *)buffer);
	} 
	else 
	{
		char* imgName = "Images/nopic.gif";
		FILE* imgFile = fopen (imgName, "rb");
		
		if(imgFile) // Make sure there is a file to load
		{
			PA_Init16bitBg(1, 1); /* Changed to 16 bit image */
			u32 imgSize;
			fseek (imgFile, 0, SEEK_END);
			imgSize = ftell (imgFile);
			rewind (imgFile);
			
			char * buffer;
			buffer = (char*) malloc (sizeof(char)*imgSize);
			fread (buffer, 1, imgSize, imgFile);
			
			// close the file
			fclose (imgFile);
			PA_LoadGif(1, (void *)buffer); // Show GIF on top screen
			free ((void *)buffer);
		}
	}
}

void writeInfo()
{
}

void loadMatch(int matchNum)
{
}

int readMatch()
{
	int result = 0;
	int matchNum = 1;
	FILE* f = fopen(kCurMatchFilename, "rb");	// "rb" = read
	if(f)
	{
		result = fscanf(f, "%d\n\r", &matchNum);
	}
	fclose(f);
	return matchNum;
}

void writeMatch(int matchNum)
{
	int result = 0;
	FILE* f = fopen(kCurMatchFilename, "wb");	// "wb" = write
	if(f)
	{
		result = fprintf(f, "%d", matchNum);
	}
	fclose(f);
}

int readDS()
{
	int result = 0;
	int dsnumber = 1;
	FILE* f = fopen(kDSFilename, "rb");	// "rb" = read
	if(f)
	{
		result = fscanf(f, "%d\n\r", &dsnumber);
	}
	fclose(f);
	return dsnumber;
}