
#ifndef _game_HydTab_h
#define _game_HydTab_h

#include "Controller.h"

#include "model.h"

#include "Tab.h"
#include "CheckBox.h"
#include "NumberSprite.h"
#include "RadioButton.h"

class HydTabController : public Controller {

public:
	
	HydTabController(Controller* superController);
	
	~HydTabController();
	
	void handleKey();
	
	void loadData(const HydData& HydInfo);
	
	void saveData(HydData* HydInfo);
	
	void set_HasHybrid(CheckBox* cb);
	
	void set_UsesKINECT(CheckBox* cb);
	
	void set_ScoreType(RBGroup* rbg);
	
	void set_TScore(NumberSprite* ns);
	
	void set_MScore(NumberSprite* ns);
	
	void set_LScore(NumberSprite* ns);
	
private:

	Controller* mSuperController;
	
	CheckBox* HasHybrid;
	CheckBox* UsesKINECT;
	
	RBGroup* ScoreType;
	
	NumberSprite* TScore;
	NumberSprite* MScore;
	NumberSprite* LScore;
};

Tab* initHydTab();

#endif