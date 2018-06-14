/********************************************************************************
** Form generated from reading UI file 'CMessage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMESSAGE_H
#define UI_CMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMessage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btn_back;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_title_3;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *btn_home;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_hide;
    QWidget *widget_timer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_gif;
    QLabel *label_timer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_OK;
    QSpacerItem *verticalSpacer;
    QWidget *widget_return;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_title_2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_hide_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_return;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *CMessage)
    {
        if (CMessage->objectName().isEmpty())
            CMessage->setObjectName(QStringLiteral("CMessage"));
        CMessage->resize(1297, 973);
        CMessage->setStyleSheet(QLatin1String("QWidget#widget_main\n"
"{\n"
"border-image: url(:/Image/Resources/Image/img_bg.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(CMessage);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(CMessage);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        verticalLayout_2 = new QVBoxLayout(widget_main);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_title = new QWidget(widget_main);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 95));
        widget_title->setMaximumSize(QSize(16777215, 95));
        horizontalLayout_7 = new QHBoxLayout(widget_title);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(25, 10, 25, 0);
        btn_back = new QPushButton(widget_title);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
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

        horizontalLayout_7->addWidget(btn_back);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        label_title_3 = new QLabel(widget_title);
        label_title_3->setObjectName(QStringLiteral("label_title_3"));
        label_title_3->setMinimumSize(QSize(689, 72));
        label_title_3->setMaximumSize(QSize(689, 72));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_title_3->setFont(font1);
        label_title_3->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(label_title_3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        btn_home = new QPushButton(widget_title);
        btn_home->setObjectName(QStringLiteral("btn_home"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(18);
        btn_home->setFont(font2);
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

        horizontalLayout_7->addWidget(btn_home);


        verticalLayout_2->addWidget(widget_title);

        widget = new QWidget(widget_main);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 140, 0, 0);
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        verticalLayout_4 = new QVBoxLayout(widget_3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_title = new QLabel(widget_4);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(36);
        font3.setBold(true);
        font3.setWeight(75);
        label_title->setFont(font3);
        label_title->setStyleSheet(QString::fromUtf8("#label_title\n"
"{min-width:339px;\n"
" max-width:339px;\n"
"min-height:71px;\n"
"max-height:71px;\n"
"border-image: url(:/Image/Resources/Image/\345\217\226\344\273\266\345\267\262\345\256\214\346\210\220\357\274\201.png);\n"
"}"));
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_title);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(widget_4);

        widget_hide = new QWidget(widget_3);
        widget_hide->setObjectName(QStringLiteral("widget_hide"));
        widget_hide->setMinimumSize(QSize(0, 50));
        widget_hide->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(widget_hide);

        widget_timer = new QWidget(widget_3);
        widget_timer->setObjectName(QStringLiteral("widget_timer"));
        horizontalLayout = new QHBoxLayout(widget_timer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 20, 0, 20);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_gif = new QLabel(widget_timer);
        label_gif->setObjectName(QStringLiteral("label_gif"));
        label_gif->setMinimumSize(QSize(33, 33));
        label_gif->setMaximumSize(QSize(33, 33));
        label_gif->setStyleSheet(QLatin1String("#label_gif\n"
"{\n"
"min-width:33px;\n"
"max-width:33px;\n"
"min-height:33px;\n"
"max-height:33px;\n"
"border-radius: 10px;\n"
"}"));

        horizontalLayout->addWidget(label_gif);

        label_timer = new QLabel(widget_timer);
        label_timer->setObjectName(QStringLiteral("label_timer"));
        label_timer->setMinimumSize(QSize(0, 0));
        label_timer->setMaximumSize(QSize(16777215, 16777215));
        label_timer->setFont(font1);
        label_timer->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_timer->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_timer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget_timer);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_OK = new QPushButton(widget_2);
        btn_OK->setObjectName(QStringLiteral("btn_OK"));
        QFont font4;
        btn_OK->setFont(font4);
        btn_OK->setStyleSheet(QLatin1String("#btn_OK\n"
"{\n"
"min-width:330px;\n"
"max-width:330px;\n"
"min-height:155px;\n"
"max-height:155px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_OK{border-image: url(:/Image/Resources/Image/btn_yes_nor.png);}\n"
"#btn_OK:hover{border-image:url(:/Image/Resources/Image/btn_yes_sele.png);}\n"
"#btn_OK:pressed{border-image:url(:/Image/Resources/Image/btn_yes_press.png);}"));

        horizontalLayout_2->addWidget(btn_OK);


        verticalLayout_4->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widget_3);

        widget_return = new QWidget(widget);
        widget_return->setObjectName(QStringLiteral("widget_return"));
        widget_return->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(widget_return);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_return);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        label_title_2 = new QLabel(widget_5);
        label_title_2->setObjectName(QStringLiteral("label_title_2"));
        QFont font5;
        font5.setFamily(QStringLiteral("Agency FB"));
        font5.setPointSize(36);
        font5.setBold(false);
        font5.setWeight(50);
        label_title_2->setFont(font5);
        label_title_2->setStyleSheet(QString::fromUtf8("#label_title_2\n"
"{min-width:349px;\n"
" max-width:349px;\n"
"min-height:71px;\n"
"max-height:71px;\n"
"border-image: url(:/Image/Resources/Image/\346\234\252\345\256\214\346\210\220\345\217\226\344\273\266\357\274\237.png);\n"
"}"));
        label_title_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_title_2);

        horizontalSpacer_5 = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addWidget(widget_5);

        widget_hide_2 = new QWidget(widget_return);
        widget_hide_2->setObjectName(QStringLiteral("widget_hide_2"));
        widget_hide_2->setMinimumSize(QSize(0, 50));
        widget_hide_2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(widget_hide_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        btn_return = new QPushButton(widget_return);
        btn_return->setObjectName(QStringLiteral("btn_return"));
        btn_return->setStyleSheet(QLatin1String("#btn_return\n"
"{\n"
"min-width:330px;\n"
"max-width:330px;\n"
"min-height:155px;\n"
"max-height:155px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_return{border-image: url(:/Image/Resources/Image/btn_open_nor.png);}\n"
"#btn_return:hover{border-image:url(:/Image/Resources/Image/btn_open_sele.png);}\n"
"#btn_return:pressed{border-image:url(:/Image/Resources/Image/btn_open_press.png);}"));

        horizontalLayout_6->addWidget(btn_return);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(widget_return);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(widget_main);


        retranslateUi(CMessage);

        QMetaObject::connectSlotsByName(CMessage);
    } // setupUi

    void retranslateUi(QWidget *CMessage)
    {
        CMessage->setWindowTitle(QApplication::translate("CMessage", "CMessage", Q_NULLPTR));
        btn_back->setText(QString());
        label_title_3->setText(QString());
        btn_home->setText(QString());
        label_title->setText(QString());
        label_gif->setText(QString());
        label_timer->setText(QApplication::translate("CMessage", "30S", Q_NULLPTR));
        btn_OK->setText(QString());
        label_title_2->setText(QString());
        btn_return->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CMessage: public Ui_CMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMESSAGE_H
