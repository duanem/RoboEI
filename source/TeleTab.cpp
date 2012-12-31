
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "TeleTab.h"
#include "model.h"

#include "Controller.h"
#include "NumberSprite.h"
#include "CheckBox.h"

#include "Controllers.h"

TeleTabController::TeleTabController(Controller* superController)
: Controller(superController)
, DisabledCounter(0)
{
	mSuperController = superController;
}

TeleTabController::~TeleTabController()
{
}

void TeleTabController::handleKey()
{
	if(!Disabled->get_mFrame())
	{
		LowerBridge->enable();
		TravelBar->enable();
		if(Pad.Held.L && Pad.Newpress.Y)
		{
			BallsPU->dec_mFrame();
			if(BallsPU->get_mFrame() < 0)
				BallsPU->set_mFrame(0);
		}
		else if(Pad.Newpress.Y)
		{
			BallsPU->inc_mFrame();
		}
		
		if(Pad.Held.L && Pad.Newpress.X)
		{
			TScore->dec_mFrame();
			if(TScore->get_mFrame() < 0)
				TScore->set_mFrame(0);
		}
		else if(Pad.Newpress.X)
		{
			TScore->inc_mFrame();
		}
		
		if(Pad.Held.L && Pad.Newpress.A)
		{
			MScore->dec_mFrame();
			if(MScore->get_mFrame() < 0)
				MScore->set_mFrame(0);
		}
		else if(Pad.Newpress.A)
		{
			MScore->inc_mFrame();
		}
		
		if(Pad.Held.L && Pad.Newpress.B)
		{
			LScore->dec_mFrame();
			if(LScore->get_mFrame() < 0)
				LScore->set_mFrame(0);
		}
		else if(Pad.Newpress.B)
		{
			LScore->inc_mFrame();
		}
	}
	else
	{
		LowerBridge->disable();
		TravelBar->disable();
	}
	
	// handle the Disabled Counter
	if(Stylus.Released && nsTT::wasTouched(Disabled))
	{
		PA_WaitForVBL();
		if(Disabled->get_mFrame())
			DisabledCounter->inc_mFrame();	
		if(Pad.Held.L && DisabledCounter->get_mFrame() > 0)
			DisabledCounter->dec_mFrame();
	}
	
	if (mSuperController)
		mSuperController->handleKey();
}

void TeleTabController::loadData(const TeleData& TeleInfo)
{
	Disabled->set_mFrame(TeleInfo.Disabled);
	DisabledCounter->set_mFrame(TeleInfo.DisabledCounter);
	LowerBridge->set_mFrame(TeleInfo.Bridge);
	TravelBar->set_mFrame(TeleInfo.Bar);
	BallsPU->set_mFrame(TeleInfo.BallsPU);
	TScore->set_mFrame(TeleInfo.TopP);
	MScore->set_mFrame(TeleInfo.MidP);
	LScore->set_mFrame(TeleInfo.LowP);
}

void TeleTabController::saveData(TeleData* TeleInfo)
{
	TeleInfo->Disabled = Disabled->get_mFrame();
	TeleInfo->DisabledCounter = DisabledCounter->get_mFrame();
	TeleInfo->Bridge = LowerBridge->get_mFrame();
	TeleInfo->Bar = TravelBar->get_mFrame();
	TeleInfo->BallsPU = BallsPU->get_mFrame();
	TeleInfo->TopP = TScore->get_mFrame();
	TeleInfo->MidP = MScore->get_mFrame();
	TeleInfo->LowP = LScore->get_mFrame();
}

void TeleTabController::set_Disabled(CheckBox* cb)
{
	Disabled = cb;
}

void TeleTabController::set_LowerBridge(CheckBox* cb)
{
	LowerBridge = cb;
}

void TeleTabController::set_TravelBar(CheckBox* cb)
{
	TravelBar = cb;
}

void TeleTabController::set_BallsPU(NumberSprite* ns)
{
	BallsPU = ns;
}

void TeleTabController::set_TScore(NumberSprite* ns)
{
	TScore = ns;
}

void TeleTabController::set_MScore(NumberSprite* ns)
{
	MScore = ns;
}

void TeleTabController::set_LScore(NumberSprite* ns)
{
	LScore = ns;
}

void TeleTabController::set_DisabledCounter(NumberSprite* ns)
{
	DisabledCounter = ns;
}


Tab* initTeleTab()
{	
	Tab* TeleTab = new Tab(kBottomScreen, 64, 0, TeleTab_Sprite, &BGTele, Controllers::teleTabController);
	
		// checkboxes (If Occured)
		CheckBox* Disabled = new CheckBox(kBottomScreen, 137, 44, Disabled_Sprite);
		
			TeleTab->add(Disabled);
				Controllers::teleTabController->set_Disabled(Disabled);
		
		CheckBox* CanLowerBridge = new CheckBox(kBottomScreen, 90, 76, CanLowerBridge_Sprite);
		
			TeleTab->add(CanLowerBridge);
				Controllers::teleTabController->set_LowerBridge(CanLowerBridge);
		
		CheckBox* TravelAcrossBar = new CheckBox(kBottomScreen, 218, 76, TravelAcrossBar_Sprite);
		
			TeleTab->add(TravelAcrossBar);
				Controllers::teleTabController->set_TravelBar(TravelAcrossBar);
		
		// number sprites (Score Locations and Balls PU)
		NumberSprite* BallsPU = new NumberSprite(kBottomScreen, 104, 135, BALLS_Sprite);
		NumberSprite* TopScoreTele = new NumberSprite(kBottomScreen, 222, 108, Top_Sprite);
		NumberSprite* MidScoreTele = new NumberSprite(kBottomScreen, 222, 135, Mid_Sprite);
		NumberSprite* LowScoreTele = new NumberSprite(kBottomScreen, 222, 164, Low_Sprite);
		
			TeleTab->add(BallsPU);
				Controllers::teleTabController->set_BallsPU(BallsPU);
			
			TeleTab->add(TopScoreTele);
				Controllers::teleTabController->set_TScore(TopScoreTele);
			
			TeleTab->add(MidScoreTele);
				Controllers::teleTabController->set_MScore(MidScoreTele);
			
			TeleTab->add(LowScoreTele);
				Controllers::teleTabController->set_LScore(LowScoreTele);
		
		// disabled counter display
		NumberSprite* DisabledCounter = new NumberSprite(kBottomScreen, 174, 44, BlankTitle_Sprite);
			
			TeleTab->add(DisabledCounter);
				Controllers::teleTabController->set_DisabledCounter(DisabledCounter);

	return TeleTab;
}

namespace nsTT
{
	bool wasTouched(CheckBox* cb)
	{
		return ((PA_SpriteStylusOver(cb->get_mSpriteNum())||PA_SpriteStylusOver(cb->get_mTitleSpriteNum()))&& cb->get_mScreen() == kBottomScreen);
	}
}