#include "NumKeyBoard.h"

#include <QDebug>


NumKeyBoard::NumKeyBoard(QWidget *parent) :
	QWidget(parent)
{
	this->setupUi(this);
	display->setFocus();
	button_init();

	waitingForOperand = true;
	inputMode = iMode_Normal;
	caps_Lock = false;

	signalMapper = new QSignalMapper(this);
	setMapper();//调用了setMapper函数，英文字母数字键盘集群关联信号和漕
	connectMapper();
	connect(signalMapper, SIGNAL(mapped(const QString&)),
		this, SLOT(setDispText(const QString&)));
	connect(toolButton_enter, SIGNAL(clicked()), this, SLOT(onEnter()));
	connect(toolButton_backspace, SIGNAL(clicked()), this, SLOT(onBackspace()));

	QRegExp regx("[0-9]+$");
	QValidator *validator = new QRegExpValidator(regx, display);
	display->setValidator(validator);
	display->hide();

	connect(display, &QLineEdit::textChanged,this, &NumKeyBoard::on_slot_textChanged);

	display->setMaxLength(6);
}

NumKeyBoard::~NumKeyBoard()
{
	
}
void NumKeyBoard::button_init()
{
	display->setStyleSheet("QLineEdit{font-size:25px;color:rgb(0,0,0);"
		"height:50px;border:2px solid rgb(155,200,33);"
		"border-radius:10px;}");
	toolButton_0->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_1->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_2->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_3->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_4->setStyleSheet("border:2px groove gray;border-radius:10px;"
		" background-color:gray;color:white;font-size:25px");
	toolButton_5->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_6->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_7->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_8->setStyleSheet("border:2px groove gray;border-radius:10px;"
		" background-color:gray;color:white;font-size:25px");
	toolButton_9->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");
	toolButton_backspace->setStyleSheet("border:2px groove gray;border-radius:10px;"
		" background-color:gray;color:white;font-size:25px");
	toolButton_enter->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
		"background-color:gray;color:white;font-size:25px}");


}

void NumKeyBoard::setMapper()
{
	//number
	signalMapper->setMapping(toolButton_0, toolButton_0->text());
	signalMapper->setMapping(toolButton_1, toolButton_1->text());
	signalMapper->setMapping(toolButton_2, toolButton_2->text());
	signalMapper->setMapping(toolButton_3, toolButton_3->text());
	signalMapper->setMapping(toolButton_4, toolButton_4->text());
	signalMapper->setMapping(toolButton_5, toolButton_5->text());
	signalMapper->setMapping(toolButton_6, toolButton_6->text());
	signalMapper->setMapping(toolButton_7, toolButton_7->text());
	signalMapper->setMapping(toolButton_8, toolButton_8->text());
	signalMapper->setMapping(toolButton_9, toolButton_9->text());
	
	
}

void NumKeyBoard::connectMapper()
{
	connect(toolButton_0, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_3, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_4, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_5, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_6, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_7, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_8, SIGNAL(clicked()), signalMapper, SLOT(map()));
	connect(toolButton_9, SIGNAL(clicked()), signalMapper, SLOT(map()));


}

void NumKeyBoard::setDispText(const QString &text)
{
	if (waitingForOperand)
	{
		display->clear();
		waitingForOperand = false;
	}
	display->insert(text);
}

void NumKeyBoard::onEnter()
{
	waitingForOperand = true;
	text = display->text();
	qDebug() << "input" << text;
	emit setvalue(text);
	display->clear();
	this->close();
	//qDebug() << text << endl;

}

void NumKeyBoard::onBackspace()
{
	display->backspace();
}
/*支持鼠标拖拽键盘*/
void NumKeyBoard::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		move(event->globalPos() - dragPosition);
		event->accept();
	}
}

void NumKeyBoard::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
	if (event->button() == Qt::RightButton)
	{
		close();
	}
}

void NumKeyBoard::onInvMode()
{
	if (inputMode == iMode_Normal)
	{
		inputMode = iMode_Passwd;
	}
	else if (inputMode == iMode_Passwd)
	{
		inputMode = iMode_Normal;
	}

	if (inputMode == iMode_Normal)
	{
		display->setEchoMode(QLineEdit::Normal);
	}
	else if (inputMode == iMode_Passwd)
	{
		display->setEchoMode(QLineEdit::Password);
	}
}

void NumKeyBoard::on_slot_textChanged(const QString & text)
{


	for (int i=0;i<text.length();i++)
	{
		QString num = text.at(i);
		QString lcdname = QString("lcdNumber_%1").arg(i+1);
		QLCDNumber *db = this->findChild<QLCDNumber *>(lcdname);
		num += " ";
		if (db!=nullptr)
		{
			db->display(num);				
		}
	}
	for (int i = text.length(); i < 6; i++)
	{
		QString lcdname = QString("lcdNumber_%1").arg(i+1);
		QLCDNumber *db = this->findChild<QLCDNumber *>(lcdname);
		if (db != nullptr)
		{
			QString num = "0";
			num += " ";
			db->display(num);
		}
	}
}
