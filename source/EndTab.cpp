
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
	
	if(Pad.Held.L && Pad.Newpress.B)
	{
		Regular->dec_mFrame();
		if(Regular->get_mFrame() < 0)
			Regular->set_mFrame(0);
	}
	else if(Pad.Newpress.B)
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

Tab* initEndTab()
{
	Tab* EndTab = new Tab(kBottomScreen, 192, 0, EndTab_Sprite, &BGEnd, Controllers::ETController);
	
		CheckBox Defensive(kBottomScreen, 100, 60, Defensive_Sprite);
		
			EndTab->add(&Defensive);
				Controllers::ETController->set_Defensive(&Defensive);
		
		CheckBox Assist(kBottomScreen, 100, 92, Assist_Sprite);
		
			EndTab->add(&Assist);
				Controllers::ETController->set_Assist(&Assist);
		
		NumberSprite Technical(kBottomScreen, 220, 52, Technical_Sprite);
		NumberSprite Regular(kBottomScreen, 220, 84, Regular_Sprite);
		
			EndTab->add(&Technical);
				Controllers::ETController->set_Technical(&Technical);
			
			EndTab->add(&Regular);
				Controllers::ETController->set_Regular(&Regular);
		
		SpecialBox YellowPenalty(kBottomScreen, 146, 114, yellow_penalty_Sprite);
		
			EndTab->add(&YellowPenalty);
				Controllers::ETController->set_YellowPenalty(&YellowPenalty);
		
		SpecialBox RedPenalty(kBottomScreen, 42, 114, red_penalty_Sprite);
		
			EndTab->add(&RedPenalty);
				Controllers::ETController->set_RedPenalty(&RedPenalty);
		
		SpecialBox Finish(kBottomScreen, 160, 156, Finish_Sprite);
		
			EndTab->add(&Finish);
				Controllers::ETController->set_Finish(&Finish);
	
	return EndTab;
}