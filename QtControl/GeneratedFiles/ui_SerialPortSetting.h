/********************************************************************************
** Form generated from reading UI file 'SerialPortSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSETTING_H
#define UI_SERIALPORTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortSetting
{
public:

    void setupUi(QWidget *SerialPortSetting)
    {
        if (SerialPortSetting->objectName().isEmpty())
            SerialPortSetting->setObjectName(QStringLiteral("SerialPortSetting"));
        SerialPortSetting->resize(400, 300);

        retranslateUi(SerialPortSetting);

        QMetaObject::connectSlotsByName(SerialPortSetting);
    } // setupUi

    void retranslateUi(QWidget *SerialPortSetting)
    {
        SerialPortSetting->setWindowTitle(QApplication::translate("SerialPortSetting", "SerialPortSetting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialPortSetting: public Ui_SerialPortSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSETTING_H
