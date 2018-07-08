#include "ControlSql.h"

ControlSql::ControlSql(QObject *parent)
	: CSQLBase(parent)
{
	InitSQL();
	Read_AppList();
}

ControlSql::~ControlSql()
{
}

void ControlSql::InitSQL()
{
	QString strError;

	SetTableName("AppDb", "AppInfo");
	bool bResults = opendatabase();
	QStringList strExpression;

	strExpression.append("id integer primary key DEFAULT NULL");
	strExpression.append("saveRow integer DEFAULT 0");
	strExpression.append("saveColumn integer DEFAULT 0");
	strExpression.append("saveQRNum integer");
	strExpression.append("saveHeight    text DEFAULT '0'");
	strExpression.append("saveWeight    text DEFAULT '0'");
	strExpression.append("phoneNum      text DEFAULT ''");
	strExpression.append("userName      text DEFAULT ''");
	strExpression.append("saveDateTime  text DEFAULT ''");
	strExpression.append("getDateTime   text DEFAULT ''");
	strExpression.append("useState      int DEFAULT 0");
	CreatTable("AppInfo", strExpression);

}



//读取数据库列表信息
void ControlSql::Read_AppList()
{

	QQueue < QSqlRecord > RecordQueue;
	QSqlRecord szRecord;
	RecordQueue = ReadAppData();
	AppInfo info = {};
	int nSize = RecordQueue.size();
	while (nSize > 0)
	{
		szRecord = RecordQueue.dequeue();
		nSize = RecordQueue.size();
		WriteValues(szRecord, info);
		m_AppList.append(info);		
	}
}
bool ControlSql::Get_App_By_QRnum(int nQRnum, AppInfo& info)
{
	_READ_LOCK_;
	QList<AppInfo>::iterator it;
	for (it = m_AppList.begin(); it != m_AppList.end(); it++)
	{
		if (it->saveQRNum == nQRnum)
		{
			info=*it ;
			return true;
		}
	}
	return false;
}
bool ControlSql::Get_App_By_Point(int nRow, int nColoumn, AppInfo& Info)
{
	_READ_LOCK_;
	QList<AppInfo>::iterator it;
	for (it = m_AppList.begin(); it != m_AppList.end(); it++)
	{
		if (it->savePoint.x() == nRow  && it->savePoint.y() == nColoumn)
		{
			Info = *it;
			return true;
		}
	}
	return false;

}
//新增一个APP
void ControlSql::Add_AppInfo(AppInfo &info)
{
	_WRITE_LOCK_;
	QStringList strName, strValues;
	QStringList strResults;
	QString strSql = QString("saveQRNum = %1 where").arg(info.saveQRNum);
	GetValues(strResults, strSql, 0);
	if (strResults.size() > 0)
	{	
		Update(info, strSql);
	}
	else
	{	
		Insert(info);	
	}
	QList<AppInfo>::iterator it;
	for (it = m_AppList.begin(); it != m_AppList.end(); it++)
	{
		if (it->saveQRNum == info.saveQRNum)
		{
			*it = info;
			return;
		}
	}
	m_AppList.append(info);

}

//更新一个APP
void ControlSql::Update_AppInfo(AppInfo &info)
{
	_WRITE_LOCK_;
	QStringList strName, strValues;
	QStringList strResults;
	QString strSql = QString("saveQRNum = %1").arg(info.saveQRNum);
	GetValues(strResults, strSql, 0);
	if (strResults.size() > 0)
	{
		Update(info, strSql);
	}
	else
	{
		Insert(info);
	}
	QList<AppInfo>::iterator it;
	for (it = m_AppList.begin(); it != m_AppList.end(); it++)
	{
		if (it->saveQRNum == info.saveQRNum)
		{
			*it = info;
			return;
		}
	}
	m_AppList.append(info);
}

