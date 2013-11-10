#pragma once

#include "core\data_calculator.h"
#include <qobject.h>

#include <qlist.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <qthread.h>

/**
*  Class for collecting all loaded data
*/
class CDataStorage : public QObject
{
   Q_OBJECT

public:
   CDataStorage(QObject* parent = nullptr);
   virtual ~CDataStorage();

private:
   CAbstractDataCalculator* m_pCPUcalc;
   CAbstractDataCalculator* m_pRAMcalc;

   typedef struct SDataValue
   {
      uint uiNumber;
      QString strTime;
      ushort usCPU;
      ushort usRAM;
   }TSDataValue;
   QList<TSDataValue*> m_listDataValues;

   QThread m_ThreadCPU;
   QThread m_ThreadRAM;

   QTimer* m_updatableTimer;

   Q_SLOT void UpdateData();
   int m_iCurrNumber;
};

