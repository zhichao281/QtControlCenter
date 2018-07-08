#include "QAdminWidget.h"
#include "QMoveControl.h"

QAdminWidget::QAdminWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setupUi(this);
	connect(btn_move, SIGNAL(clicked()), this, SLOT(on_slot_move()));
	
	m_pMoveControl.reset(new QMoveControl);
	connect(m_pMoveControl.get(), SIGNAL(sig_finish()), this, SLOT(on_slot_finish()));
	
	connect(gblPortControl, SIGNAL(sig_ReadSetting(int,QString)), this, SLOT(solt_ReadSetting(int ,QString)));


	
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
	timer->setInterval(100);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(on_slot_btn_weight()));
}

QAdminWidget::~QAdminWidget()
{
}
void QAdminWidget::on_slot_move()
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
		m_pMoveControl->SetMove(QPoint(nRow, nColumn), QPoint(0, 0));
		m_pMoveControl->StartWork();
	}
	else if (radio_save->isChecked())
	{
		m_pMoveControl->SetMove(QPoint(0, 0), QPoint(nRow, nColumn));
		m_pMoveControl->StartWork();
	}
	else if (radio_null->isChecked())
	{
		m_pMoveControl->Reset();
		gblPortControl->MovePoint(nRow, nColumn);
	}
	
}
void QAdminWidget::on_slot_finish()
{

}
void QAdminWidget::on_slot_open()
{
	m_pMoveControl->Reset();
	LOG_INFO("finish opendoor");
	gblPortControl->OpenDoor();

}
void QAdminWidget::on_slot_close()
{
	m_pMoveControl->Reset();
	gblPortControl->CloseDoor();

}


void QAdminWidget::on_slot_suck()
{
	m_pMoveControl->Reset();
	gblPortControl->SuckTray();
}
void QAdminWidget::on_slot_drop()
{
	m_pMoveControl->Reset();
	gblPortControl->DropTray();
}
void QAdminWidget::on_slot_pull()
{
	m_pMoveControl->Reset();
	gblPortControl->GetGoods();
}
void QAdminWidget::on_slot_push()
{
	m_pMoveControl->Reset();
	gblPortControl->PushGoods();
}

void QAdminWidget::on_slot_btn_height()
{
	gblPortControl->GetHeight();
	QTimer::singleShot(100, this, [=]()
	{
		edit_height->setText(gblRuntimeData->strHeight);

	});
}
void QAdminWidget::on_slot_btn_weight()
{
	gblPortControl->setReadState(true);
	eidt_weight->setText(gblRuntimeData->strWeight);
	if (timer->isActive() == false)
	{
		timer->start();
	}
}
void QAdminWidget::on_slot_btn_setZero()
{
	gblPortControl->SetZero();
	eidt_weight->setText(gblRuntimeData->strWeight);
}
void QAdminWidget::on_slot_move_setting()
{
	gblPortControl->move_setting(move_edit->text().toInt());
}
void QAdminWidget::on_slot_move_read()
{
	gblPortControl->move_read();
	
}
void QAdminWidget::on_slot_rotate_setting()
{
	gblPortControl->rotate_setting(rotate_edit->text().toInt());
}
void QAdminWidget::on_slot_rotate_read()
{
	gblPortControl->rotate_read();
}
void QAdminWidget::on_slot_tray_setting()
{
	gblPortControl->tray_setting(tray_edit->text().toInt());
}
void QAdminWidget::on_slot_tray_read()
{
	gblPortControl->tray_read();
}
void QAdminWidget::on_slot_door_setting()
{
	gblPortControl->door_setting(door_edit->text().toInt());
}
void QAdminWidget::on_slot_door_read()
{
	gblPortControl->door_read();
}
void QAdminWidget::on_slot_zero_setting()
{
	gblPortControl->zero_setting(zero_edit->text().toInt());
}

void QAdminWidget::on_slot_zero_read()
{
	gblPortControl->zero_read();
}

void QAdminWidget::on_slot_btn_setting()
{

}

void  QAdminWidget::solt_ReadSetting(int nAction , QString strRecevice)
{
	//int n1 = strRecevice.section(" ", 8, 9);
	QString str1 = strRecevice.section(" ", 7, 7).toInt(0, 16);
	QString str2 = strRecevice.section(" ", 8, 8).toInt(0, 16);
	QString str3 = strRecevice.section(" ", 9, 9).toInt(0, 16);
	QString str4 = strRecevice.section(" ", 10, 10).toInt(0, 16);
	QString str = str1 + str2 + str3 + str4;

	QString strText = QString::number(str.toInt(0, 16));

	switch (nAction)
	{
	case Action_Read_Move:
	{
		move_edit->setText(strText);
		break;
	}
	case Action_Read_Rotate:
	{
		rotate_edit->setText(strText);
		break;
	}
	case Action_Read_Tray:
	{
		tray_edit->setText(strText);
		break;
	}
	case Action_Read_Door:
	{
		door_edit->setText(strText);
		break;
	}
	case Action_Read_Zero:
	{
		zero_edit->setText(strText);
		break;
	}


	default:
		break;
	}

}