#include "core\data_storage.h"

#include "core\calculator_cpu.h"
#include "core\calculator_ram.h"


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
   
   m_ThreadCPU.start();
   m_ThreadRAM.start();

   dynamic_cast<QObject*>(m_pCPUcalc)->moveToThread(&m_ThreadCPU);
   dynamic_cast<QObject*>(m_pRAMcalc)->moveToThread(&m_ThreadRAM);

   Q_ASSERT(connect(m_updatableTimer,SIGNAL(timeout()),this,SLOT(UpdateData())));
   m_updatableTimer->setSingleShot(false);
   m_updatableTimer->start(1000);
}

CDataStorage::~CDataStorage()
{
}

void CDataStorage::UpdateData()
{
   TSDataValue* currDataValue = new TSDataValue;
   currDataValue->uiNumber = ++m_iCurrNumber;
   currDataValue->strTime = QDateTime::currentDateTime().toString("dd.MM hh:mm:ss.zzz");
   currDataValue->usCPU = m_pCPUcalc->GetCurrValue();
   currDataValue->usRAM = m_pRAMcalc->GetCurrValue();
   
#ifdef _DEBUG
   qDebug() << currDataValue->uiNumber << "\t" << currDataValue->strTime << "\t" << currDataValue->usCPU << "  " << currDataValue->usRAM;
#endif
   m_dataMutex.lock();
   m_listDataValues.push_back(currDataValue);
   m_dataMutex.unlock();
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