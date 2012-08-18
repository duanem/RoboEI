
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
	
	void set_LowerBridge(SpecialBox* sb);
	
	void set_Assist(SpecialBox* sb);
	
	void set_Other(SpecialBox* sb);
	
	void set_TScore(NumberSprite* ns);
	
	void set_MScore(NumberSprite* ns);
	
	void set_LScore(NumberSprite* ns);
	
private:

	Controller* mSuperController;
	
	CheckBox* HasHybrid;
	CheckBox* UsesKINECT;
	
	SpecialBox* LowerBridge;
	SpecialBox* Assist;
	SpecialBox* Other;
	
	NumberSprite* TScore;
	NumberSprite* MScore;
	NumberSprite* LScore;
};

Tab* initHydTab();

#endif