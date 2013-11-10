#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>

CMainWindowWidget::CMainWindowWidget(QWidget *parent) : 
   QMainWindow(parent)
   ,m_pDataStorage(new CDataStorage(this))
//   ,m_pDataTimer(new QTimer(this))
{
	ui.setupUi(this);
	setCentralWidget(ui.tabWidget);

	ui.tabCalculation->setLayout(ui.verticalLayout_3);
	ui.tabGraph->setLayout(ui.verticalLayout_4);

}

CMainWindowWidget::~CMainWindowWidget()
{
   do {} while ( !m_pDataStorage->stop() );
}