//删除一个APP
void ControlSql::Delete_AppInfo(AppInfo &info)
{
	_WRITE_LOCK_;
	QString strSql;

	//ID内存分配的字段 可以根据ID去删除
	strSql = QString("saveQRNum = %1").arg(info.saveQRNum);	
	bool bResults = Delete(strSql);

	QList<AppInfo>::iterator it;
	for (it = m_AppList.begin(); it != m_AppList.end();)
	{
		if (it->saveQRNum == info.saveQRNum) //从List 删除 并删除文件夹
		{
			it = m_AppList.erase(it);
			return;
		}
		if (it->saveQRNum != info.saveQRNum && it != m_AppList.end())
		{
			it++;
		}
		if (it == m_AppList.end())
		{
			return ;
		}
	}
	return;
}

void ControlSql::WriteValues(QSqlRecord & query, AppInfo & info)
{
	info.savePoint.setX( query.value("saveRow").toInt());
	info.savePoint.setY(query.value("saveColumn").toInt());
	info.saveQRNum = query.value("saveQRNum").toInt();
	info.saveHeight = query.value("saveHeight").toString();

	info.saveWeight = query.value("saveWeight").toString();
	info.phoneNum = query.value("phoneNum").toString();

	info.userName = query.value("userName").toString();
	info.saveDateTime = query.value("saveDateTime").toString();
	info.getDateTime = query.value("getDateTime").toString();
	info.useState = query.value("useState").toInt();
}

/* 插入函数. 构造SQL插入语句.*/
bool ControlSql::Insert(AppInfo &info)
{

	QStringList strName, strValues;

	InitQstringList(strName, strValues);

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

		for (i = 0; i < strName.size(); i++)
		{
			sql = sql + strName.value(i);
			if (i != strName.size() - 1)
			{
				sql += QString(",");
			}
			else
			{

				sql = sql + QString(")");
			}
		}

		sql = sql + QString(" values (");

		for (i = 0; i < strValues.size(); i++)
		{
			sql = sql + strValues.value(i);
			if (i != strValues.size() - 1)
			{
				sql = sql + QString(",");
			}
		}

		sql = sql + QString(")");

		query.prepare(sql);
		BindValues(query, info);

		bool bResults = query.exec();
		if (!bResults)
		{
			m_strError = query.lastError().text();
		}
		m_db.close();
		return bResults;
	}

}

/* 修改函数. 构造SQL修改语句.*/
bool ControlSql::Update(AppInfo &info, QString &strExpreesion)
{
	
	//UPDATE 表名称 SET 列名称 = 新值 WHERE strExpreesion
	QStringList strNames, strValues;

	InitQstringList(strNames, strValues);

	if (strNames.size() != strValues.size())
	{
		return false;
	}

	//UPDATE 表名称 SET 列名称 = 新值 WHERE 列名称 = 某值
	if (!m_db.open())
	{
		m_db.close();
		return false;
	}
	{
		QSqlQuery query(m_db);
		//QSqlQuery query(QSqlDatabase::database());
		QString sql = QString("update ") + m_strTableName + QString(" set ");
		for (int i = 0; i < strNames.size(); i++)
		{
			sql = sql + strNames.value(i);
			sql = sql + QString(" = ");
			sql = sql + strValues.value(i);

			if (i != strNames.size() - 1)
			{
				sql = sql + QString(" ,");
			}
		}
		if (strExpreesion.size() > 0)
		{
			sql = sql + QString(" where ") + strExpreesion;
		}
		query.prepare(sql);
		BindValues(query, info);
		bool bResults = query.exec();
		if (!bResults)
		{
			m_strError = query.lastError().text();
		}
		m_db.close();
		return bResults;
	}
}


void ControlSql::BindValues(QSqlQuery &query, AppInfo info)
{

	query.bindValue(":saveRow", info.savePoint.x());

	query.bindValue(":saveColumn", info.savePoint.y());

	query.bindValue(":saveQRNum", info.saveQRNum);

	query.bindValue(":saveHeight", info.saveHeight);

	query.bindValue(":saveWeight", info.saveWeight);

	query.bindValue(":userName", info.userName);

	query.bindValue(":saveDateTime", info.saveDateTime);

	query.bindValue(":getDateTime", info.getDateTime);

	query.bindValue(":useState", info.useState);
}