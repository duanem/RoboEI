
#ifndef _game_GameTabs_h
#define _game_GameTabs_h

#include "Controller.h"

#include "Tab.h"

class GameTabsController : public Controller {

public:

	GameTabsController(Controller* superController);
	
	~GameTabsController();
	
	void handleKey();
	
	void loadData(const GameData& GameInfo);
	
	void saveData(GameData* GameInfo);
	
	void set_Controllee(TabGroup* tabgroup);
	
private:

	Controller* mSuperController;
	
	TabGroup* mControllee;
};

TabGroup* initGameTabs();

#endif