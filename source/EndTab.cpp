
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"
#include "model.h"

#include "EndTab.h"

#include "Controller.h"
#include "NumberSprite.h"
#include "CheckBox.h"

#include "Controllers.h"

EndTabController::EndTabController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

EndTabController::~EndTabController()
{
}

void EndTabController::handleKey()
{
	if(Pad.Held.L && Pad.Newpress.X)
	{
		Technical->dec_mFrame();
		if(Technical->get_mFrame() < 0)
			Technical->set_mFrame(0);
	}
	else if(Pad.Newpress.X)
	{
		Technical->inc_mFrame();
	}
	
	if(Pad.Held.L && Pad.Newpress.A)
	{
		Regular->dec_mFrame();
		if(Regular->get_mFrame() < 0)
			Regular->set_mFrame(0);
	}
	else if(Pad.Newpress.A)
	{
		Regular->inc_mFrame();
	}
	
	if (mSuperController)
		mSuperController->handleKey();
}

void EndTabController::loadData(const EndData& EndInfo)
{
	Defensive->set_mFrame(EndInfo.Defensive);
	Assist->set_mFrame(EndInfo.Assist);
	Technical->set_mFrame(EndInfo.Technical);
	Regular->set_mFrame(EndInfo.Regular);
	YellowPenalty->set_mFrame(EndInfo.YellowPenalty);
	RedPenalty->set_mFrame(EndInfo.RedPenalty);
	Finish->set_mFrame(EndInfo.Finish);
}

void EndTabController::saveData(EndData* EndInfo)
{
	EndInfo->Defensive = Defensive->get_mFrame();
	EndInfo->Assist = Assist->get_mFrame();
	EndInfo->Technical = Technical->get_mFrame();
	EndInfo->Regular = Regular->get_mFrame();
	EndInfo->YellowPenalty = YellowPenalty->get_mFrame();
	EndInfo->RedPenalty = RedPenalty->get_mFrame();
}

void EndTabController::set_Defensive(CheckBox* cb)
{
	Defensive = cb;
}

void EndTabController::set_Assist(CheckBox* cb)
{
	Assist = cb;
}

void EndTabController::set_Technical(NumberSprite* ns)
{
	Technical = ns;
}

void EndTabController::set_Regular(NumberSprite* ns)
{
	Regular = ns;
}

void EndTabController::set_YellowPenalty(SpecialBox* sb)
{
	YellowPenalty = sb;
}

void EndTabController::set_RedPenalty(SpecialBox* sb)
{
	RedPenalty = sb;
}

void EndTabController::set_Finish(SpecialBox* sb)
{
	Finish = sb;
}

bool EndTabController::getFinishFrame()
{
	return Finish->get_mFrame();
}

Tab* initEndTab()
{
	Tab* EndTab = new Tab(kBottomScreen, 192, 0, EndTab_Sprite, &BGEnd, Controllers::endTabController);
	
		CheckBox* Defensive = new CheckBox(kBottomScreen, 100, 60, Defensive_Sprite);
		
			EndTab->add(Defensive);
				Controllers::endTabController->set_Defensive(Defensive);
		
		CheckBox* Assist = new CheckBox(kBottomScreen, 100, 92, Assist_Sprite);
		
			EndTab->add(Assist);
				Controllers::endTabController->set_Assist(Assist);
		
		NumberSprite* Technical = new NumberSprite(kBottomScreen, 224, 60, Technical_Sprite);
		NumberSprite* Regular = new NumberSprite(kBottomScreen, 224, 92, Regular_Sprite);
		
			EndTab->add(Technical);
				Controllers::endTabController->set_Technical(Technical);
			
			EndTab->add(Regular);
				Controllers::endTabController->set_Regular(Regular);
		
		SpecialBox* YellowPenalty = new SpecialBox(kBottomScreen, 146, 114, yellow_penalty_Sprite);
		
			EndTab->add(YellowPenalty);
				Controllers::endTabController->set_YellowPenalty(YellowPenalty);
		
		SpecialBox* RedPenalty = new SpecialBox(kBottomScreen, 42, 114, red_penalty_Sprite);
		
			EndTab->add(RedPenalty);
				Controllers::endTabController->set_RedPenalty(RedPenalty);
		
		SpecialBox* Finish = new SpecialBox(kBottomScreen, 160, 156, Finish_Sprite);
		
			EndTab->add(Finish);
				Controllers::endTabController->set_Finish(Finish);
	
	return EndTab;
}

bool endMatch()
{
	return Controllers::endTabController->getFinishFrame();
}