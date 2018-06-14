/********************************************************************************
** Form generated from reading UI file 'CQRWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQRWIDGET_H
#define UI_CQRWIDGET_H

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

class Ui_CQRWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_back;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_home;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_gif;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *CQRWidget)
    {
        if (CQRWidget->objectName().isEmpty())
            CQRWidget->setObjectName(QStringLiteral("CQRWidget"));
        CQRWidget->resize(1024, 768);
        CQRWidget->setStyleSheet(QLatin1String("QWidget#widget_main\n"
"{\n"
"border-image: url(:/Image/Resources/Image/img_bg.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(CQRWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(CQRWidget);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        verticalLayout_2 = new QVBoxLayout(widget_main);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(widget_main);
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

        horizontalLayout_4->addWidget(btn_back);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_title = new QLabel(widget_title);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(504, 71));
        label_title->setMaximumSize(QSize(504, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_title->setFont(font1);
        label_title->setStyleSheet(QString::fromUtf8("\n"
"min-width:504px;\n"
"max-width:504px;\n"
"min-height:71px;\n"
"max-height:71px;\n"
"border-image: url(:/Image/Resources/Image/\350\257\267\346\211\253\346\217\217\344\272\214\347\273\264\347\240\201\345\255\230\344\273\266.png);"));

        horizontalLayout_4->addWidget(label_title);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

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

        horizontalLayout_4->addWidget(btn_home);


        verticalLayout_2->addWidget(widget_title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_gif = new QLabel(widget_main);
        label_gif->setObjectName(QStringLiteral("label_gif"));
        label_gif->setMinimumSize(QSize(325, 326));
        label_gif->setMaximumSize(QSize(325, 326));
        label_gif->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_gif);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout->addWidget(widget_main);


        retranslateUi(CQRWidget);

        QMetaObject::connectSlotsByName(CQRWidget);
    } // setupUi

    void retranslateUi(QWidget *CQRWidget)
    {
        CQRWidget->setWindowTitle(QApplication::translate("CQRWidget", "CQRWidget", Q_NULLPTR));
        btn_back->setText(QString());
        label_title->setText(QString());
        btn_home->setText(QString());
        label_gif->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CQRWidget: public Ui_CQRWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQRWIDGET_H
