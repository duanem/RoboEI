
#include <PA9.h>
#include "all_gfx.h"
#include "raguna.h"

#include "model.h"
#include "main.h"

#include "Controller.h"
#include "InitTab.h"

#include "Tab.h"
#include "NumberSprite.h"
#include "CheckBox.h"

#include "Controllers.h"

#include <vector>

InitTabController::InitTabController(Controller* superController)
: Controller(superController)
, AllianceColor(false)
{
	mSuperController = superController;
}

InitTabController::~InitTabController()
{
}

void InitTabController::handleKey()
{
	if(Pad.Held.L && Pad.Held.R)
	{
		if(Pad.Newpress.Start && MatchNum->get_mFrame() < kMaxMatches) 					// dont increase above match 200
		{
			MatchNum->inc_mFrame();
			writeMatch(MatchNum->get_mFrame());
		}
		else if(Pad.Newpress.Select && MatchNum->get_mFrame() > 1) 						// dont decrease below match 1
		{
			MatchNum->dec_mFrame();
			writeMatch(MatchNum->get_mFrame());
		}
	}
			
	if (mSuperController)
		mSuperController->handleKey();
}

void InitTabController::loadData(const InitData& InitInfo)
{	
	DSNum->set_mFrame(InitInfo.DSNum);
	MatchNum->set_mFrame(InitInfo.MatchNum);	
	TeamNum->set_mFrame(InitInfo.TeamNum);
	
	for(std::vector<SpecialBox*>::iterator acbIter = AllianceColorBar.begin(); acbIter != AllianceColorBar.end(); ++acbIter)
	{
		(*acbIter)->set_mFrame(InitInfo.AllianceColor);
	}
	
	Loadrobotpic(TeamNum->get_mFrame());
}

void InitTabController::saveData(InitData* InitInfo)
{
	InitInfo->DSNum = DSNum->get_mFrame();
	InitInfo->MatchNum = MatchNum->get_mFrame();
	InitInfo->TeamNum = TeamNum->get_mFrame();
	InitInfo->AllianceColor = AllianceColor;
}

void InitTabController::add_BarSprite(SpecialBox* sb)
{
	AllianceColorBar.push_back(sb);
}

void InitTabController::set_TeamNum(NumberSprite* ns)
{
	TeamNum = ns;
}

void InitTabController::set_MatchNum(NumberSprite* ns)
{
	MatchNum = ns;
}

void InitTabController::set_DSNum(NumberSprite* ns)
{
	DSNum = ns;
}

Tab* initInitTab()
{
	Tab* InitTab = new Tab(kTopScreen, 0, 0, BlankTab_Sprite, &BGBlank, Controllers::initTabController);
	
		SpecialBox* AllianceColor1 = new SpecialBox(kTopScreen, 0, 160, RedBlue_Sprite);
		SpecialBox* AllianceColor2 = new SpecialBox(kTopScreen, 64, 160, RedBlue_Sprite);
		SpecialBox* AllianceColor3 = new SpecialBox(kTopScreen, 128, 160, RedBlue_Sprite);
		SpecialBox* AllianceColor4 = new SpecialBox(kTopScreen, 192, 160, RedBlue_Sprite);
		
			InitTab->add(AllianceColor1);
				Controllers::initTabController->add_BarSprite(AllianceColor1);
			
			InitTab->add(AllianceColor2);
				Controllers::initTabController->add_BarSprite(AllianceColor2);
			
			InitTab->add(AllianceColor3);
				Controllers::initTabController->add_BarSprite(AllianceColor3);
			
			InitTab->add(AllianceColor4);
				Controllers::initTabController->add_BarSprite(AllianceColor4);
				
		
		NumberSprite* TeamNum = new NumberSprite(kTopScreen, 52, 168, BlankTitle_Sprite);
		
			InitTab->add(TeamNum);
				Controllers::initTabController->set_TeamNum(TeamNum);
		
		NumberSprite* MatchNum = new NumberSprite(kTopScreen, 140, 168, BlankTitle_Sprite);
		
			InitTab->add(MatchNum);
				Controllers::initTabController->set_MatchNum(MatchNum);
		
		NumberSprite* DSNum = new NumberSprite(kTopScreen, 244, 168, BlankTitle_Sprite);
		
			InitTab->add(DSNum);
				Controllers::initTabController->set_DSNum(DSNum);
				
	
	return InitTab;
}