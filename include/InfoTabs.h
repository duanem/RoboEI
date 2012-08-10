
#ifndef _game_InfoTabs_h
#define _game_InfoTabs_h

#include "Controller.h"

#include "Tab.h"

class InfoTabsController : public Controller {

public:

	InfoTabsController(Controller* superController);
	
	~InfoTabsController();
	
	void handleKey();
	
	void loadData(const MatchData& MatchInfo);
	
	void saveData(MatchData* MatchInfo);
	
	void set_Controllee(TabGroup* tabgroup);
	
private:

	Controller* mSuperController;
	
	TabGroup* mControllee;
};

TabGroup* initInfoTabs();
	
#endif