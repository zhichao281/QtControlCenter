
#ifndef _QEXTSERIALPORT_H_
#define _QEXTSERIALPORT_H_

/*POSIX CODE*/


/*MS WINDOWS CODE*/

#include "win_qextserialport.h"
#define QextBaseType Win_QextSerialPort


class QextSerialPort: public QextBaseType 
{
	Q_OBJECT
	
	public:
		typedef QextSerialBase::QueryMode QueryMode;

	    QextSerialPort();
	    QextSerialPort(const QString & name, QueryMode mode = QextSerialPort::Polling);
	    QextSerialPort(PortSettings const& s, QueryMode mode = QextSerialPort::Polling);
	    QextSerialPort(const QString & name, PortSettings const& s, QueryMode mode = QextSerialPort::Polling);
	    QextSerialPort(const QextSerialPort& s);
	    QextSerialPort& operator=(const QextSerialPort&);
	    virtual ~QextSerialPort();

};

#endif
