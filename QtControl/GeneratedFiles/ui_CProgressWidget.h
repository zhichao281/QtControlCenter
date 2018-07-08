/********************************************************************************
** Form generated from reading UI file 'CProgressWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPROGRESSWIDGET_H
#define UI_CPROGRESSWIDGET_H

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

class Ui_CProgressWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_main;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_back;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_title_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_home;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_gif;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_weight;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_height;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *CProgressWidget)
    {
        if (CProgressWidget->objectName().isEmpty())
            CProgressWidget->setObjectName(QStringLiteral("CProgressWidget"));
        CProgressWidget->resize(1024, 768);
        CProgressWidget->setStyleSheet(QLatin1String("QWidget#widget_main\n"
"{\n"
"border-image: url(:/Image/Resources/Image/img_bg.png);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(CProgressWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_main = new QWidget(CProgressWidget);
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

        label_title_2 = new QLabel(widget_title);
        label_title_2->setObjectName(QStringLiteral("label_title_2"));
        label_title_2->setMinimumSize(QSize(689, 72));
        label_title_2->setMaximumSize(QSize(689, 72));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_title_2->setFont(font1);
        label_title_2->setStyleSheet(QString::fromUtf8("\n"
"min-width:689px;\n"
"max-width:689px;\n"
"min-height:72px;\n"
"max-height:72px;\n"
"border-image: url(:/Image/Resources/Image/\350\256\276\345\244\207\350\277\220\350\241\214\344\270\255\357\274\214\350\257\267\350\200\220\345\277\203\347\255\211\345\276\205.png);"));

        horizontalLayout_5->addWidget(label_title_2);

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


        verticalLayout_2->addWidget(widget_title);

        widget_4 = new QWidget(widget_main);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        widget_4->setMaximumSize(QSize(16777215, 16777215));
        widget_4->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 80, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_gif = new QLabel(widget_4);
        label_gif->setObjectName(QStringLiteral("label_gif"));
        label_gif->setMinimumSize(QSize(160, 20));
        label_gif->setMaximumSize(QSize(160, 20));
        label_gif->setStyleSheet(QLatin1String("QLabel#label_gif\n"
"{\n"
"min-width:160px;\n"
"max-width:160px;\n"
"min-height:20px;\n"
"max-height:20px;\n"
"border-image:url(:/Image/Resources/Image/loading.gif);\n"
"}"));

        horizontalLayout->addWidget(label_gif);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_4);

        widget_2 = new QWidget(widget_main);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 50);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(50);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(50, 0, 10, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(658, 278));
        widget_3->setStyleSheet(QLatin1String("\n"
"#widget_3\n"
"{\n"
"min-width:658px;\n"
"max-width:658px;\n"
"min-height:278px;\n"
"max-height:278px;\n"
"border-radius: 10px;\n"
"}\n"
"#widget_3{border-image: url(:/Image/Resources/Image/label.png);}\n"
""));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setSpacing(30);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 20, 0, 20);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, -1, -1, -1);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(122, 118, 117);\n"
"font: 30pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_3->addWidget(label_3);

        label_weight = new QLabel(widget_3);
        label_weight->setObjectName(QStringLiteral("label_weight"));
        label_weight->setMaximumSize(QSize(16777215, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(30);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_weight->setFont(font3);
        label_weight->setLayoutDirection(Qt::RightToLeft);
        label_weight->setStyleSheet(QString::fromUtf8("color: rgb(122, 118, 117);\n"
"font: 30pt \"\351\273\221\344\275\223\";"));
        label_weight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_weight);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(122, 118, 117);\n"
"font: 30pt \"\351\273\221\344\275\223\";"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(50, -1, -1, -1);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(122, 118, 117);\n"
"font: 30pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_4->addWidget(label_4);

        label_height = new QLabel(widget_3);
        label_height->setObjectName(QStringLiteral("label_height"));
        label_height->setMaximumSize(QSize(16777215, 50));
        label_height->setFont(font3);
        label_height->setStyleSheet(QString::fromUtf8("color: rgb(122, 118, 117);\n"
"font: 30pt \"\351\273\221\344\275\223\";"));
        label_height->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_height);

        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(122, 118, 117);\n"
"font: 30pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_2->addWidget(widget_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        verticalLayout_2->addWidget(widget_2);


        verticalLayout->addWidget(widget_main);


        retranslateUi(CProgressWidget);

        QMetaObject::connectSlotsByName(CProgressWidget);
    } // setupUi

    void retranslateUi(QWidget *CProgressWidget)
    {
        CProgressWidget->setWindowTitle(QApplication::translate("CProgressWidget", "CProgressWidget", Q_NULLPTR));
        btn_back->setText(QString());
        label_title_2->setText(QString());
        btn_home->setText(QString());
        label_gif->setText(QString());
        label_3->setText(QApplication::translate("CProgressWidget", "\350\264\247\347\211\251\351\207\215\351\207\217\357\274\232", Q_NULLPTR));
        label_weight->setText(QApplication::translate("CProgressWidget", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("CProgressWidget", "kg", Q_NULLPTR));
        label_4->setText(QApplication::translate("CProgressWidget", "\350\264\247\347\211\251\351\253\230\345\272\246\357\274\232", Q_NULLPTR));
        label_height->setText(QApplication::translate("CProgressWidget", "0", Q_NULLPTR));
        label->setText(QApplication::translate("CProgressWidget", "mm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CProgressWidget: public Ui_CProgressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPROGRESSWIDGET_H
