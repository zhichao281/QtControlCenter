#include "SQLBase.h"


#include <QSqlError>
#include <QSqlRecord>
#include <stdio.h>
#include <QCoreApplication>

#define CountArray(Array) (sizeof(Array)/sizeof(Array[0]))

CSQLBase::CSQLBase(QObject *parent)
	: QObject(parent)
{

	
}

CSQLBase::~CSQLBase()
{
	m_db.close();
}
void CSQLBase::SetTableName(QString dbName,QString strTableName )
{
	m_strDbName = dbName + ".db";
	m_strTableName=strTableName;
}

/* 打开数据库.*/
bool CSQLBase::opendatabase()
{
	_WRITE_LOCK_;
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setHostName("localhost"); //设置数据库主机名 
	m_strDbName=QString("%1/%2").arg(QCoreApplication::applicationDirPath()).arg(m_strDbName);
	m_db.setDatabaseName(m_strDbName); //设置数据库名 
	m_db.setUserName("root"); //设置数据库登入用户名 
	m_db.setPassword("123456"); //设计数据库登入密码 
	bool bResults=m_db.open();
	if (!bResults)
	{
		m_strError=m_db.lastError().text();
	}
	m_db.close();
	return bResults;
}
/* 创建表格.*/
bool CSQLBase::CreatTable(QString strTableName,QString strExpreesion)
{
	//CREAT TABLE IF NOT EXISTS +表名称  
	_WRITE_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return  false;
	}
	else
	{
		QSqlQuery query(m_db);
		m_strTableName=strTableName;
		QString sql = QString("create table if not exists ") + m_strTableName +strExpreesion;
		bool bResults = query.exec(sql);   //创建一个表
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}
}

/* 执行SQL语句.*/
BOOL CSQLBase::dbExecSql(QString strSql)
{
	_WRITE_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return  FALSE;
	}
	else
	{
		QSqlQuery query(m_db);
		bool bResults = query.exec(strSql);   //创建一个表
		if(!bResults)
		{
			m_strError=query.lastError().text();
			LOG_INFO("strSql=[%s],m_strError=[%s]", strSql.toStdString().c_str(),m_strError.toStdString().c_str());
			m_db.close();
			return bResults;
		}
		m_db.close();
		return bResults;
	}
}

/* 创建表格.*/
bool CSQLBase::CreatTable(QString strTableName,QStringList strExpreesion)
{
	//CREAT TABLE IF NOT EXISTS +表名称  
	_WRITE_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		m_strTableName=strTableName;
		QString sql = QString("create table if not exists ") + m_strTableName + QString(" ( ");

		for (int i=0; i < strExpreesion.size(); i++)
		{
			sql = sql + strExpreesion.value(i);
			if (i != strExpreesion.size() - 1)
			{
				sql+=QString(",");
			}
			else
			{
				sql = sql + QString(")");
			}
		}
		bool bResults = query.exec(sql);   //创建一个表
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}
}

/* 创建表格.*/
bool CSQLBase::CreatTableEx(QString strTableName,QStringList strExpreesion)
{
	//CREAT TABLE IF NOT EXISTS +表名称  
	_WRITE_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("create table if not exists ") + strTableName + QString(" ( ");

		for (int i=0; i < strExpreesion.size(); i++)
		{
			sql = sql + strExpreesion.value(i);
			if (i != strExpreesion.size() - 1)
			{
				sql+=QString(",");
			}
			else
			{
				sql = sql + QString(")");
			}
		}
		bool bResults = query.exec(sql);   //创建一个表
		if(!bResults)
		{
			m_strError=query.lastError().text();
			LOG_INFO("%s", "strSql=[%s],m_strError=[%s]",sql.toStdWString().c_str(), m_strError.toStdWString().c_str());
		}
		m_db.close();
		return bResults;
	}
}

/* 重命名表格.*/
bool CSQLBase::RenameTable(QString strTableName)
{
	// ALTER TABLE +旧表名+ RENAME TO +新表名 
	_WRITE_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("alter table ") + m_strTableName + QString(" rename to ") + strTableName;
		bool bResults = query.exec(sql);   //重命名
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}
}

/* 删除表格.*/
bool CSQLBase::DropTable(QString strTableName)
{
	// 删除表 - DROP TABLE +表名 
	_WRITE_LOCK_;
	if (!m_db.open())
	{
		m_db.close(); 
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("drop table ") + m_strTableName;
		bool bResults = query.exec(sql);   
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}

}

/* 表格某列是否存在.*/
bool CSQLBase::TableIsColumnExist(QString &strColumnName)
{
	_READ_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		//select * from sqlite_master where name='tablename' and sql like '%fieldname%'; 
		QString sql = QString("select * from sqlite_master where name='%1' and sql like '%%%2%%'").arg(m_strTableName, strColumnName);
		query.exec(sql);
		bool bRet = false;
		if (query.next())
		{
			bRet = true;
		}
		m_db.close();
		return bRet;
	}
}

