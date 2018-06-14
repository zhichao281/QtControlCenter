/********************************************************************************
** Form generated from reading UI file 'NumKeyBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMKEYBOARD_H
#define UI_NUMKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NumKeyBoard
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_back;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_home;
    QWidget *widget_input;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *display;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_num;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_backspace;
    QToolButton *toolButton_0;
    QToolButton *toolButton_enter;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *NumKeyBoard)
    {
        if (NumKeyBoard->objectName().isEmpty())
            NumKeyBoard->setObjectName(QStringLiteral("NumKeyBoard"));
        NumKeyBoard->resize(1024, 768);
        NumKeyBoard->setMinimumSize(QSize(0, 0));
        NumKeyBoard->setStyleSheet(QString::fromUtf8("QWidget#NumKeyBoard\n"
"{\n"
"	\n"
"	border-image: url(:/Image/Resources/Image/img_bg.png);\n"
"}\n"
"QToolButton\n"
"{\n"
"min-height:80px;\n"
"min-width:80px;\n"
"max-height:80px;\n"
"max-width:80px;\n"
"	font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QLCDNumber\n"
"{\n"
"min-height:100px;\n"
"min-width:100px;\n"
"max-height:100px;\n"
"max-width:100px;\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(NumKeyBoard);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(NumKeyBoard);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 95));
        widget_title->setMaximumSize(QSize(16777215, 95));
        horizontalLayout_4 = new QHBoxLayout(widget_title);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(25, 10, 25, 0);
        btn_back = new QPushButton(widget_title);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        btn_back->setFont(font);
        btn_back->setStyleSheet(QLatin1String("#btn_back\n"
"{\n"
"min-width:55px;\n"
"max-width:55px;\n"
"min-height:50px;\n"
"max-height:50px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_back{border-image: url(:/Image/Resources/Image/btn_Return_nor.png);}\n"
"#btn_back:hover{border-image:url(:/Image/Resources/Image/btn_Return_sele.png);}\n"
"#btn_back:pressed{border-image:url(:/Image/Resources/Image/btn_Return_press.png);}"));

        horizontalLayout_4->addWidget(btn_back);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_title->setFont(font1);
        label_title->setStyleSheet(QString::fromUtf8("\n"
"min-width:379px;\n"
"max-width:379px;\n"
"min-height:71px;\n"
"max-height:71px;\n"
"border-image: url(:/Image/Resources/Image/\350\257\267\350\276\223\345\205\245\345\217\226\344\273\266\347\240\201.png);"));

        horizontalLayout_4->addWidget(label_title);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_home = new QPushButton(widget_title);
        btn_home->setObjectName(QStringLiteral("btn_home"));
        btn_home->setStyleSheet(QLatin1String("#btn_home\n"
"{\n"
"min-width:55px;\n"
"max-width:55px;\n"
"min-height:50px;\n"
"max-height:50px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_home{border-image: url(:/Image/Resources/Image/btn_home_nor.png);}\n"
"#btn_home:hover{border-image:url(:/Image/Resources/Image/btn_home_sele.png);}\n"
"#btn_home:pressed{border-image:url(:/Image/Resources/Image/btn_home_press.png);}"));

        horizontalLayout_4->addWidget(btn_home);


        verticalLayout->addWidget(widget_title);

        widget_input = new QWidget(NumKeyBoard);
        widget_input->setObjectName(QStringLiteral("widget_input"));
        widget_input->setMinimumSize(QSize(0, 0));
        widget_input->setMaximumSize(QSize(16777215, 200));
        horizontalLayout_2 = new QHBoxLayout(widget_input);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 35, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        display = new QLineEdit(widget_input);
        display->setObjectName(QStringLiteral("display"));
        display->setMaximumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        display->setFont(font2);

        horizontalLayout_3->addWidget(display);

        label_1 = new QLabel(widget_input);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setStyleSheet(QString::fromUtf8("\n"
"#label_1\n"
"{\n"
"min-width:85px;\n"
"max-width:85px;\n"
"min-height:94px;\n"
"max-height:94px;\n"
"border-radius: 12;\n"
"color: rgb(122, 118, 117);\n"
"	font: 64px \"\351\273\221\344\275\223\";\n"
"}\n"
"#label_1{border-image:url(:/Image/Resources/Image/label_Inputbox_sele.png)}"));
        label_1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_1);

        label_2 = new QLabel(widget_input);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"#label_2\n"
"{\n"
"min-width:85px;\n"
"max-width:85px;\n"
"min-height:94px;\n"
"max-height:94px;\n"
"border-radius: 12;\n"
"color: rgb(122, 118, 117);\n"
"	font: 64px \"\351\273\221\344\275\223\";\n"
"}\n"
"#label_2{border-image:url(:/Image/Resources/Image/label_Inputbox_sele.png)}"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(widget_input);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"#label_3\n"
"{\n"
"min-width:85px;\n"
"max-width:85px;\n"
"min-height:94px;\n"
"max-height:94px;\n"
"border-radius: 12;\n"
"color: rgb(122, 118, 117);\n"
"	font: 64px \"\351\273\221\344\275\223\";\n"
"}\n"
"#label_3{border-image:url(:/Image/Resources/Image/label_Inputbox_sele.png)}"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(widget_input);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"#label_4\n"
"{\n"
"min-width:85px;\n"
"max-width:85px;\n"
"min-height:94px;\n"
"max-height:94px;\n"
"border-radius: 12;\n"
"color: rgb(122, 118, 117);\n"
"	font: 64px \"\351\273\221\344\275\223\";\n"
"}\n"
"#label_4{border-image:url(:/Image/Resources/Image/label_Inputbox_sele.png)}"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        label_5 = new QLabel(widget_input);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"#label_5\n"
"{\n"
"min-width:85px;\n"
"max-width:85px;\n"
"min-height:94px;\n"
"max-height:94px;\n"
"border-radius: 12;\n"
"color: rgb(122, 118, 117);\n"
"	font: 64px \"\351\273\221\344\275\223\";\n"
"}\n"
"#label_5{border-image:url(:/Image/Resources/Image/label_Inputbox_sele.png)}"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        label_6 = new QLabel(widget_input);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"#label_6\n"
"{\n"
"min-width:85px;\n"
"max-width:85px;\n"
"min-height:94px;\n"
"max-height:94px;\n"
"border-radius: 12;\n"
"color: rgb(122, 118, 117);\n"
"	font: 64px \"\351\273\221\344\275\223\";\n"
"}\n"
"#label_6{border-image:url(:/Image/Resources/Image/label_Inputbox_sele.png)}"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        horizontalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(widget_input);

        widget_num = new QWidget(NumKeyBoard);
        widget_num->setObjectName(QStringLiteral("widget_num"));
        widget_num->setMinimumSize(QSize(0, 100));
        horizontalLayout = new QHBoxLayout(widget_num);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 35, 0, 35);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(widget_num);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(60);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_1 = new QToolButton(widget);
        toolButton_1->setObjectName(QStringLiteral("toolButton_1"));
        toolButton_1->setMinimumSize(QSize(108, 108));
        toolButton_1->setMaximumSize(QSize(108, 108));
        toolButton_1->setStyleSheet(QLatin1String("#toolButton_1\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_1{border-image: url(:/Image/Resources/Image/1_nor.png);}\n"
"#toolButton_1:hover{border-image:url(:/Image/Resources/Image/1_nor.png);}\n"
"#toolButton_1:pressed{border-image:url(:/Image/Resources/Image/1_press.png);}"));

        gridLayout->addWidget(toolButton_1, 0, 0, 1, 1);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(108, 108));
        toolButton_2->setMaximumSize(QSize(108, 108));
        toolButton_2->setStyleSheet(QLatin1String("#toolButton_2\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_2{border-image: url(:/Image/Resources/Image/2_nor.png);}\n"
"#toolButton_2:hover{border-image:url(:/Image/Resources/Image/2_nor.png);}\n"
"#toolButton_2:pressed{border-image:url(:/Image/Resources/Image/2_press.png);}"));

        gridLayout->addWidget(toolButton_2, 0, 1, 1, 1);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(108, 108));
        toolButton_4->setMaximumSize(QSize(108, 108));
        toolButton_4->setStyleSheet(QLatin1String("#toolButton_4\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_4{border-image: url(:/Image/Resources/Image/4_nor.png);}\n"
"#toolButton_4:hover{border-image:url(:/Image/Resources/Image/4_nor.png);}\n"
"#toolButton_4:pressed{border-image:url(:/Image/Resources/Image/4_press.png);}"));

        gridLayout->addWidget(toolButton_4, 1, 0, 1, 1);

        toolButton_5 = new QToolButton(widget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(108, 108));
        toolButton_5->setMaximumSize(QSize(108, 108));
        toolButton_5->setStyleSheet(QLatin1String("#toolButton_5\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_5{border-image: url(:/Image/Resources/Image/5_nor.png);}\n"
"#toolButton_5:hover{border-image:url(:/Image/Resources/Image/5_nor.png);}\n"
"#toolButton_5:pressed{border-image:url(:/Image/Resources/Image/5_press.png);}"));

        gridLayout->addWidget(toolButton_5, 1, 1, 1, 1);

        toolButton_6 = new QToolButton(widget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(108, 108));
        toolButton_6->setMaximumSize(QSize(108, 108));
        toolButton_6->setStyleSheet(QLatin1String("#toolButton_6\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_6{border-image: url(:/Image/Resources/Image/6_nor.png);}\n"
"#toolButton_6:hover{border-image:url(:/Image/Resources/Image/6_nor.png);}\n"
"#toolButton_6:pressed{border-image:url(:/Image/Resources/Image/6_press.png);}"));

        gridLayout->addWidget(toolButton_6, 1, 2, 1, 1);

        toolButton_7 = new QToolButton(widget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(108, 108));
        toolButton_7->setMaximumSize(QSize(108, 108));
        toolButton_7->setStyleSheet(QLatin1String("#toolButton_7\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_7{border-image: url(:/Image/Resources/Image/7_nor.png);}\n"
"#toolButton_7:hover{border-image:url(:/Image/Resources/Image/7_nor.png);}\n"
"#toolButton_7:pressed{border-image:url(:/Image/Resources/Image/7_press.png);}"));

        gridLayout->addWidget(toolButton_7, 2, 0, 1, 1);

        toolButton_8 = new QToolButton(widget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(108, 108));
        toolButton_8->setMaximumSize(QSize(108, 108));
        toolButton_8->setStyleSheet(QLatin1String("#toolButton_8\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_8{border-image: url(:/Image/Resources/Image/8_nor.png);}\n"
"#toolButton_8:hover{border-image:url(:/Image/Resources/Image/8_nor.png);}\n"
"#toolButton_8:pressed{border-image:url(:/Image/Resources/Image/8_press.png);}"));

        gridLayout->addWidget(toolButton_8, 2, 1, 1, 1);

        toolButton_9 = new QToolButton(widget);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setMinimumSize(QSize(108, 108));
        toolButton_9->setMaximumSize(QSize(108, 108));
        toolButton_9->setStyleSheet(QLatin1String("#toolButton_9\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_9{border-image: url(:/Image/Resources/Image/9_nor.png);}\n"
"#toolButton_9:hover{border-image:url(:/Image/Resources/Image/9_nor.png);}\n"
"#toolButton_9:pressed{border-image:url(:/Image/Resources/Image/9_press.png);}"));

        gridLayout->addWidget(toolButton_9, 2, 2, 1, 1);

        toolButton_backspace = new QToolButton(widget);
        toolButton_backspace->setObjectName(QStringLiteral("toolButton_backspace"));
        toolButton_backspace->setMinimumSize(QSize(108, 108));
        toolButton_backspace->setMaximumSize(QSize(108, 108));
        toolButton_backspace->setStyleSheet(QLatin1String("#toolButton_backspace\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"}\n"
"#toolButton_backspace{border-image: url(:/Image/Resources/Image/btn_keyboard2_nor.png);}\n"
"#toolButton_backspace:hover{border-image:url(:/Image/Resources/Image/btn_keyboard2_nor.png);}\n"
"#toolButton_backspace:pressed{border-image:url(:/Image/Resources/Image/btn_keyboard2_sele.png);}"));

        gridLayout->addWidget(toolButton_backspace, 3, 0, 1, 1);

        toolButton_0 = new QToolButton(widget);
        toolButton_0->setObjectName(QStringLiteral("toolButton_0"));
        toolButton_0->setMinimumSize(QSize(108, 108));
        toolButton_0->setMaximumSize(QSize(108, 108));
        toolButton_0->setStyleSheet(QLatin1String("#toolButton_0\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_0{border-image: url(:/Image/Resources/Image/0_nor.png);}\n"
"#toolButton_0:hover{border-image:url(:/Image/Resources/Image/0_nor.png);}\n"
"#toolButton_0:pressed{border-image:url(:/Image/Resources/Image/0_press.png);}"));

        gridLayout->addWidget(toolButton_0, 3, 1, 1, 1);

        toolButton_enter = new QToolButton(widget);
        toolButton_enter->setObjectName(QStringLiteral("toolButton_enter"));
        toolButton_enter->setMinimumSize(QSize(108, 108));
        toolButton_enter->setMaximumSize(QSize(108, 108));
        toolButton_enter->setStyleSheet(QLatin1String("#toolButton_enter\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"}\n"
"#toolButton_enter{border-image: url(:/Image/Resources/Image/btn_keyboard3_nor.png);}\n"
"#toolButton_enter:hover{border-image:url(:/Image/Resources/Image/btn_keyboard3_nor.png);}\n"
"#toolButton_enter:pressed{border-image:url(:/Image/Resources/Image/btn_keyboard3_sele.png);}"));

        gridLayout->addWidget(toolButton_enter, 3, 2, 1, 1);

        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(108, 108));
        toolButton_3->setMaximumSize(QSize(108, 108));
        toolButton_3->setStyleSheet(QLatin1String("#toolButton_3\n"
"{\n"
"min-width:108px;\n"
"max-width:108px;\n"
"min-height:108px;\n"
"max-height:108px;\n"
"border-radius: 10px;\n"
"color: rgba(255, 255, 255,0);\n"
"}\n"
"#toolButton_3{border-image: url(:/Image/Resources/Image/3_nor.png);}\n"
"#toolButton_3:hover{border-image:url(:/Image/Resources/Image/3_nor.png);}\n"
"#toolButton_3:pressed{border-image:url(:/Image/Resources/Image/3_press.png);}"));

        gridLayout->addWidget(toolButton_3, 0, 2, 1, 1);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_num);


        retranslateUi(NumKeyBoard);

        QMetaObject::connectSlotsByName(NumKeyBoard);
    } // setupUi

    void retranslateUi(QWidget *NumKeyBoard)
    {
        NumKeyBoard->setWindowTitle(QApplication::translate("NumKeyBoard", "NumKeyBoard", Q_NULLPTR));
        btn_back->setText(QString());
        label_title->setText(QString());
        btn_home->setText(QString());
        display->setText(QString());
        label_1->setText(QApplication::translate("NumKeyBoard", "-", Q_NULLPTR));
        label_2->setText(QApplication::translate("NumKeyBoard", "-", Q_NULLPTR));
        label_3->setText(QApplication::translate("NumKeyBoard", "-", Q_NULLPTR));
        label_4->setText(QApplication::translate("NumKeyBoard", "-", Q_NULLPTR));
        label_5->setText(QApplication::translate("NumKeyBoard", "-", Q_NULLPTR));
        label_6->setText(QApplication::translate("NumKeyBoard", "-", Q_NULLPTR));
        toolButton_1->setText(QApplication::translate("NumKeyBoard", "1", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("NumKeyBoard", "2", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("NumKeyBoard", "4", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("NumKeyBoard", "5", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("NumKeyBoard", "6", Q_NULLPTR));
        toolButton_7->setText(QApplication::translate("NumKeyBoard", "7", Q_NULLPTR));
        toolButton_8->setText(QApplication::translate("NumKeyBoard", "8", Q_NULLPTR));
        toolButton_9->setText(QApplication::translate("NumKeyBoard", "9", Q_NULLPTR));
        toolButton_backspace->setText(QString());
        toolButton_0->setText(QApplication::translate("NumKeyBoard", "0", Q_NULLPTR));
        toolButton_enter->setText(QString());
        toolButton_3->setText(QApplication::translate("NumKeyBoard", "3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NumKeyBoard: public Ui_NumKeyBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMKEYBOARD_H
