#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QWidget>
#include "ui_QtGuiClass.h"
#include <QTimer>
class QtGuiClass : public QWidget,public Ui::QtGuiClass
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

public slots:
	void on_slot_move();
	void on_slot_finish();
	void on_slot_open();
	void on_slot_close();

	void on_slot_suck();
	void on_slot_drop();
	void on_slot_pull();
	void on_slot_push();

	void on_slot_btn_height();
	void on_slot_btn_weight();
	void on_slot_btn_setZero();
	void on_slot_move_setting();
	void on_slot_move_read();
	void on_slot_rotate_setting();
	void on_slot_rotate_read();
	void on_slot_tray_setting();
	void on_slot_tray_read();
	void on_slot_door_setting();
	void on_slot_door_read();
	void on_slot_zero_setting();
	void on_slot_zero_read();
	void on_slot_btn_setting();


	void  solt_ReadSetting(int, QString);
public:
	QTimer * timer;  //用于声明定时器  


};
