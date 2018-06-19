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
	}
	else
	{
		gblMoveControl->SetMove(QPoint(0, 0), QPoint(nRow, nColumn));
	}
	gblMoveControl->StartWork();
}
void QtGuiClass::on_slot_finish()
{

}
void QtGuiClass::on_slot_open()
{
	gblPortControl->OpenDoor();

}
void QtGuiClass::on_slot_close()
{

	gblPortControl->CloseDoor();

}


void QtGuiClass::on_slot_suck()
{
	gblPortControl->SuckTray();
}
void QtGuiClass::on_slot_drop()
{
	gblPortControl->DropTray();
}
void QtGuiClass::on_slot_pull()
{
	gblPortControl->GetGoods();
}
void QtGuiClass::on_slot_push()
{
	gblPortControl->PushGoods();
}