/* 表格新增一列.*/
bool CSQLBase::TableAddColumn(QString &strExpreesion)
{
	_WRITE_LOCK_;
	//ALTER TABLE 表名 ADD COLUMN 列名 数据类型 限定符
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("alter table ") + m_strTableName + QString(" add column ") + strExpreesion;
		bool bResults = query.exec(sql);   //新增一列
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}

}

/* 插入函数. 构造SQL插入语句.*/
bool CSQLBase::Insert(QStringList &strName, QStringList &strValues)
{
	_WRITE_LOCK_;
	if (strName.size() != strValues.size())
	{
		return false;
	}
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);

		QString sql = QString("insert into ") + m_strTableName + QString("(");

		int i;

		for (i=0; i < strName.size(); i++)
		{
			sql = sql + strName.value(i);
			if (i != strName.size() - 1)
			{
				sql+=QString(",");
			}
			else
			{

				sql = sql + QString(")");
			}
		}

		sql = sql + QString(" values  (");

		for (i = 0; i < strValues.size(); i++)
		{
			sql = sql + QString("'") + strValues.value(i) + QString("'");
			if (i != strValues.size()-1)
			{
				sql = sql + QString(",");
			}
		}

		sql = sql + QString(")");
		bool bResults=query.exec(sql);
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}

}


/* 修改函数. 构造SQL修改语句.*/
bool CSQLBase::Update(QStringList &strNames, QStringList &strValues, QString &strExpreesion)
{
	_WRITE_LOCK_;

	if (strNames.size() != strValues.size())
	{
		return false;
	}

	//UPDATE 表名称 SET 列名称 = 新值 WHERE strExpreesion
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("update ")+m_strTableName+QString(" set ");
		for (int i = 0; i < strNames.size(); i++)
		{
			sql = sql + strNames.value(i);
			sql = sql + QString(" = '");
			sql = sql + strValues.value(i);
			sql = sql + QString("'");
			if (i != strNames.size()-1)
			{
				sql = sql + QString(" ,");
			}
		}
		if (strExpreesion.size()>0)
		{
			sql = sql + QString(" where ") + strExpreesion;
		}

		bool bResults=query.exec(sql);
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}

}



/* 删除函数.构造SQL删除语句.*/
bool CSQLBase::Delete(QString &strExpreesion)
{

	_WRITE_LOCK_;
	//DELETE FROM 表名称 WHERE 列名称 = 值
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	{
		QSqlQuery query(m_db);
		// QSqlQuery query(QSqlDatabase::database());
		QString sql = QString("delete from ") + m_strTableName ;

		if (strExpreesion.size()>0)
		{
			sql = sql + QString(" where ") + strExpreesion;
		}
		bool bResults=query.exec(sql);
		if(!bResults)
		{
			m_strError=query.lastError().text();
			LOG_INFO("strSql=[%s],m_strError=[%s]",strExpreesion.toStdString().c_str(),m_strError.toStdString().c_str());
			m_db.close();
			return bResults;
		}
		m_db.close();
		return bResults;
	}
}

/* 删除函数.构造SQL删除语句.*/
bool CSQLBase::Delete(QStringList &strKeys,QStringList &strValues)
{
	_WRITE_LOCK_;
	if (strKeys.size() != strValues.size())
	{
		return false;
	}
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	{
		QSqlQuery query(m_db);
		QString sql = QString("delete  from ") + m_strTableName ;
		if (strKeys.size()>0)
		{
			sql=sql	+QString(" where ");
			for (int i = 0; i < strKeys.size(); i++)
			{
				sql = sql + strKeys.value(i);
				sql = sql + QString(" = '");
				sql = sql + strValues.value(i);
				sql = sql + QString("'");
				if (i != strKeys.size()-1)
				{
					sql = sql + QString(" and ");
				}
			}
		}
		bool bResults=query.exec(sql);
		if(!bResults)
		{
			m_strError=query.lastError().text();
		}
		m_db.close();
		return bResults;
	}
}

/* 查找函数.构造SQL查询语句.*/
void CSQLBase::GetValues(QStringList &strReturnValues)
{
	_READ_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return ;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("select * from ") + m_strTableName;
		query.exec(sql);
		while (query.next())
		{
			strReturnValues << query.value(0).toString();
		}
		m_db.close();
		return;
	}
}

