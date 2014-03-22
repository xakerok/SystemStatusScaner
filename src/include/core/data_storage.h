#pragma once

#include "core\data_calculator.h"
#include <qobject.h>

#include <qlist.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <qthread.h>
#include <qmutex.h>

/**
*  Class for collecting all loaded data
*/
class CDataStorage : public QObject
{
   Q_OBJECT

public:
   CDataStorage(QObject* parent = nullptr);
   CDataStorage( QObject* parent = nullptr );
   virtual ~CDataStorage();

   bool stop();
private:
   CAbstractDataCalculator* m_pCPUcalc;
   CAbstractDataCalculator* m_pRAMcalc;
   IDataCalculator* m_pCPUcalc;
   IDataCalculator* m_pRAMcalc;

   typedef struct SDataValue
   struct SDataValue
   {
      uint uiNumber;
      QString strTime;
      ushort usCPU;
      ushort usRAM;
   }TSDataValue;
   QList<TSDataValue*> m_listDataValues;
   };

   QList<SDataValue*> m_listDataValues;

   QThread m_ThreadCPU;
   QThread m_ThreadRAM;

   QTimer* m_updatableTimer;

   Q_SLOT void UpdateData();
private slots:
   void updateData();

private:
   int m_iCurrNumber;

   mutable QMutex m_dataMutex;
};

