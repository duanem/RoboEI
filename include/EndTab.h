
#ifndef _game_EndTab_h
#define _game_EndTab_h

#include "Controller.h"

#include "model.h"

#include "tab.h"
#include "NumberSprite.h"
#include "checkbox.h"


class EndTabController : public Controller {

public:
	
	EndTabController(Controller* superController);
	
	~EndTabController();
	
	void handleKey();
	
	void loadData(const EndData& EndInfo);
	
	void saveData(EndData* EndInfo);
	
	void set_Defensive(CheckBox* cb);
	
	void set_Assist(CheckBox* cb);
	
	void set_Technical(NumberSprite* ns);
	
	void set_Regular(NumberSprite* ns);
	
	void set_YellowPenalty(SpecialBox* sb);
	
	void set_RedPenalty(SpecialBox* sb);
	
	void set_Finish(SpecialBox* sb);
	
private:

	Controller* mSuperController;
	
	CheckBox* Defensive;
	CheckBox* Assist;
	
	NumberSprite* Technical;
	NumberSprite* Regular;
	
	SpecialBox* YellowPenalty;
	SpecialBox* RedPenalty;
	SpecialBox* Finish;
	
};

Tab* initEndTab();

#endif