#include "CProgressWidget.h"
#include "ControlSql.h"
#include <QTimer>
CProgressWidget::CProgressWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint| Qt::WindowMinimizeButtonHint);
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	pMove = new QMovie(":/Image/Resources/Image/loading.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	//QTimer::singleShot(1000 * 10, this, SLOT(on_slot_timeout()));

	btn_back->hide();
	btn_home->hide();
	
	connect(gblPortControl, SIGNAL(sig_ClosedoorFinish()), this, SLOT(on_slot_ClosedoorFinish()));
	connect(gblPortControl, SIGNAL(sig_SuckTrauFinish()), this, SLOT(slot_SuckTrauFinish()));

}

CProgressWidget::~CProgressWidget()
{
}


bool CProgressWidget::setInputNum(int nInputNum, WIDGET_TYPE types)
{
	AppInfo app;
	bool bres = gblControlSql->Get_App_By_QRnum(nInputNum, app);
	if (types == WIDGET_TYPE::MSGBOX_SAVE)
	{
		if (bres ==true )
		{
			QMessageBox::about(nullptr, "警告", "此二维码已使用！");
			return false;
		}
		app.saveQRNum = nInputNum;
		for (int nRow = MAXNULLTRAY; nRow< MAXROW;)
		{
			for (int nColumn = 0; nColumn < MAXCOLUMN; nColumn++)
			{
				AppInfo Info;
				bool bresult = gblControlSql->Get_App_By_Point(nRow, nColumn, Info);
				if (bresult == false)
				{
					app.savePoint.setX(nRow);
					app.savePoint.setY(nColumn);
					gblControlSql->Add_AppInfo(app);
					gblPortControl->CloseDoor();
					return true;
				}
			}
			nRow += ADDROW;
		}
	}
	else
	{
		if (bres == false)
		{
			QMessageBox::about(nullptr, "警告", "此二维码不存在！");
			return false;
		}

		bool bres = gblControlSql->Get_App_By_QRnum(nInputNum, app);
		label_weight->setText(QString::number(app.saveWeight));
		label_height->setText(QString::number(app.saveHeight));

	}

	return true;

}



void CProgressWidget::setValue(QString strWeight, QString strHeight)
{
	label_weight->setText(strWeight);
	label_height->setText(strHeight);
}

void CProgressWidget::on_slot_ClosedoorFinish()
{
	gblPortControl->SuckTray();
}
void CProgressWidget::slot_SuckTrauFinish()
{

}
void CProgressWidget::on_slot_timeout()
{
	done(0);
}