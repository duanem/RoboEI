
#include <PA9.h>
#include "all_gfx.h"
#include "raguna.h"

#include "Controller.h"
#include "GameTabs.h"

#include "Tab.h"

#include "HydTab.h"
#include "TeleTab.h"
#include "BrdgTab.h"
#include "EndTab.h"

#include "Controllers.h"

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

void GameTabsController::loadData(const GameData& GameInfo)
{
}

void GameTabsController::saveData(GameData* GameInfo)
{
}

void GameTabsController::set_Controllee(TabGroup* tabgroup)
{
	mControllee = tabgroup;
}

TabGroup* initGameTabs()
{
	
	TabGroup* GameTabs = new TabGroup(Controllers::gameTabsController);

		GameTabs->add(initHydTab());
		GameTabs->add(initTeleTab());
		GameTabs->add(initBrdgTab());
		GameTabs->add(initEndTab());
		
	Controllers::gameTabsController->set_Controllee(GameTabs);
	
	return GameTabs;
}
