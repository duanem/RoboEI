
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

int main()
{
	//int maxMatches;
	PA_Init();
	PA_InitVBL();
	fatInitDefault();
	
	int maxMatches = Loadmatches();
	printf("after Loadmatches();\n");
	MatchData MatchInfo;
	
	View Rebound;
	
	Rebound.add(initGameTabs());
	Rebound.add(initInfoTabs());

	while(true)
	{
		loadMatch(MatchInfo);
		
		if(readMatch() > maxMatches)
		{
			MatchInfo.InitInfo.MatchNum = 1;
			writeMatch(1);
		}
		
		Rebound.show();
		
		while(!endMatch())
		{
			Rebound.handle();
			Rebound.draw();
			Rebound.update();
			
			PA_WaitForVBL();
		}
		
		saveMatch(&MatchInfo);
		writeInfo(&MatchInfo);
		writeMatch(MatchInfo.InitInfo.MatchNum+1);
		MatchInfo = MatchData();
		
		Rebound.hide();
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
			
			if(result == EOF || !result)
				break;
			
			++i;
		}
	}
	else			// cant load data
		printf("Unable to load data");
	
	fclose(testRead);
	
	return i - 1;
	
}
	
void Loadrobotpic(int robotnum)
{
	//PA_InitText(1, 0);
	//PA_OutputText(1, 0, 23, "Team:%d", MatchList[MatchInfo.InitInfo.MatchNum-1].RobotNo[dsnumber-1] );
	
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

void writeInfo(MatchData* MatchInfo)
{
	FILE* dataFile = fopen("data.txt", "ab");
	fprintf(dataFile, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",
	
	MatchInfo->InitInfo.MatchNum,
	MatchInfo->InitInfo.TeamNum,
	MatchInfo->InitInfo.AllianceColor,
	
	MatchInfo->GameInfo.HydInfo.HasHybrid,
	MatchInfo->GameInfo.HydInfo.UsesKINECT,
	MatchInfo->GameInfo.HydInfo.LowerBridge,
	MatchInfo->GameInfo.HydInfo.Assist,
	MatchInfo->GameInfo.HydInfo.Other,
	MatchInfo->GameInfo.HydInfo.TopP,
	MatchInfo->GameInfo.HydInfo.MidP,
	MatchInfo->GameInfo.HydInfo.LowP,
	
	MatchInfo->GameInfo.TeleInfo.Disabled,
	MatchInfo->GameInfo.TeleInfo.DisabledCounter,
	MatchInfo->GameInfo.TeleInfo.Bridge,
	MatchInfo->GameInfo.TeleInfo.Bar,
	MatchInfo->GameInfo.TeleInfo.BallsPU,
	MatchInfo->GameInfo.TeleInfo.TopP,
	MatchInfo->GameInfo.TeleInfo.MidP,
	MatchInfo->GameInfo.TeleInfo.LowP,
	
	MatchInfo->GameInfo.BrdgInfo.BalanceType,
	MatchInfo->GameInfo.BrdgInfo.BalanceAmount,
	
	MatchInfo->GameInfo.EndInfo.Defensive,
	MatchInfo->GameInfo.EndInfo.Assist,
	MatchInfo->GameInfo.EndInfo.Technical,
	MatchInfo->GameInfo.EndInfo.Regular,
	MatchInfo->GameInfo.EndInfo.YellowPenalty,
	MatchInfo->GameInfo.EndInfo.RedPenalty);
	
	fclose(dataFile);
}

void loadMatch(const MatchData& MatchToLoad)
{
	using namespace Controllers;
	
	Super->loadData();
		gameTabsController->loadData(MatchToLoad.GameInfo);
			hydTabController->loadData(MatchToLoad.GameInfo.HydInfo);
			teleTabController->loadData(MatchToLoad.GameInfo.TeleInfo);
			brdgTabController->loadData(MatchToLoad.GameInfo.BrdgInfo);
			endTabController->loadData(MatchToLoad.GameInfo.EndInfo);
		infoTabsController->loadData(MatchToLoad);
			initTabController->loadData(MatchToLoad.InitInfo);
			
}

void saveMatch(MatchData* MatchToSave)
{
	using namespace Controllers;
	
	Super->saveData();
		gameTabsController->saveData(&MatchToSave->GameInfo);
			hydTabController->saveData(&MatchToSave->GameInfo.HydInfo);
			teleTabController->saveData(&MatchToSave->GameInfo.TeleInfo);
			brdgTabController->saveData(&MatchToSave->GameInfo.BrdgInfo);
			endTabController->saveData(&MatchToSave->GameInfo.EndInfo);
		
		infoTabsController->saveData(MatchToSave);
			initTabController->saveData(&MatchToSave->InitInfo);
	
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