
#include <PA9.h>

#include "model.h"

#include "Controller.h"
#include "InitTab.h"

#include "tab.h"
#include "NumberSprite.h"
#include "checkbox.h"

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
}