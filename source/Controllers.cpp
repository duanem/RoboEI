
#include "Controllers.h"

#include "IncludeTabs.h"

namespace Controllers
{
	Controller* Super = new Controller(NULL);
		GameTabsController* gameTabsController = new GameTabsController(Super);
			HydTabController* hydTabController = new HydTabController(gameTabsController);
			TeleTabController* teleTabController = new TeleTabController(gameTabsController);
			BridgeTabController* brdgTabController = new BridgeTabController(gameTabsController);
			EndTabController* endTabController = new EndTabController(gameTabsController);
		InfoTabsController* infoTabsController = new InfoTabsController(Super);
			InitTabController* initTabController = new InitTabController(infoTabsController);
}