#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>

CMainWindowWidget::CMainWindowWidget( QWidget *parent ) : 
   QMainWindow( parent )
   ,m_pDataStorage( new CDataStorage( this ) )
{
	ui.setupUi( this );
	setCentralWidget( ui.tabWidget );

	ui.tabCalculation->setLayout( ui.verticalLayout_3 );
	ui.tabGraph->setLayout( ui.verticalLayout_4 );

   ui.treeWidget->setColumnWidth( 0, 75 );
   ui.treeWidget->setColumnWidth( 1, 110 );
   ui.treeWidget->setColumnWidth( 2, 50 );
   ui.treeWidget->setColumnWidth( 3, 50 );
   ui.treeWidget->setMaximumWidth( 300 ); 
   
	//TODO" fixed size? It's possible?

}

CMainWindowWidget::~CMainWindowWidget()
{
   do {} while ( !m_pDataStorage->stop() );
}
