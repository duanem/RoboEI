
#include <PA9.h>
#include "all_gfx.h"

#include "raguna.h"

#include "BrdgTab.h"
#include "model.h"

#include "Controller.h"
#include "RadioButton.h"

#include "Controllers.h"

BridgeTabController::BridgeTabController(Controller* superController)
: Controller(superController)
{
	mSuperController = superController;
}

BridgeTabController::~BridgeTabController()
{
}

void BridgeTabController::handleKey()
{
	if(BalanceType->get_CurRB() == 4)
	{
		BalanceAmount->disable();
	}
	
	if (mSuperController)
		mSuperController->handleKey();
}

void BridgeTabController::loadData(const BrdgData& BrdgInfo)
{
	BalanceType->set_CurRB(BrdgInfo.BalanceType);
	BalanceAmount->set_CurRB(BrdgInfo.BalanceAmount);
}

void BridgeTabController::saveData(BrdgData* BrdgInfo)
{
	BrdgInfo->BalanceType = BalanceType->get_CurRB();
	BrdgInfo->BalanceAmount = BalanceAmount->get_CurRB();
}

void BridgeTabController::set_BalanceType(RBGroup* rbg)
{
	BalanceType = rbg;
}

void BridgeTabController::set_BalanceAmount(RBGroup* rbg)
{
	BalanceAmount = rbg;
}

Tab* initBrdgTab()
{
	
	Tab* BrdgTab = new Tab(kBottomScreen, 128, 0, BridgeTab_Sprite, &BGBridge, Controllers::BTController);
	
		RBGroup* BalanceType = new RBGroup;
		
			RadioButton* Balance = new RadioButton(kBottomScreen, 31, 36, Balanc_Sprite);
			RadioButton* BalanCO = new RadioButton(kBottomScreen, 31, 65, BalanCO_Sprite);
			RadioButton* AttBal = new RadioButton(kBottomScreen, 31, 96, AttBal_Sprite);
			RadioButton* AttBalCO = new RadioButton(kBottomScreen, 31, 125, AttBalCO_Sprite);
			RadioButton* None = new RadioButton(kBottomScreen, 31, 156, none_Sprite);
		
		BalanceType->add(Balance);
		BalanceType->add(BalanCO);
		BalanceType->add(AttBal);
		BalanceType->add(AttBalCO);
		BalanceType->add(None);
		
		BrdgTab->add(BalanceType);
			Controllers::BTController->set_BalanceType(BalanceType);
		
		RBGroup* BalanceAmount = new RBGroup;
		
			RadioButton* OneBot = new RadioButton(kBottomScreen, 153, 68, One_Sprite);
			RadioButton* TwoBot = new RadioButton(kBottomScreen, 153, 100, Two_Sprite);
			RadioButton* ThreeBot = new RadioButton(kBottomScreen, 153, 132, Three_Sprite);
		
		BalanceAmount->add(OneBot);
		BalanceAmount->add(TwoBot);
		BalanceAmount->add(ThreeBot);
		
		BrdgTab->add(BalanceAmount);
			Controllers::BTController->set_BalanceAmount(BalanceAmount);
		
	return BrdgTab;
}