/* 查找函数.构造SQL查询语句.*/
void CSQLBase::GetValues(QStringList &strReturnValues,QString &strExpreesion,int nValues)
{
	
	if (!m_db.open())
	{
		m_db.close();
		return ;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("select * from ") + m_strTableName ;
		if (strExpreesion.size()>0)
		{
			sql = sql + QString(" where ") + strExpreesion;
		}
		query.exec(sql);
		while (query.next())
		{
			strReturnValues << query.value(nValues).toString();
		}
		m_db.close();
		return;
	}

}

/* 查找函数.构造SQL查询语句.*/
void CSQLBase::GetValues(QStringList &strName,QStringList &strValues,QString &strExpreesion,int nValues)
{
	_READ_LOCK_;
	if (!m_db.open())
	{
		m_db.close();
		return ;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("select ( ")  ;
		for (int i=0; i < strName.size(); i++)
		{
			sql = sql + strName.value(i);
			if (i != strName.size() - 1)
			{
				sql+=QString(",");
			}
			else
			{

				sql = sql + QString(")");
			}
		}


		sql = sql +(" from ")+ m_strTableName ;
		if (strExpreesion.size()>0)
		{
			sql = sql + QString(" where ") + strExpreesion;
		}
		query.exec(sql);
		while (query.next())
		{
			strValues << query.value(nValues).toString();
		}
		m_db.close();
		return;
	}
}

/* 查找函数.构造SQL查询语句.*/
QQueue < QSqlRecord >  CSQLBase::GetValues(QStringList &strKeys,QStringList &strValues)
{
	_READ_LOCK_;
	QQueue < QSqlRecord >  RecordQueue;
	QSqlRecord SqlRecord;
	RecordQueue.clear();
	if (strKeys.size() != strValues.size())
	{
		return RecordQueue;
	}

	if (!m_db.open())
	{
		m_strError=m_db.lastError().text();
		m_db.close();
		return RecordQueue;
	}

	{
		QSqlQuery query(m_db);
		//QSqlQuery query(QSqlDatabase::database());
		QString sql = QString("select * from ") + m_strTableName ;
		if (strKeys.size()>0)
		{
			sql=sql	+QString(" where ");
			for (int i = 0; i < strKeys.size(); i++)
			{
				sql = sql + strKeys.value(i);
				sql = sql + QString(" = '");
				sql = sql + strValues.value(i);
				sql = sql + QString("'");
				if (i != strKeys.size()-1)
				{
					sql = sql + QString(" and ");
				}
			}
		}
		query.exec(sql);
		while (query.next())
		{
			SqlRecord=query.record();
			RecordQueue.enqueue(SqlRecord);
		}
		m_db.close();
		return RecordQueue;
	}
}



int CSQLBase::dbExecSql( QString strSql,int &rows,int &cols,std::vector < QSqlRecord > &RecordQueue)
{
	_WRITE_LOCK_;
	QSqlRecord SqlRecord;
	rows=0;
	cols=0;
	if (!m_db.open())
	{
		m_db.close();
		return  -1;
	}
	{
		QSqlQuery query(m_db);
		query.exec(strSql);
		while (query.next())
		{
			SqlRecord=query.record();
			RecordQueue.push_back(SqlRecord);
			rows++;
		}
		m_db.close();
		cols=SqlRecord.count();
		return rows;
	}
}

int CSQLBase::TableCount()
{
	_READ_LOCK_;
	int nCount=0;
	if (!m_db.open())
	{
		m_db.close();
		return nCount;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("select count(*) from ") + m_strTableName;
		query.exec(sql);

		while (query.next())
		{
			nCount= query.value(0).toInt();
		}
		m_db.close();

		return nCount;
	}
}

void CSQLBase::InitQstringList(QStringList &strName,QStringList &strValues)
{
	strName.clear();
	strValues.clear();

	strName.append("saveRow");
	strValues.append(":saveRow");

	strName.append("saveColumn");
	strValues.append(":saveColumn");

	strName.append("saveQRNum");
	strValues.append(":saveQRNum");

	strName.append("saveHeight");
	strValues.append(":saveHeight");

	strName.append("saveWeight");
	strValues.append(":saveWeight");

	strName.append("phoneNum");
	strValues.append(":phoneNum");

	strName.append("userName");
	strValues.append(":userName");

}


/* 遍历数据库*/
QQueue < QSqlRecord > CSQLBase::ReadAppData()
{
	_READ_LOCK_;
	QQueue < QSqlRecord >  RecordQueue;
	QSqlRecord SqlRecord;
	if (!m_db.open())
	{
		m_db.close();
		return RecordQueue;
	}
	else
	{
		QSqlQuery query(m_db);
		QString sql = QString("select * from ") + m_strTableName;
		query.exec(sql);
		while (query.next())
		{
			SqlRecord = query.record();
			RecordQueue.enqueue(SqlRecord);
		}
		m_db.close();
		return RecordQueue;
	}
}






