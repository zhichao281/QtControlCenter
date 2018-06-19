#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setupUi(this);
	connect(btn_ok, SIGNAL(clicked()), this, SLOT(on_slot_Ok()));

}

ConfigWidget::~ConfigWidget()
{
}
void ConfigWidget::on_slot_Ok()
{
	if (radio_admin->isChecked() == true)
	{
		
		w1.show();
		this->hide();
	}
	if (radio_user->isChecked() == true)
	{
	
		w.showMaximized();
		this->hide();
	}

}