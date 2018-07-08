#include "ConfigWidget.h"

#include "QAdminWidget.h"
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
		QAdminWidget *AdminWidget=new QAdminWidget;
		AdminWidget->show();
		this->hide();
	}
	if (radio_user->isChecked() == true)
	{
		if (uesrWidget == nullptr)
		{
			uesrWidget = new CMainWidget;
		}	
		uesrWidget->showMaximized();
		this->hide();
	}

}
