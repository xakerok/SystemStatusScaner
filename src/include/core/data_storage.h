#pragma once

#include "core\data_calculator.h"
#include <qobject.h>

#include <qlist.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <qthread.h>
#include <qmutex.h>

struct SDataValue
{
   uint uiNumber;
   QString strTime;
   ushort usCPU;
   ushort usRAM;
};

/**
*  Class for collecting all loaded data
*/
class CDataStorage : public QObject
{
   Q_OBJECT

public:
   CDataStorage( QObject* parent = nullptr );
   virtual ~CDataStorage();

   bool stop();
	QList<SDataValue*> getListDataValues() const;
private:
   IDataCalculator* m_pCPUcalc;
   IDataCalculator* m_pRAMcalc;
   
   QList<SDataValue*> m_listDataValues;

   QThread m_ThreadCPU;
   QThread m_ThreadRAM;

   QTimer* m_updatableTimer;

private slots:
   void updateData();

private:
   int m_iCurrNumber;

   mutable QMutex m_dataMutex;
};
