#include "CProgressWidget.h"
#include "ControlSql.h"
#include <QTimer>
#include "QPortControl.h"
#include "QMoveControl.h"
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
	btn_back->hide();
	btn_home->hide();
	

}

CProgressWidget::~CProgressWidget()
{
}


bool CProgressWidget::setInputNum(int nInputNum, WIDGET_TYPE types)
{
	m_nInputNum = nInputNum;
	m_type = types;
	return true;

}

 void CProgressWidget::setValue(QString strWeight, QString strHeight)
{


}
