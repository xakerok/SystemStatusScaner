#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>
#include <qfileinfo.h>
#include <QSysInfo>

CMainWindowWidget::CMainWindowWidget(QWidget *parent) : 
    QMainWindow(parent)
  ,m_pDataStorage(new CDataStorage(this))
  ,m_pChecker( new CChecker( this ) )
{
    ui.setupUi(this);
    setCentralWidget(ui.tabWidget);

    QString userName = qgetenv("USER");
      if (userName.isEmpty())
          userName = qgetenv("USERNAME");
    ui.line_ComputerName->setText(userName);

    ui.line_OS->setText( QSysInfo::prettyProductName() );

    ui.line_Processor->setText( QSysInfo::currentCpuArchitecture() );

    ui.tabCalculation->setLayout(ui.verticalLayout_3);
    ui.tabGraph->setLayout(ui.verticalLayout_4);

    ui.treeWidget->setColumnWidth( 0, 75 );
    ui.treeWidget->setColumnWidth( 1, 100 );
    ui.treeWidget->setColumnWidth( 2, 50 );
    ui.treeWidget->setColumnWidth( 3, 50 );

    ui.splitter->setStretchFactor( 0, 2 );
    ui.splitter->setStretchFactor( 1, 5 );

    updateCurrentTime();

    m_pChecker->setDataStorage( m_pDataStorage );

    connect ( ui.buttonCheck, &QAbstractButton::clicked, m_pChecker, &CChecker::on_check );

    connect( m_pChecker, &CChecker::alertGreen, this, &CMainWindowWidget::checkerGreen );
    connect( m_pChecker, &CChecker::alertYellow, this, &CMainWindowWidget::checkerYellow );
    connect( m_pChecker, &CChecker::alertRed, this, &CMainWindowWidget::checkerRed );

    connect ( m_pDataStorage, &CDataStorage::updated, this, &CMainWindowWidget::on_undate );

    connect(m_pDataStorage->m_updatableTimer, &QTimer::timeout, this, &CMainWindowWidget::updateCurrentTime );

}

CMainWindowWidget::~CMainWindowWidget()
{
    do {} while ( !m_pDataStorage->stop() );
}


void CMainWindowWidget::updateCurrentTime()
{
    ui.dateTimeEdit->setDateTime( QDateTime::currentDateTime() );
}

void CMainWindowWidget::on_undate( SDataValue* dataValue )
{
    QTreeWidgetItem *item = new QTreeWidgetItem( ui.treeWidget );

    item->setText( 0, QString::number( dataValue->uiNumber ) );

    item->setText( 1, dataValue->strTime );
    item->setText( 2, QString::number( dataValue->usCPU ) );
    item->setText( 3, QString::number( dataValue->usRAM ) );

    ui.graphicsView_cpu->painting( m_pDataStorage->getListDataValues(), MyGraphicsView::CPUTypePainter );
    ui.graphicsView_ram->painting( m_pDataStorage->getListDataValues(), MyGraphicsView::RAMTypePainter );
    ui.graphicsView_all->painting( m_pDataStorage->getListDataValues(), MyGraphicsView::ALLTypePainter );
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
