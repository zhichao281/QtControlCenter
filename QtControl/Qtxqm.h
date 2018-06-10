#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QObject>
#include <string>
using namespace  std;

#include "../include/HSingleton/HSingleton.h"
#include "define.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif



class Qtxqm : public QObject
{
	Q_OBJECT

public:
	Qtxqm(QObject *parent=nullptr);

	~Qtxqm();

public:
	bool Start_Receive();

signals:
	void sig_SendResult(QString strResult);

public slots:
	void on_slot_getResultStr();

private:

	struct vbar_channel *m_dev;
	string  m_strResult;
};
#define gblTxqm HSingletonTemplatePtr<Qtxqm>::get()