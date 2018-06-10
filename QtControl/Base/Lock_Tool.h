
#ifndef __LOCK_TOOL_H__
#define __LOCK_TOOL_H__

#include <Windows.h>
#include <QReadWriteLock>





namespace QLock_Tool
{
	class CLock
	{
	public:
		CLock(QReadWriteLock &key, int nLockType);
		~CLock();
		enum LOCK_TYPE 
		{
			LOCK_WRITE= 1,
			LOCK_READ= 2,
		};
	private:
		QReadWriteLock &m_mutex;//Ïß³ÌËø
	};


}


#define  _READ_LOCK_  QLock_Tool::CLock _lock(_mutex,QLock_Tool::CLock::LOCK_READ)
#define  _WRITE_LOCK_ QLock_Tool::CLock _lock(_mutex,QLock_Tool::CLock::LOCK_WRITE)
#define  _LOCK_KEY_   QReadWriteLock   _mutex


#endif