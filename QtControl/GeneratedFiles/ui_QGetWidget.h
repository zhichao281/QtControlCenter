/********************************************************************************
** Form generated from reading UI file 'QGetWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGETWIDGET_H
#define UI_QGETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGetWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_back;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_home;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_get;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_QRGet;
    QToolButton *btn_NumGet;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_Save;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *btn_QRSave;
    QToolButton *btn_NumSave;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *QGetWidget)
    {
        if (QGetWidget->objectName().isEmpty())
            QGetWidget->setObjectName(QStringLiteral("QGetWidget"));
        QGetWidget->resize(1436, 768);
        QGetWidget->setStyleSheet(QLatin1String("QWidget#widget_main\n"
"{\n"
"border-image: url(:/Image/Resources/Image/img_bg.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(QGetWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(QGetWidget);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(widget_main);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(widget_main);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 95));
        widget_title->setMaximumSize(QSize(16777215, 95));
        horizontalLayout_5 = new QHBoxLayout(widget_title);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(25, 10, 25, 0);
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

        horizontalLayout_5->addWidget(btn_back);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(504, 71));
        label_title->setMaximumSize(QSize(504, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_title->setFont(font1);
        label_title->setStyleSheet(QLatin1String("\n"
"min-width:504px;\n"
"max-width:504px;\n"
"min-height:71px;\n"
"max-height:71px;\n"
""));

        horizontalLayout_5->addWidget(label_title);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

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

        horizontalLayout_5->addWidget(btn_home);


        verticalLayout_4->addWidget(widget_title);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        widget_get = new QWidget(widget_main);
        widget_get->setObjectName(QStringLiteral("widget_get"));
        widget_get->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget_get);
        horizontalLayout->setSpacing(80);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_QRGet = new QToolButton(widget_get);
        btn_QRGet->setObjectName(QStringLiteral("btn_QRGet"));
        btn_QRGet->setMinimumSize(QSize(312, 143));
        btn_QRGet->setMaximumSize(QSize(312, 143));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(36);
        font3.setBold(true);
        font3.setWeight(75);
        btn_QRGet->setFont(font3);
        btn_QRGet->setStyleSheet(QLatin1String("#btn_QRGet\n"
"{\n"
"min-width:312;\n"
"max-width:312;\n"
"min-height:143;\n"
"max-height:143px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_QRGet{border-image: url(:/Image/Resources/Image/btn_qujian1_nor.png);}\n"
"#btn_QRGet:hover{border-image:url(:/Image/Resources/Image/btn_qujian1_sele.png);}\n"
"#btn_QRGet:pressed{border-image:url(:/Image/Resources/Image/btn_qujian1_press.png);}"));

        horizontalLayout->addWidget(btn_QRGet);

        btn_NumGet = new QToolButton(widget_get);
        btn_NumGet->setObjectName(QStringLiteral("btn_NumGet"));
        btn_NumGet->setMinimumSize(QSize(312, 143));
        btn_NumGet->setMaximumSize(QSize(312, 143));
        btn_NumGet->setFont(font3);
        btn_NumGet->setStyleSheet(QLatin1String("#btn_NumGet\n"
"{\n"
"min-width:312;\n"
"max-width:312;\n"
"min-height:143;\n"
"max-height:143px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_NumGet{border-image: url(:/Image/Resources/Image/btn_qujian2_nor.png);}\n"
"#btn_NumGet:hover{border-image:url(:/Image/Resources/Image/btn_qujian2_sele.png);}\n"
"#btn_NumGet:pressed{border-image:url(:/Image/Resources/Image/btn_qujian2_press.png);}"));
        btn_NumGet->setPopupMode(QToolButton::DelayedPopup);
        btn_NumGet->setAutoRaise(false);
        btn_NumGet->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(btn_NumGet);


        horizontalLayout_2->addWidget(widget_get);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        horizontalLayout_2->addLayout(verticalLayout_2);

        widget_Save = new QWidget(widget_main);
        widget_Save->setObjectName(QStringLiteral("widget_Save"));
        widget_Save->setMinimumSize(QSize(0, 0));
        widget_Save->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_4 = new QHBoxLayout(widget_Save);
        horizontalLayout_4->setSpacing(80);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_QRSave = new QToolButton(widget_Save);
        btn_QRSave->setObjectName(QStringLiteral("btn_QRSave"));
        btn_QRSave->setMinimumSize(QSize(312, 143));
        btn_QRSave->setMaximumSize(QSize(312, 143));
        btn_QRSave->setFont(font3);
        btn_QRSave->setStyleSheet(QLatin1String("#btn_QRSave\n"
"{\n"
"min-width:312;\n"
"max-width:312;\n"
"min-height:143;\n"
"max-height:143px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_QRSave{border-image: url(:/Image/Resources/Image/btn_cunjian1_nor.png);}\n"
"#btn_QRSave:hover{border-image:url(:/Image/Resources/Image/btn_cunjian1_sele.png);}\n"
"#btn_QRSave:pressed{border-image:url(:/Image/Resources/Image/btn_cunjian1_press.png);}"));

        horizontalLayout_4->addWidget(btn_QRSave);

        btn_NumSave = new QToolButton(widget_Save);
        btn_NumSave->setObjectName(QStringLiteral("btn_NumSave"));
        btn_NumSave->setMinimumSize(QSize(312, 143));
        btn_NumSave->setMaximumSize(QSize(312, 143));
        btn_NumSave->setFont(font3);
        btn_NumSave->setStyleSheet(QLatin1String("#btn_NumSave\n"
"{\n"
"min-width:312;\n"
"max-width:312;\n"
"min-height:143;\n"
"max-height:143px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_NumSave{border-image: url(:/Image/Resources/Image/btn_cunjian2_nor.png);}\n"
"#btn_NumSave:hover{border-image:url(:/Image/Resources/Image/btn_cunjian2_sele.png);}\n"
"#btn_NumSave:pressed{border-image:url(:/Image/Resources/Image/btn_cunjian2_press.png);}"));
        btn_NumSave->setPopupMode(QToolButton::DelayedPopup);
        btn_NumSave->setAutoRaise(false);
        btn_NumSave->setArrowType(Qt::NoArrow);

        horizontalLayout_4->addWidget(btn_NumSave);


        horizontalLayout_2->addWidget(widget_Save);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(widget_main);


        retranslateUi(QGetWidget);

        QMetaObject::connectSlotsByName(QGetWidget);
    } // setupUi

    void retranslateUi(QWidget *QGetWidget)
    {
        QGetWidget->setWindowTitle(QApplication::translate("QGetWidget", "QGetWidget", Q_NULLPTR));
        btn_back->setText(QString());
        label_title->setText(QString());
        btn_home->setText(QString());
        btn_QRGet->setText(QString());
        btn_NumGet->setText(QString());
        btn_QRSave->setText(QString());
        btn_NumSave->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QGetWidget: public Ui_QGetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGETWIDGET_H
