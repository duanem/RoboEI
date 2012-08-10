
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
// 4th # on screen
//, debugger(kTopScreen, 100, 150, Debug_Sprite)
{
	mSuperController = superController;
}

GameTabsController::~GameTabsController()
{
}

void GameTabsController::handleKey()
{
	//debugger.show();
	
	mControllee->set_NewTab(mControllee->get_CurTab() + Pad.Newpress.Right - Pad.Newpress.Left);
	
	//debugger.set_mFrame(1);
	//debugger.draw();
	
	if(mControllee->get_NewTab() < 0)
	{
		mControllee->set_NewTab(mControllee->size()-1);
	}
	else if(mControllee->get_NewTab() >= mControllee->size())
	{
		mControllee->set_NewTab(0);
	}
	
	//debugger.set_mFrame(2);
	//debugger.draw();
	
	if (mSuperController)
		mSuperController->handleKey();
		
	//debugger.set_mFrame(3);
	//debugger.draw();
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

TabGroup* initGameTabs()
{
	
	TabGroup* GameTabs = new TabGroup(Controllers::GTController);

		GameTabs->add(initHydTab());
		GameTabs->add(initTeleTab());
		GameTabs->add(initBrdgTab());
		GameTabs->add(initEndTab());
		
	Controllers::GTController->set_Controllee(GameTabs);
	
	return GameTabs;
}
