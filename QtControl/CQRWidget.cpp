#include "CQRWidget.h"
#include <QTimer>
#include "Qtxqm.h"
#include "QMoveControl.h"
#include "ControlSql.h"
CQRWidget::CQRWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);

	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMinimizeButtonHint);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	pMove = new QMovie(":/Image/Resources/Image/saoma.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	connect(btn_back, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
	connect(btn_home, SIGNAL(clicked()), this, SLOT(on_btnHome_clicked()));
	

	connect(gblTxqm, SIGNAL(sig_SendResult(QString)), this, SLOT(on_slot_SendResult(QString)));
	
	connect(gblPortControl, SIGNAL(sig_OpendoorFinish()), this, SLOT(on_slot_OpendoorFinish()));

	connect(gblPortControl, SIGNAL(sig_ClosedoorFinish()), this, SLOT(on_slot_ClosedoorFinish()));

	connect(gblMoveControl, SIGNAL(sig_finish()), this, SLOT(on_slot_finish()));

}

CQRWidget::~CQRWidget()
{
}

void CQRWidget::Init(WIDGET_TYPE types)
{
	m_type = types;
	if (types & MSGBOX_GET)
	{
			label_title->setStyleSheet("min-width:504;"
									   "max-width:504;"
			                           "min-height:71px;"
			                           "max-height:71px;"
			                           "border-image: url(:/Image/Resources/Image/请扫描二维码取件.png);");
	}
	if (types & MSGBOX_SAVE)
	{	
		label_title->setStyleSheet("min-width:504;"
								   " max-width:504;"
								   "min-height:71px;"
			                       "max-height:71px;"
			                       "border-image: url(:/Image/Resources/Image/请扫描二维码存件.png);");
	}

}


void CQRWidget::on_btnBack_clicked()
{
	done(MSGBOX_BACK);
}
void CQRWidget::on_btnHome_clicked()
{
	done(MSGBOX_HOME);
}


void CQRWidget::on_slot_SendResult(QString strResult)
{
	if (strResult.length() != 6)
	{
		QMessageBox::about(nullptr, "onEnter", "二维码有误");
		return;
	}
	m_nInputNum = strResult.toInt();
	gblRuntimeData->InputNum = m_nInputNum;
	if (m_type & MSGBOX_GET)
	{
		AppInfo app;
		bool bres = gblControlSql->Get_App_By_QRnum(m_nInputNum, app);
		if (bres == false)
		{
			QMessageBox::about(nullptr, "警告", "此二维码不存在！");
			return;
		}
		done(gblRuntimeData->InputNum);
	}
	else
	{
		AppInfo app;
		bool bres = gblControlSql->Get_App_By_QRnum(m_nInputNum, app);
		if (bres == true)
		{
			QMessageBox::about(nullptr, "警告", "此二维码已使用！");
			return;
		}
		app.saveQRNum = m_nInputNum;

		for (int i = 0; i < 3; i++)
		{
			int nRow = 0;
			switch (i)
			{
			case 0:
				nRow = 15;
				break;
			case 1:
				nRow = 25;
				break;
			case 2:
				nRow = 35;
				break;
			case 3:
				nRow = 40;
				break;
			default:
				break;
			}
			for (int j = 0; j < 3; j++)
			{
				int nColumn = 0;
				switch (j)
				{
				case 0:
					nColumn = 2;
					break;
				case 1:
					nColumn = 6;
					break;
				case 2:
					nColumn = 7;
					break;
				}
				AppInfo Info;
				bool bresult = gblControlSql->Get_App_By_Point(nRow, nColumn, Info);
				if (bresult == false)
				{
					app.savePoint.setX(nRow);
					app.savePoint.setY(nColumn);
					gblControlSql->Add_AppInfo(app);
					gblMoveControl->SetMove(QPoint(nRow, nColumn), QPoint(0, 0));
					gblMoveControl->StartWork();

					return;
				}
			}
		}
	}
	

	
}



void CQRWidget::on_slot_finish()
{

	gblPortControl->OpenDoor();
}

void CQRWidget::on_slot_OpendoorFinish()
{
	if (m_type & MSGBOX_SAVE)
	{
		done(m_nInputNum);
	}
	if (m_type & MSGBOX_GET)
	{
	}
	
}
void CQRWidget::on_slot_ClosedoorFinish()
{
}