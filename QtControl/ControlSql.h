#pragma once
#include "Base/SQLBase.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QObject>
#include <QList>
#include <QVector>
#include "define.h"
#include "include/HSingleton/HSingleton.h"


class ControlSql : public CSQLBase
{
	Q_OBJECT

public:
	ControlSql(QObject *parent=nullptr);
	~ControlSql();

public:

	void  InitSQL();

	/*插入函数. 构造SQL插入语句.
	insert into (info.names,info.names,info.names) values (info.values,info.values,info.values)
	*/
	bool Insert(AppInfo &info);

	/* 修改函数. 构造SQL修改语句.
	UPDATE 表名称 SET (info.names,info.names,info.names) = (info.values,info.values,info.values) WHERE strExpreesion
	*/
	bool Update(AppInfo &info, QString &strExpreesion);

	/*数据绑定*/
	void BindValues(QSqlQuery &query, AppInfo info);

	void Read_AppList();
	//新增一个APP
	void Add_AppInfo(AppInfo &info);
	//更新一个APP
	void Update_AppInfo(AppInfo &info);
	//删除一个APP
	void Delete_AppInfo(AppInfo &info);


	bool Get_App_By_QRnum(int nQRnum, AppInfo& Info);

	bool Get_App_By_Point(int nRow,int nColoumn, AppInfo& Info);

	/*把获取的信息 写成 info信息
	query  返回的数据库结果集  info:写成info信息
	*/
	void WriteValues(QSqlRecord &query, AppInfo &info);
public:
	QList<AppInfo>   m_AppList;


	QVector<QPoint>   vecAppId;	//存在的ID值
};

#define gblControlSql   HSingletonTemplatePtr<ControlSql>::get()