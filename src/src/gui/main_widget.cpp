#include "gui\main_widget.h"

#include <qdebug.h>
#include <qdatetime.h>

CMainWindowWidget::CMainWindowWidget(QWidget *parent) : 
   QMainWindow(parent)
   ,m_pCPUcalc(new CCalculatorCPU(this))
   ,m_pRAMcalc(new CCalculatorRAM(this))
   ,m_pDataTimer(new QTimer(this))
{
	ui.setupUi(this);
	setCentralWidget(ui.tabWidget);

	ui.tabCalculation->setLayout(ui.verticalLayout_3);
	ui.tabGraph->setLayout(ui.verticalLayout_4);

   m_pDataTimer->setInterval(1000);
   Q_ASSERT(connect(m_pDataTimer,SIGNAL(timeout()),this,SLOT(GetCurrDataValue())));
//   m_pDataTimer->start();
}

CMainWindowWidget::~CMainWindowWidget()
{

}

void CMainWindowWidget::GetCurrDataValue()
{
   qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
   qDebug() << "CurrCPU : " << m_pCPUcalc->GetCurrValue() ;
   qDebug() << "CurrRAM : " << m_pRAMcalc->GetCurrValue() ;
}