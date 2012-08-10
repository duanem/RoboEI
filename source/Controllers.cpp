
#include "Controllers.h"

#include "IncludeTabs.h"

namespace Controllers
{
	Controller* Super = new Controller(NULL);
	GameTabsController* GTController = new GameTabsController(Super);
	HydTabController* HTController = new HydTabController(GTController);
	TeleTabController* TTController = new TeleTabController(GTController);
	BridgeTabController* BTController = new BridgeTabController(GTController);
	EndTabController* ETController = new EndTabController(GTController);
}