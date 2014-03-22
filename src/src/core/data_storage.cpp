#include "core\data_storage.h"

#include "core\calculator_cpu.h"
#include "core\calculator_ram.h"

#include <QMutexLocker>
#ifdef _DEBUG
#include <qdebug.h>
#endif

CDataStorage::CDataStorage(QObject* parent) : 
   QObject(parent)
   ,m_ThreadCPU(this)
   ,m_ThreadRAM(this)
   ,m_updatableTimer(new QTimer(this))
{
   m_iCurrNumber = NULL;
   
   m_pCPUcalc = new CCalculatorCPU;
   m_pRAMcalc = new CCalculatorRAM;
   
   dynamic_cast<QObject*>(m_pCPUcalc)->moveToThread(&m_ThreadCPU);
   dynamic_cast<QObject*>(m_pRAMcalc)->moveToThread(&m_ThreadRAM);

   m_ThreadCPU.start();
   m_ThreadRAM.start();
   
   Q_ASSERT( connect( m_updatableTimer, SIGNAL(timeout()), this, SLOT( updateData() ) ) );
   m_updatableTimer->setSingleShot(false);
   m_updatableTimer->start(1000);
}

CDataStorage::~CDataStorage()
{
}

void CDataStorage::updateData()
{
   TSDataValue* currDataValue = new TSDataValue;
   currDataValue->uiNumber = ++m_iCurrNumber;
   currDataValue->strTime = QDateTime::currentDateTime().toString("dd.MM hh:mm:ss.zzz");
   currDataValue->usCPU = m_pCPUcalc->getCurrValue();
   currDataValue->usRAM = m_pRAMcalc->getCurrValue();
   
   qDebug() <</* ++m_iCurrNumber << "\t" <<*/ QDateTime::currentDateTime().toString("dd.MM hh:mm:ss.zzz") << "\t" << m_pCPUcalc->getCurrValue() << "  " << m_pRAMcalc->getCurrValue();

}


bool CDataStorage::stop()
{
   m_updatableTimer->stop();
   m_ThreadCPU.quit();
   m_ThreadRAM.quit();
   qDeleteAll(m_listDataValues);
   m_listDataValues.clear();
   if(m_ThreadCPU.isFinished() && m_ThreadRAM.isFinished())
      return true;
   return false;
}
