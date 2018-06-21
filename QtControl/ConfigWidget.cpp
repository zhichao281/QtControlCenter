#include "ConfigWidget.h"

#include "QtGuiClass.h"
ConfigWidget::ConfigWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setupUi(this);
	radio_user->setChecked(true);
	connect(btn_ok, SIGNAL(clicked()), this, SLOT(on_slot_Ok()));
	uesrWidget = nullptr;
}

ConfigWidget::~ConfigWidget()
{
}
void ConfigWidget::on_slot_Ok()
{
	if (radio_admin->isChecked() == true)
	{
		QtGuiClass *AdminWidget=new QtGuiClass;
		AdminWidget->show();
		this->hide();
	}
	if (radio_user->isChecked() == true)
	{
		if (uesrWidget == nullptr)
		{
			uesrWidget = new QtControl;
		}	
		uesrWidget->showMaximized();
		this->hide();
	}

}
