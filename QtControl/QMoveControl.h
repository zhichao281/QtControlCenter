#pragma once

#include <QObject>
#include <QPoint>
#include "QPortControl.h"
#include "include/HSingleton/HSingleton.h"
class QMoveControl : public QObject
{
	Q_OBJECT

public:
	QMoveControl(QObject *parent=nullptr);
	~QMoveControl();

	void Init();

	void Reset();

	void SetMove(QPoint startPoint, QPoint endPoint);

	void StartWork();

	void StartSecondWork();
signals:
	void  sig_finish();
public slots:

	void on_slot_MoveFinish();

	void on_slot_PushGoodsFinish();

	void on_slot_GetGoodsFinish();

	void on_slot_SuckTrayFinish();

	void on_slot_DropTrayFinish();


private:
	QPoint m_StartPoint;
	QPoint m_EndPoint;
	bool  m_bSecond;
	bool   m_bFinish;
};
