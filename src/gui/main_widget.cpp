#include "main_widget.h"

CMainWindowWidget::CMainWindowWidget(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	setCentralWidget(ui.tabWidget);

	ui.tabCalculation->setLayout(ui.verticalLayout_3);
	ui.tabGraph->setLayout(ui.verticalLayout_4);
}

CMainWindowWidget::~CMainWindowWidget()
{

}
