
#ifndef _game_BrdgTab_h
#define _game_BrdgTab_h

#include "Controller.h"

#include "model.h"

#include "tab.h"
#include "RadioButton.h"

class BridgeTabController : public Controller {

public:
	
	BridgeTabController(Controller* superController);
	
	~BridgeTabController();
	
	void handleKey();
	
	void loadData(const BrdgData& BrdgInfo);
	
	void saveData(BrdgData* BrdgInfo);
	
	void set_BalanceType(RBGroup* rbg);
	
	void set_BalanceAmount(RBGroup* rbg);
	
private:

	Controller* mSuperController;
	
	RBGroup* BalanceType;
	RBGroup* BalanceAmount;
	
};

Tab* initBrdgTab();

#endif