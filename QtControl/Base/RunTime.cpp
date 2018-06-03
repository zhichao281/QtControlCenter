#include <QString>
#include "RunTime.h"

#include "myhelper.h"


/*
*	Function:		CRunTime
*	Explanation:	构造
*/
CRunTime::CRunTime()
{
	Clear();
}

/*
*	Function:		~CRunTime
*	Explanation:	析构
*/
CRunTime::~CRunTime()
{
}


/**
* 函数功能说明：清空
* by Maga 2016-7-12
*/
void CRunTime::Clear()
{

	PortName = "COM1";
	BaudRate = 9600;
	DataBit = 8;
	Parity = "奇";
	StopBit = 1;
	HexSend = false;
	HexReceive = false;
	Debug = false;
	AutoClear = false;

	AutoSend = false;
	SendInterval = 1000;
	AutoSave = false;
	SaveInterval = 5000;

	SendFileName = "send.txt";
	DeviceFileName = "device.txt";

	Mode = "Tcp_Client";
	ServerIP = "127.0.0.1";
	ServerPort = 6000;
	ListenPort = 6000;
	SleepTime = 100;
	AutoConnect = true;

	strComputerUrl = "www.baidu.com";
}



void CRunTime::ReadConfig()
{
    if (!CheckConfig()) 
	{
        return;
    }

    QString fileName = QString("%1/%2_Config.ini").arg(AppPath).arg(AppName);
    QSettings set(fileName, QSettings::IniFormat);

    set.beginGroup("ComConfig");
	PortName = set.value("PortName").toString();
    BaudRate = set.value("BaudRate").toInt();
    DataBit = set.value("DataBit").toInt();
    Parity = set.value("Parity").toString();
    StopBit = set.value("StopBit").toInt();

    HexSend = set.value("HexSend").toBool();
    HexReceive = set.value("HexReceive").toBool();
    Debug = set.value("Debug").toBool();
    AutoClear = set.value("AutoClear").toBool();

    AutoSend = set.value("AutoSend").toBool();
    SendInterval = set.value("SendInterval").toInt();
    AutoSave = set.value("AutoSave").toBool();
    SaveInterval = set.value("SaveInterval").toInt();

    SendFileName = set.value("SendFileName").toString();
    DeviceFileName = set.value("DeviceFileName").toString();
    set.endGroup();

    set.beginGroup("NetConfig");
    Mode = set.value("Mode").toString();
    ServerIP = set.value("ServerIP").toString();
    ServerPort = set.value("ServerPort").toInt();
    ListenPort = set.value("ListenPort").toInt();
    SleepTime = set.value("SleepTime").toInt();
    AutoConnect = set.value("AutoConnect").toBool();
    set.endGroup();


	set.beginGroup("AppConfig");
	strComputerUrl = set.value("ComputerUrl").toString();
	set.endGroup();
}

void CRunTime::WriteConfig()
{
    QString fileName = QString("%1/%2_Config.ini").arg(AppPath).arg(AppName);
    QSettings set(fileName, QSettings::IniFormat);

    set.beginGroup("ComConfig");
    set.setValue("PortName", PortName);
    set.setValue("BaudRate", BaudRate);
    set.setValue("DataBit", DataBit);
    set.setValue("Parity", Parity);
    set.setValue("StopBit", StopBit);

    set.setValue("HexSend", HexSend);
    set.setValue("HexReceive", HexReceive);
    set.setValue("Debug", Debug);
    set.setValue("AutoClear", AutoClear);

    set.setValue("AutoSend", AutoSend);
    set.setValue("SendInterval", SendInterval);
    set.setValue("AutoSave", AutoSave);
    set.setValue("SaveInterval", SaveInterval);

    set.setValue("SendFileName", SendFileName);
    set.setValue("DeviceFileName", DeviceFileName);
    set.endGroup();

    set.beginGroup("NetConfig");
    set.setValue("Mode", Mode);
    set.setValue("ServerIP", ServerIP);
    set.setValue("ServerPort", ServerPort);
    set.setValue("ListenPort", ListenPort);
    set.setValue("SleepTime", SleepTime);
    set.setValue("AutoConnect", AutoConnect);
	set.endGroup();
	set.beginGroup("AppConfig");
	set.setValue("ComputerUrl", strComputerUrl);
	
    set.endGroup();
}

void CRunTime::NewConfig()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    CRunTime::Parity = CRunTime::Parity.toLatin1();
#endif
    WriteConfig();
}

bool CRunTime::CheckConfig()
{
    QString fileName = QString("%1/%2_Config.ini").arg(AppPath).arg(AppName);

    //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
    QFile file(fileName);

    if (file.size() == 0) {
        NewConfig();
        return false;
    }

    //如果配置文件不完整,则以初始值继续运行,并生成配置文件
    if (file.open(QFile::ReadOnly)) {
        bool ok = true;

        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            QStringList list = line.split("=");

            if (list.count() == 2) {
                if (list.at(1) == "") {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            NewConfig();
            return false;
        }
    } else {
        NewConfig();
        return false;
    }

    return true;
}

void CRunTime::WriteError(QString str)
{
    QString fileName = QString("%1/%2_Error_%3.txt").arg(AppPath).arg(AppName).arg(QDATE);
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text);
    QTextStream stream(&file);
    stream << DATETIME << "  " << str << "\n";
}

void CRunTime::NewDir(QString dirName)
{
    //如果路径中包含斜杠字符则说明是绝对路径
    //linux系统路径字符带有 /  windows系统 路径字符带有 :/
    if (!dirName.startsWith("/") && !dirName.contains(":/")) {
        dirName = QString("%1/%2").arg(AppPath).arg(dirName);
    }

    QDir dir(dirName);

    if (!dir.exists()) {
        dir.mkpath(dirName);
    }
}
