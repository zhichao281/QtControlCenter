#ifndef SQLBASE_H
#define SQLBASE_H
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QObject>

#include <QString>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QQueue>


#include <QReadWriteLock>

#include "log/log_deffine.h"

#include "Lock_Tool.h"


/*
NOT NULL - 非空 
UNIQUE - 唯一 
PRIMARY KEY - 主键 
FOREIGN KEY - 外键 
CHECK - 条件检查 
DEFAULT - 默认
*/


class  CSQLBase : public QObject
{
	Q_OBJECT
public:
	explicit CSQLBase(QObject *parent = 0);
	~CSQLBase();

	/* 设置数据库名.*/
	void SetTableName(QString dbName,QString strTableName);

	/* 打开数据库.*/
	bool opendatabase();

	/* 创建表格.

	CREAT TABLE IF NOT EXISTS + 表名(strTableName)  + (strExpreesion,strExpreesion,strExpreesion)
	*/
	bool CreatTable(QString strTableName, QStringList strExpreesion);

	/* 创建表格.*/
	bool CreatTableEx(QString strTableName, QStringList strExpreesion);

	/* 创建表格.
	CREAT TABLE IF NOT EXISTS + (表名)strTableName  + strExpreesion
	*/
	bool CreatTable(QString strTableName,QString strExpreesion);

	/* 重命名表格.
	ALTER TABLE +旧表名+ RENAME TO + strTableName (表名) 
	*/
	bool RenameTable(QString strTableName);

	/* 表格某列是否存在.
	//ALTER TABLE 表名 ADD COLUMN + strColumnName (列名 数据类型 限定符)
	*/
	bool TableIsColumnExist(QString &strColumnName);

	/* 表格新增一列.
	//ALTER TABLE 表名 ADD COLUMN + strExpreesion (列名 数据类型 限定符)
	*/
	bool TableAddColumn(QString &strExpreesion);

	/* 删除表格.
	 删除表 - DROP TABLE +strTableName (表名)
	*/
	bool DropTable(QString strTableName);

	/* 插入函数. 构造SQL插入语句.
	insert into (names,names,names) values (values,values,values)
	*/
	bool Insert(QStringList &strNames,QStringList &strValues);



	/* 修改函数. 构造SQL修改语句.
	UPDATE 表名称 SET (names,names,names) = (values,values,values) WHERE strExpreesion
	*/
	bool Update(QStringList &strNames,QStringList &strValues, QString &strExpreesion);



	/* 删除函数.构造SQL删除语句.
	//DELETE FROM 表名称 WHERE strExpreesion
	*/
	bool Delete(QString &strExpreesion);

	/* 删除函数.构造SQL删除语句.
	//DELETE FROM 表名称 WHERE strKeys =strValues and strKeys =strValues
	*/
	bool Delete(QStringList &strKeys,QStringList &strValues);

	/*执行数据库语言：select，insert，update,delete,也可以执行存储过程和存储函数.
	输入strExpreesion ：语句
	*/
	BOOL dbExecSql(QString strExpreesion);

	/* 查找函数.构造SQL查询语句.
	select * from 表名称 
	返回 第一列信息
	*/
	void GetValues(QStringList &strReturnValues);

	/* 查找函数.构造SQL查询语句.
	select * from 表名称 + where + strExpreesion 
	返回 第nValues列信息
	*/
	void GetValues(QStringList &strReturnValues,QString &strExpreesion,int nValues);

	/* 查找函数.构造SQL查询语句.*/
	void GetValues(QStringList &strName,QStringList &strValues,QString &strExpreesion,int nValues);

	/* 查找函数.构造SQL查询语句.
	select * from 表名称 + where  key = values ,key= values  ,如果不需查询条件 strKeys.size为0
	返回结果集
	*/
	QQueue < QSqlRecord >  GetValues(QStringList &strKeys,QStringList &strValues);

	/* 查找函数.查询表格行数.*/
	int TableCount();

	/* 初始化数据.*/
	void InitQstringList(QStringList &strName,QStringList &strValues);




	/*执行数据库语言：select，insert，update,delete,也可以执行存储过程和存储函数.
	strSql：输入语句  rows 输出结果集的最大行数
	cols： 输出结果集的最大列数RecordQueue：输出结果集
	返回：	TURE: 执行成功
	 False:失败
	*/
	int dbExecSql( QString strSql,int &rows,int &cols,std::vector< QSqlRecord > &pRecordQueue);


	QQueue < QSqlRecord > ReadAppData();

public:
	QSqlTableModel	*model;
	QSqlDatabase	m_db;
	QString			m_strTableName;			//表格名
	QString			m_strDbName;		    //数据库名
	QString         m_strError;
	//QReadWriteLock m_mutex;
	 


	_LOCK_KEY_;
};







#endif // SQLBASE_H
