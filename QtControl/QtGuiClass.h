#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"

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
};
