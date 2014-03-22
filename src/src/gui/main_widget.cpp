#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>

CMainWindowWidget::CMainWindowWidget(QWidget *parent) : 
   QMainWindow(parent)
   ,m_pDataStorage(new CDataStorage(this))
	,m_pChecker( new CChecker( this ) )
{
	ui.setupUi(this);
	setCentralWidget(ui.tabWidget);

	ui.tabCalculation->setLayout(ui.verticalLayout_3);
	ui.tabGraph->setLayout(ui.verticalLayout_4);

   ui.treeWidget->setColumnWidth( 0, 134 );
   ui.treeWidget->setColumnWidth( 1, 175 );
   ui.treeWidget->setColumnWidth( 2, 75 );
   ui.treeWidget->setColumnWidth( 3, 75 );

	m_pChecker->setDataStorage( m_pDataStorage );

	//TODO" fixed size? It's possible?

}

CMainWindowWidget::~CMainWindowWidget()
{
   do {} while ( !m_pDataStorage->stop() );
}