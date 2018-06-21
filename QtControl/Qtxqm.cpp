#include "Qtxqm.h"
#include <QDebug>
Qtxqm::Qtxqm(QObject *parent)
	: QObject(parent)
{
	m_dev = nullptr;
	
}

Qtxqm::~Qtxqm()
{
}

bool Qtxqm::Start_Receive()
{
	if (m_dev == nullptr)
	{
		m_dev = vbar_connectDevice(1);
		if (m_dev != nullptr)
		{
			QTimer::singleShot(0, this, SLOT(on_slot_getResultStr()));
			return 1;
		}
		return -1;
	}

}

void Qtxqm::on_slot_getResultStr()
{
	
	unsigned char result_buffer[1024];
	int datalen = 0;
	int datatype = 0;
	int ret = vbar_getResultStr(m_dev, result_buffer, &datalen, &datatype);
	if (ret ==0)
	{
		if (datalen > 0)
		{
			ret = vbar_beepControl(m_dev, 1);
			result_buffer[datalen] = '\0';
			m_strResult = (char*)result_buffer;
			emit sig_SendResult(QString::fromStdString(m_strResult.c_str()));
		}
	}


	QTimer::singleShot(5, this, SLOT(on_slot_getResultStr()));
}