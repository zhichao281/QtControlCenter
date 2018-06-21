#include "QtGuiClass.h"
#include "QMoveControl.h"

QtGuiClass::QtGuiClass(QWidget *parent)
	: QWidget(parent)
{
	this->setupUi(this);
	connect(btn_move, SIGNAL(clicked()), this, SLOT(on_slot_move()));
	

	connect(gblMoveControl, SIGNAL(sig_finish()), this, SLOT(on_slot_finish()));

	connect(btn_open, SIGNAL(clicked()), this, SLOT(on_slot_open()));
	connect(btn_close, SIGNAL(clicked()), this, SLOT(on_slot_close()));
	connect(btn_suck, SIGNAL(clicked()), this, SLOT(on_slot_suck()));
	connect(btn_drop, SIGNAL(clicked()), this, SLOT(on_slot_drop()));
	connect(btn_push, SIGNAL(clicked()), this, SLOT(on_slot_push()));
	connect(btn_pull, SIGNAL(clicked()), this, SLOT(on_slot_pull()));

}

QtGuiClass::~QtGuiClass()
{
}
void QtGuiClass::on_slot_move()
{
	int nRow = lineEdit_X->text().toInt();
	int nColumn = lineEdit_Y->text().toInt();
	if (radio_get->isChecked())
	{
		gblMoveControl->SetMove(QPoint(nRow, nColumn), QPoint(0, 0));
		gblMoveControl->StartWork();
	}
	else if (radio_save->isChecked())
	{
		gblMoveControl->SetMove(QPoint(0, 0), QPoint(nRow, nColumn));
		gblMoveControl->StartWork();
	}
	else if (radio_null->isChecked())
	{
		gblMoveControl->Reset();
		gblPortControl->MovePoint(nRow, nColumn);
	}
	
}
void QtGuiClass::on_slot_finish()
{

}
void QtGuiClass::on_slot_open()
{
	gblMoveControl->Reset();
	LOG_INFO("finish opendoor");
	gblPortControl->OpenDoor();

}
void QtGuiClass::on_slot_close()
{
	gblMoveControl->Reset();
	gblPortControl->CloseDoor();

}


void QtGuiClass::on_slot_suck()
{
	gblMoveControl->Reset();
	gblPortControl->SuckTray();
}
void QtGuiClass::on_slot_drop()
{
	gblMoveControl->Reset();
	gblPortControl->DropTray();
}
void QtGuiClass::on_slot_pull()
{
	gblMoveControl->Reset();
	gblPortControl->GetGoods();
}
void QtGuiClass::on_slot_push()
{
	gblMoveControl->Reset();
	gblPortControl->PushGoods();
}
