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

	connect(btn_height, SIGNAL(clicked()), this, SLOT(on_slot_btn_height()));
	connect(btn_weight, SIGNAL(clicked()), this, SLOT(on_slot_btn_weight()));
	connect(btn_setZero, SIGNAL(clicked()), this, SLOT(on_slot_btn_setZero()));
	connect(move_setting, SIGNAL(clicked()), this, SLOT(on_slot_move_setting()));
	connect(move_read, SIGNAL(clicked()), this, SLOT(on_slot_move_read()));
	connect(rotate_setting, SIGNAL(clicked()), this, SLOT(on_slot_rotate_setting()));
	connect(rotate_read, SIGNAL(clicked()), this, SLOT(on_slot_rotate_read()));
	connect(tray_setting, SIGNAL(clicked()), this, SLOT(on_slot_tray_setting()));
	connect(tray_read, SIGNAL(clicked()), this, SLOT(on_slot_tray_read()));
	connect(door_setting, SIGNAL(clicked()), this, SLOT(on_slot_door_setting()));
	connect(door_read, SIGNAL(clicked()), this, SLOT(on_slot_door_read()));
	connect(zero_setting, SIGNAL(clicked()), this, SLOT(on_slot_zero_setting()));
	connect(zero_read, SIGNAL(clicked()), this, SLOT(on_slot_zero_read()));
	connect(btn_setting, SIGNAL(clicked()), this, SLOT(on_slot_btn_setting()));
	timer = new QTimer(this);
	timer->setInterval(25);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(on_slot_btn_weight()));
}

QtGuiClass::~QtGuiClass()
{
}
void QtGuiClass::on_slot_move()
{
	int nRow = lineEdit_X->text().toInt();
	int nColumn = lineEdit_Y->text().toInt();
	if (nColumn>8)
	{
		QMessageBox::about(nullptr, "出错啦", "超出最高列数");

		lineEdit_Y->setText("0");
		return;
	}
	if (nRow>100)
	{
		QMessageBox::about(nullptr, "出错啦", "超出最高行数");

		lineEdit_X->setText("0");
		return;
	}
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

void QtGuiClass::on_slot_btn_height()
{

}
void QtGuiClass::on_slot_btn_weight()
{
	eidt_weight->setText(gblRuntimeData->strWeight);
	if (timer->isActive() == false)
	{
		timer->start();
	}
}
void QtGuiClass::on_slot_btn_setZero()
{
	gblPortControl->SetZero();
	eidt_weight->setText(gblRuntimeData->strWeight);
}
void QtGuiClass::on_slot_move_setting()
{

}
void QtGuiClass::on_slot_move_read()
{

}
void QtGuiClass::on_slot_rotate_setting()
{
}
void QtGuiClass::on_slot_rotate_read()
{

}
void QtGuiClass::on_slot_tray_setting()
{

}
void QtGuiClass::on_slot_tray_read()
{

}
void QtGuiClass::on_slot_door_setting()
{

}
void QtGuiClass::on_slot_door_read()
{

}
void QtGuiClass::on_slot_zero_setting()
{

}

void QtGuiClass::on_slot_zero_read()
{

}

void QtGuiClass::on_slot_btn_setting()
{

}