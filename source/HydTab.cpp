
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "HydTab.h"
#include "model.h"

#include "Controller.h"
#include "NumberSprite.h"
#include "CheckBox.h"
#include "RadioButton.h"

#include "Controllers.h"


HydTabController::HydTabController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

HydTabController::~HydTabController()
{
}

void HydTabController::handleKey()
{
	
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
		
	if(HasHybrid->get_mFrame() == false)
	{
		ScoreType->disable();
		UsesKINECT->set_mFrame(false);
		TScore->set_mFrame(0);
		MScore->set_mFrame(0);
		LScore->set_mFrame(0);
	}
	
	if (mSuperController)
		mSuperController->handleKey();
}

void HydTabController::loadData(const HydData& HydInfo)
{
	HasHybrid->set_mFrame(HydInfo.HasHybrid);
	UsesKINECT->set_mFrame(HydInfo.UsesKINECT);
	ScoreType->set_CurRB(HydInfo.ScoreType);
	TScore->set_mFrame(HydInfo.TopP);
	MScore->set_mFrame(HydInfo.MidP);
	LScore->set_mFrame(HydInfo.LowP);
}

void HydTabController::saveData(HydData* HydInfo)
{
	HydInfo->HasHybrid = HasHybrid->get_mFrame();
	HydInfo->UsesKINECT = UsesKINECT->get_mFrame();
	HydInfo->ScoreType = ScoreType->get_CurRB();
	HydInfo->TopP = TScore->get_mFrame();
	HydInfo->MidP = MScore->get_mFrame();
	HydInfo->LowP = LScore->get_mFrame();
}

void HydTabController::set_HasHybrid(CheckBox* cb)
{
	HasHybrid = cb;
}

void HydTabController::set_UsesKINECT(CheckBox* cb)
{
	UsesKINECT = cb;
}

void HydTabController::set_ScoreType(RBGroup* rbg)
{
	ScoreType = rbg;
}

void HydTabController::set_TScore(NumberSprite* ns)
{
	TScore = ns;
}

void HydTabController::set_MScore(NumberSprite* ns)
{
	MScore = ns;
}

void HydTabController::set_LScore(NumberSprite* ns)
{
	LScore = ns;
}

Tab* initHydTab()
{
	Tab* HydTab = new Tab(kBottomScreen, 0, 0, HybridTab_Sprite, &BGHybrid, Controllers::hydTabController);
	
		// checkboxes (Hybrid Type)
		CheckBox* HasHybrid = new CheckBox(kBottomScreen, 88, 40, HasHybrid_Sprite);
		
			HydTab->add(HasHybrid);
				Controllers::hydTabController->set_HasHybrid(HasHybrid);
		
		CheckBox* UsesKINECT = new CheckBox(kBottomScreen, 224, 40, UsesKINECT_Sprite);
		
			HydTab->add(UsesKINECT);
				Controllers::hydTabController->set_UsesKINECT(UsesKINECT);
		
		// radiobuttons (Score Type)
		RBGroup* ScoreType = new RBGroup;
		
		RadioButton* LowerBridge = new RadioButton(kBottomScreen, 32, 64, LwrBrdg_Sprite);
		RadioButton* HybridAssist = new RadioButton(kBottomScreen, 96, 64, HybAssist_Sprite);
		RadioButton* Other = new RadioButton(kBottomScreen, 160, 64, Other_Sprite);
		
		ScoreType->add(LowerBridge);
		ScoreType->add(HybridAssist);
		ScoreType->add(Other);
		
			HydTab->add(ScoreType);
				Controllers::hydTabController->set_ScoreType(ScoreType);
		
		// number_sprites (Score Locations)
		NumberSprite* TopScore = new NumberSprite(kBottomScreen, 140, 106, Top_Sprite);
		NumberSprite* MidScore = new NumberSprite(kBottomScreen, 140, 128, Mid_Sprite);
		NumberSprite* LowScore = new NumberSprite(kBottomScreen, 140, 150, Low_Sprite);
		
			HydTab->add(TopScore);
				Controllers::hydTabController->set_TScore(TopScore);
			
			HydTab->add(MidScore);
				Controllers::hydTabController->set_MScore(MidScore);
			
			HydTab->add(LowScore);
				Controllers::hydTabController->set_LScore(LowScore);
	
	return HydTab;
}