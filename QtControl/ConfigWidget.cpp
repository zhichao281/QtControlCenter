#include "ConfigWidget.h"

ConfigWidget::ConfigWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setupUi(this);
	radio_user->setChecked(true);
	connect(btn_ok, SIGNAL(clicked()), this, SLOT(on_slot_Ok()));

}

ConfigWidget::~ConfigWidget()
{
}
void ConfigWidget::on_slot_Ok()
{
	if (radio_admin->isChecked() == true)
	{
		AdminWidget.show();
		this->hide();
	}
	if (radio_user->isChecked() == true)
	{
		uesrWidget.showMaximized();
		this->hide();
	}

}
