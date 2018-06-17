#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include "ui_QGetWidget.h"
#include "NumKeyBoard.h"
#include "define.h"
#include "CQRWidget.h"
#include "CMessage.h"
#include "CProgressWidget.h"


class QGetWidget : public QDialog, private Ui::QGetWidget
{
	Q_OBJECT
public:

	QGetWidget(QWidget *parent = Q_NULLPTR, WIDGET_TYPE types = MSGBOX_GET);
	
	~QGetWidget();
public:

	/*
	* DateTime : 2017-08-02
	* Describe : 更改按钮的文字
	*/
	void SetTypeText(WIDGET_TYPE types, QString& strText);

	/*
	* DateTime : 2017-08-09
	* Describe : 初始化 给消息提醒框赋值状态
	*/
	void Init(WIDGET_TYPE types);

	/*
	* DateTime : 2017-08-09
	* Describe : 设置弹窗提醒的文字信息
	*/
	void SetText(const QString& strContent);

	void NumClick(WIDGET_TYPE types);

	void QRClick(WIDGET_TYPE types);

	void  MessageBoxShow(int nInputNum, WIDGET_TYPE types);
private slots:
	void on_btnBack_clicked();

	void on_btnHome_clicked();

	void on_btnNumGet_clicked();

	void on_btnQRGet_clicked();

	void on_btnNumSave_clicked();

	void on_btnQRSave_clicked();


	void on_slot_OpendoorFinish();
private:
	std::shared_ptr<NumKeyBoard>		 m_pNumKeyWidget;
	std::shared_ptr<CQRWidget>			 m_pQRWidget;
	std::shared_ptr<CProgressWidget>     m_pProgressWidget;
	

};
