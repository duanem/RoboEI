
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "TeleTab.h"
#include "model.h"

#include "Controller.h"
#include "NumberSprite.h"
#include "checkbox.h"

#include "Controllers.h"

TeleTabController::TeleTabController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

TeleTabController::~TeleTabController()
{
}

void TeleTabController::handleKey()
{
	if(Disabled->get_mFrame() == false)
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
	
	if (mSuperController)
		mSuperController->handleKey();
}

void TeleTabController::loadData(const TeleData& TeleInfo)
{
	Disabled->set_mFrame(TeleInfo.Disabled);
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


Tab* initTeleTab()
{	
	Tab* TeleTab = new Tab(kBottomScreen, 64, 0, TeleTab_Sprite, &BGTele, Controllers::TTController);
	
		// checkboxes (If Occured)
		CheckBox Disabled(kBottomScreen, 157, 44, Disabled_Sprite);
		
			TeleTab->add(&Disabled);
				Controllers::TTController->set_Disabled(&Disabled);
		
		CheckBox CanLowerBridge(kBottomScreen, 90, 76, CanLowerBridge_Sprite);
		
			TeleTab->add(&CanLowerBridge);
				Controllers::TTController->set_LowerBridge(&CanLowerBridge);
		
		CheckBox TravelAcrossBar(kBottomScreen, 218, 76, TravelAcrossBar_Sprite);
		
			TeleTab->add(&TravelAcrossBar);
				Controllers::TTController->set_TravelBar(&TravelAcrossBar);
		
		// number sprites (Score Locations and Balls PU)
		NumberSprite BallsPU(kBottomScreen, 100, 127, BALLS_Sprite);
		NumberSprite TopScoreTele(kBottomScreen, 218, 100, Top_Sprite);
		NumberSprite MidScoreTele(kBottomScreen, 218, 127, Mid_Sprite);
		NumberSprite LowScoreTele(kBottomScreen, 218, 154, Low_Sprite);
		
			TeleTab->add(&BallsPU);
				Controllers::TTController->set_BallsPU(&BallsPU);
			
			TeleTab->add(&TopScoreTele);
				Controllers::TTController->set_TScore(&TopScoreTele);
			
			TeleTab->add(&MidScoreTele);
				Controllers::TTController->set_MScore(&MidScoreTele);
			
			TeleTab->add(&LowScoreTele);
				Controllers::TTController->set_LScore(&LowScoreTele);
		
	return TeleTab;
}