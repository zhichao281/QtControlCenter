/********************************************************************************
** Form generated from reading UI file 'QtControl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCONTROL_H
#define UI_QTCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtControlClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_tittle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *m_label_title;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_QRImage;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_save;
    QToolButton *btn_get;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QWidget *QtControlClass)
    {
        if (QtControlClass->objectName().isEmpty())
            QtControlClass->setObjectName(QStringLiteral("QtControlClass"));
        QtControlClass->resize(1024, 768);
        QtControlClass->setStyleSheet(QLatin1String("QWidget#widget_main\n"
"{\n"
"\n"
"border-image:url(:/Image/Resources/Image/img_bg.png);\n"
"\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(QtControlClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(QtControlClass);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        verticalLayout_4 = new QVBoxLayout(widget_main);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_tittle = new QWidget(widget_main);
        widget_tittle->setObjectName(QStringLiteral("widget_tittle"));
        widget_tittle->setMinimumSize(QSize(0, 95));
        widget_tittle->setMaximumSize(QSize(16777215, 95));
        horizontalLayout_4 = new QHBoxLayout(widget_tittle);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(50, 0, 50, 0);
        m_label_title = new QLabel(widget_tittle);
        m_label_title->setObjectName(QStringLiteral("m_label_title"));
        m_label_title->setMaximumSize(QSize(79, 68));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(36);
        m_label_title->setFont(font);
        m_label_title->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"min-width:79px;\n"
"min-height:68px;\n"
"max-width:79px;\n"
"max-height:68px;\n"
"border-image: url(:/Image/Resources/Image/inde_logo.png);"));

        horizontalLayout_4->addWidget(m_label_title);

        widget_2 = new QWidget(widget_tittle);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 50));
        verticalLayout_8 = new QVBoxLayout(widget_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_5);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(195, 46, 30);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));

        verticalLayout_8->addWidget(label_7);


        horizontalLayout_4->addWidget(widget_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label = new QLabel(widget_tittle);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(53, 48));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"min-width:53px;\n"
"min-height:48px;\n"
"max-width:53px;\n"
"max-height:48px;\n"
"border-image: url(:/Image/Resources/Image/img_service.png);"));

        horizontalLayout_4->addWidget(label);

        widget_3 = new QWidget(widget_tittle);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 95));
        verticalLayout_9 = new QVBoxLayout(widget_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_9->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(widget_3);


        verticalLayout_4->addWidget(widget_tittle);

        widget = new QWidget(widget_main);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 640));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QLatin1String("QWidget#widget_4\n"
"{\n"
"min-height:278px;\n"
"\n"
"max-height:278px;\n"
"	\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 70, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_QRImage = new QLabel(widget_4);
        label_QRImage->setObjectName(QStringLiteral("label_QRImage"));
        label_QRImage->setMinimumSize(QSize(218, 218));
        label_QRImage->setMaximumSize(QSize(218, 218));
        label_QRImage->setStyleSheet(QLatin1String("QLabel#label_QRImage\n"
"{min-width:218px;\n"
"min-height:218px;\n"
"max-width:218px;\n"
"max-height:218px;\n"
"	\n"
"}"));

        horizontalLayout_3->addWidget(label_QRImage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_4);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setStyleSheet(QLatin1String("QWidget#widget_6\n"
"{\n"
"min-height:40px;\n"
"\n"
"max-height:40px;\n"
"\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 10, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3\n"
"{\n"
"color:rgb(255, 255, 255);\n"
"\n"
"\n"
"	font:  75 25px \"\351\273\221\344\275\223\";\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(0);
        label_3->setIndent(-1);

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(widget_6);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_save = new QToolButton(widget_5);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setMinimumSize(QSize(309, 141));
        btn_save->setMaximumSize(QSize(309, 141));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(36);
        font2.setBold(true);
        font2.setWeight(75);
        btn_save->setFont(font2);
        btn_save->setStyleSheet(QLatin1String("#btn_save\n"
"{\n"
"min-width:309px;\n"
"max-width:309px;\n"
"min-height:141px;\n"
"max-height:141px;\n"
"border-radius: 10px;\n"
"}\n"
"#btn_save{border-image: url(:/Image/Resources/Image/btn_cunfang_nor.png);}\n"
"#btn_save:hover{border-image:url(:/Image/Resources/Image/btn_cunfang_sele.png);}\n"
"#btn_save:pressed{border-image:url(:/Image/Resources/Image/btn_cunfang_press.png);}"));

        horizontalLayout->addWidget(btn_save);

        btn_get = new QToolButton(widget_5);
        btn_get->setObjectName(QStringLiteral("btn_get"));
        btn_get->setMinimumSize(QSize(309, 141));
        btn_get->setMaximumSize(QSize(309, 141));
        btn_get->setFont(font2);
        btn_get->setStyleSheet(QLatin1String("#btn_get\n"
"{\n"
"min-width:309px;\n"
"max-width:309px;\n"
"min-height:141px;\n"
"max-height:141px;\n"
"}\n"
"#btn_get{border-image: url(:/Image/Resources/Image/btn_qujian_nor.png);}\n"
"#btn_get:hover{border-image:url(:/Image/Resources/Image/btn_qujian_sele.png);}\n"
"#btn_get:pressed{border-image:url(:/Image/Resources/Image/btn_qujian_press.png);}"));
        btn_get->setPopupMode(QToolButton::DelayedPopup);
        btn_get->setAutoRaise(false);
        btn_get->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(btn_get);


        verticalLayout_2->addWidget(widget_5);


        verticalLayout_4->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(80);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(80, -1, 80, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 8);

        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(widget_main);


        retranslateUi(QtControlClass);

        QMetaObject::connectSlotsByName(QtControlClass);
    } // setupUi

    void retranslateUi(QWidget *QtControlClass)
    {
        QtControlClass->setWindowTitle(QApplication::translate("QtControlClass", "QtControl", Q_NULLPTR));
        m_label_title->setText(QString());
        label_7->setText(QApplication::translate("QtControlClass", "\347\274\226\345\217\267\357\274\232001", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("QtControlClass", "139-0506-0001", Q_NULLPTR));
        label_QRImage->setText(QString());
        label_3->setText(QApplication::translate("QtControlClass", "\350\257\267 \346\211\253 \346\217\217 \344\272\214 \347\273\264 \347\240\201", Q_NULLPTR));
        btn_save->setText(QString());
        btn_get->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtControlClass: public Ui_QtControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCONTROL_H
