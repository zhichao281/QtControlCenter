#include "QGetWidget.h"
#include <QDebug>
#include "QMoveControl.h"
QGetWidget::QGetWidget(QWidget *parent, WIDGET_TYPE types)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint );
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	Init(types);

	connect(btn_back, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
	connect(btn_home, SIGNAL(clicked()), this, SLOT(on_btnHome_clicked()));
	
	connect(btn_NumGet, SIGNAL(clicked()), this, SLOT(on_btnNumGet_clicked()));
	connect(btn_QRGet, SIGNAL(clicked()), this, SLOT(on_btnQRGet_clicked()));
	connect(btn_NumSave, SIGNAL(clicked()), this, SLOT(on_btnNumSave_clicked()));
	connect(btn_QRSave, SIGNAL(clicked()), this, SLOT(on_btnQRSave_clicked()));



}

QGetWidget::~QGetWidget()
{
}


void QGetWidget::Init(WIDGET_TYPE types)
{
	widget_Save->hide();
	widget_get->hide();
	label_title->hide();
	if (types & MSGBOX_GET)
	{
		widget_get->show();
	}
	if (types & MSGBOX_SAVE)
	{
		widget_Save->show();
	}

}


void QGetWidget::on_btnNumGet_clicked()
{

	NumClick(WIDGET_TYPE::MSGBOX_GET);
}
void QGetWidget::on_btnQRGet_clicked()
{
	QRClick(WIDGET_TYPE::MSGBOX_GET);
}
void QGetWidget::on_btnNumSave_clicked()
{
	NumClick(WIDGET_TYPE::MSGBOX_SAVE);
}
void QGetWidget::on_btnQRSave_clicked()
{
	QRClick(WIDGET_TYPE::MSGBOX_SAVE);
}

void QGetWidget::QRClick(WIDGET_TYPE types)
{
	gblRuntimeData->m_type = types;

	m_pQRWidget.reset(new CQRWidget);
	m_pQRWidget->Init(types);
	m_pQRWidget->showMaximized();
	int res = m_pQRWidget->exec();
	m_pQRWidget.reset();
	if (res == WIDGET_TYPE::MSGBOX_BACK)
	{
		this->show();
	}
	else if (res == WIDGET_TYPE::MSGBOX_HOME)
	{
		done(MSGBOX_HOME);
	}
	else
	{
		int nInputNum = res;
		WaitWorking(nInputNum, types);
		//MessageBoxShow(nInputNum, types);
	}

}

void QGetWidget::NumClick(WIDGET_TYPE types)
{
	gblRuntimeData->m_type = types;

	m_pNumKeyWidget.reset(new NumKeyBoard);
	m_pNumKeyWidget->Init(types);
	m_pNumKeyWidget->showMaximized();
	int res = m_pNumKeyWidget->exec();
	m_pNumKeyWidget.reset();
	if (res == WIDGET_TYPE::MSGBOX_BACK)
	{
		this->show();
		return;
	}
	else if (res == WIDGET_TYPE::MSGBOX_HOME)
	{
		done(MSGBOX_HOME);
		return;
	}
	else
	{
		int nInputNum = res;

		WaitWorking(nInputNum, types);
		
		//MessageBoxShow(nInputNum, types);
	}

}

//准备工作
void  QGetWidget::WaitWorking(int nInputNum, WIDGET_TYPE types)
{

	m_pWaitWorkProgresss.reset(new WaitWorkProgresss);
	bool bres = m_pWaitWorkProgresss->setInputNum(nInputNum, types);
	if (bres == false)
	{
		done(WIDGET_TYPE::MSGBOX_HOME);
		return;
	}
	m_pWaitWorkProgresss->showMaximized();
	int nResult = m_pWaitWorkProgresss->exec();
	m_pWaitWorkProgresss.reset();

	MessageBoxShow(nInputNum, types);

}

void  QGetWidget::StartWorking(int nInputNum, WIDGET_TYPE types)
{

	m_pStartWorkProgress.reset(new StartWorkProgress);
	bool bres = m_pStartWorkProgress->setInputNum(nInputNum, types);
	if (bres == false)
	{
		done(WIDGET_TYPE::MSGBOX_HOME);
		return;
	}
	m_pStartWorkProgress->showMaximized();
	int nResult = m_pStartWorkProgress->exec();
	m_pStartWorkProgress.reset();



}
void  QGetWidget::MessageBoxShow(int InputNum, WIDGET_TYPE types)
{
	m_nInputNum = InputNum;
	m_type = types;
	int nRes = 0;
	if (types == WIDGET_TYPE::MSGBOX_SAVE)
	{
		nRes = CMessage::WaitSave();
		if (nRes == WIDGET_TYPE::MSGBOX_BACK)
		{
			this->show();
			return;
		}
		else if (nRes == WIDGET_TYPE::MSGBOX_HOME)
		{
			done(WIDGET_TYPE::MSGBOX_HOME);
			return;
		}
		StartWorking(InputNum, types);	
		nRes = CMessage::SaveEnd();
		done(WIDGET_TYPE::MSGBOX_HOME);
		return;
	}
	else
	{
		nRes = CMessage::GetEnd();
		if (nRes == WIDGET_TYPE::MSGBOX_RETURN)
		{
			goto next;
		}
		else
		{		
			StartWorking(InputNum, types);
			AppInfo app;
			bool bres = gblControlSql->Get_App_By_QRnum(m_nInputNum, app);
			gblControlSql->Delete_AppInfo(app);

			done(WIDGET_TYPE::MSGBOX_HOME);
			return;
		}
		
	next:
		nRes = CMessage::WaitGet();
		if (nRes == WIDGET_TYPE::MSGBOX_BACK)
		{
			this->show();
			return;
		}
		else if (nRes == WIDGET_TYPE::MSGBOX_HOME)
		{
			done(WIDGET_TYPE::MSGBOX_HOME);
			return;
		}
	}

}



void QGetWidget::on_btnBack_clicked()
{
	done(MSGBOX_BACK);
}
void QGetWidget::on_btnHome_clicked()
{
	done(MSGBOX_HOME);
}