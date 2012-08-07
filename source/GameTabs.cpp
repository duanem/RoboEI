
#include <PA9.h>

#include "Controller.h"
#include "GameTabs.h"

#include "tab.h"

#include "HydTab.h"
#include "TeleTab.h"
#include "BrdgTab.h"
#include "EndTab.h"

GameTabsController::GameTabsController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

GameTabsController::~GameTabsController()
{
}

void GameTabsController::handleKey()
{
	mControllee->set_NewTab(mControllee->get_CurTab() + Pad.Newpress.Right - Pad.Newpress.Left);
	
	if(mControllee->get_NewTab() < 0)
	{
		mControllee->set_NewTab(mControllee->size()-1);
	}
	else if(mControllee->get_NewTab() >= mControllee->size())
	{
		mControllee->set_NewTab(0);
	}
	
	if (mSuperController)
		mSuperController->handleKey();
}

void GameTabsController::loadData(const MatchData& MatchInfo)
{
}

void GameTabsController::saveData(MatchData* MatchInfo)
{
}

void GameTabsController::set_Controllee(TabGroup* tabgroup)
{
	mControllee = tabgroup;
}

TabGroup* initGameTabs(Controller* superController)
{
	GameTabsController GTController(superController);
	
	TabGroup* GameTabs = new TabGroup(&GTController);
	
		GameTabs->add(initHydTab(&GTController));
		GameTabs->add(initTeleTab(&GTController));
		GameTabs->add(initBrdgTab(&GTController));
		GameTabs->add(initEndTab(&GTController));
		
	GTController.set_Controllee(GameTabs);
	
	return GameTabs;
}
