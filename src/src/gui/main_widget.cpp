#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>
#include <qfileinfo.h>

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

   connect ( ui.buttonCheck, &QAbstractButton::clicked, m_pChecker, &CChecker::on_check );

   connect( m_pChecker, &CChecker::alertGreen, this, &CMainWindowWidget::checkerGreen );
   connect( m_pChecker, &CChecker::alertYellow, this, &CMainWindowWidget::checkerYellow );
   connect( m_pChecker, &CChecker::alertRed, this, &CMainWindowWidget::checkerRed );

   connect ( m_pDataStorage, &CDataStorage::updated, this, &CMainWindowWidget::on_undate );
}

CMainWindowWidget::~CMainWindowWidget()
{
   do {} while ( !m_pDataStorage->stop() );
}

void CMainWindowWidget::on_undate( SDataValue* dataValue )
{
  QTreeWidgetItem *item = new QTreeWidgetItem( ui.treeWidget );
 
  item->setText( 0, QString::number( dataValue->uiNumber ) );
 
  item->setText( 1, dataValue->strTime );
  item->setText( 2, QString::number( dataValue->usCPU ) );
  item->setText( 3, QString::number( dataValue->usRAM ) );

}

void CMainWindowWidget::checkerGreen()
{
   qDebug() << "green alert";
   ui.buttonCheck->setIcon( QIcon( qApp->applicationDirPath() + "/2.png" ) );
   ui.buttonCheck->setIconSize( QSize( 100, 100) );
}
void CMainWindowWidget::checkerYellow()
{
   qDebug() << "yellow alert";
   ui.buttonCheck->setIcon( QIcon( qApp->applicationDirPath() + "/3.png" ) );
   ui.buttonCheck->setIconSize( QSize( 100, 100) );
}
void CMainWindowWidget::checkerRed()
{
   qDebug() << "red alert";
   ui.buttonCheck->setIcon( QIcon( qApp->applicationDirPath() + "/1.png" ) );
   ui.buttonCheck->setIconSize( QSize( 100, 100) );
}