#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>

CMainWindowWidget::CMainWindowWidget( QWidget *parent ) : 
   QMainWindow( parent )
   ,m_pDataStorage( new CDataStorage( this ) )
	,m_pChecker( new CChecker( this ) )
{
	ui.setupUi( this );
	setCentralWidget( ui.tabWidget );

	ui.tabCalculation->setLayout( ui.verticalLayout_3 );
	ui.tabGraph->setLayout( ui.verticalLayout_4 );

	m_pChecker->setDataStorage( m_pDataStorage );

//   m_pDataTimer->setInterval(1000);
//   Q_ASSERT(connect(m_pDataTimer,SIGNAL(timeout()),this,SLOT(GetCurrDataValue())));
//   m_pDataTimer->start();

   //TODO: del following code
   /*QTreeWidgetItem *item = new QTreeWidgetItem(ui.treeWidget);
   item->setText( 0, "50000" );
   item->setText( 1, "\"08:06:04.678\"" );
   item->setText( 2, "100" );
   item->setText( 3, "100" );*/
   //end

   ui.treeWidget->setColumnWidth( 0, 134 );
   ui.treeWidget->setColumnWidth( 1, 175 );
   ui.treeWidget->setColumnWidth( 2, 75 );
   ui.treeWidget->setColumnWidth( 3, 75 );
	//TODO" fixed size? It's possible?

}

CMainWindowWidget::~CMainWindowWidget()
{
   do {} while ( !m_pDataStorage->stop() );
}
