
#include <PA9.h>
#include "all_gfx.h"
#include "raguna.h"

#include "Controller.h"
#include "InfoTabs.h"

#include "Tab.h"

#include "HydTab.h"
#include "TeleTab.h"
#include "BrdgTab.h"
#include "EndTab.h"

#include "Controllers.h"

InfoTabsController::InfoTabsController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

InfoTabsController::~InfoTabsController()
{
}

void InfoTabsController::handleKey()
{
	mControllee->set_NewTab(mControllee->get_CurTab() + Pad.Newpress.Up - Pad.Newpress.Down);
	
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

void InfoTabsController::loadData(const MatchData& MatchInfo)
{
}

void InfoTabsController::saveData(MatchData* MatchInfo)
{
}

void InfoTabsController::set_Controllee(TabGroup* tabgroup)
{
	mControllee = tabgroup;
}

TabGroup* initInfoTabs()
{
	
	TabGroup* InfoTabs = new TabGroup(Controllers::infoTabsController);

		InfoTabs->add(initInitTab());
		
	Controllers::infoTabsController->set_Controllee(InfoTabs);
	
	return InfoTabs;
}
