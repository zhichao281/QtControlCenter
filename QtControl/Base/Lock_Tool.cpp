
#include "Lock_Tool.h"
using namespace QLock_Tool;

/**************Êý¾ÝËø************************/


 CLock::CLock(QReadWriteLock &key, int nLockType): m_mutex(key)
{
	if (CLock::LOCK_WRITE == nLockType)
	{
		m_mutex.lockForWrite();
	}
	if ( CLock::LOCK_READ ==nLockType)
	{
		m_mutex.lockForRead();
	}
}
 CLock::~CLock()
{
	m_mutex.unlock();
}