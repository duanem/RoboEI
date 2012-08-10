
#ifndef _game_InitTab_h
#define _game_InitTab_h

#include "model.h"

#include "Controller.h"

#include "Tab.h"

#include "NumberSprite.h"
#include "CheckBox.h"

#include <vector>


class InitTabController : public Controller {

public:

	InitTabController(Controller* superController);
	
	~InitTabController();
	
	void handleKey();
	
	void loadData(const InitData& InitInfo);
	
	void saveData(InitData* InitInfo);
	
	void set_AllianceColor(bool color);
	
	void add_BarSprite(SpecialBox* sb);
	
	void set_MatchNum(NumberSprite* ns);
	
	void set_TeamNum(NumberSprite* ns);
	
	void set_DSNum(NumberSprite* ns);

private:

	Controller* mSuperController;
	
	std::vector<SpecialBox*> AllianceColorBar;

	NumberSprite* MatchNum;
	NumberSprite* TeamNum;
	NumberSprite* DSNum;
	
	bool AllianceColor;

};

Tab* initInitTab();

#endif