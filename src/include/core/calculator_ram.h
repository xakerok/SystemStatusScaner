#pragma once

#include "data_calculator.h"
#include <qobject.h>
#include <qtimer.h>
#include <qmutex.h>

/**
*  class for calculating ram
*/
class CCalculatorRAM :
   public QObject,
   public CAbstractDataCalculator
{
   Q_OBJECT
public:
   CCalculatorRAM(QObject* parent = nullptr);
   virtual ~CCalculatorRAM();

   //inherited from CAbstractDataCalculator
   const int  getCurrValue();
private:
   Q_SLOT void calculateCurrValue();
   QTimer* m_pTimer;
   QMutex m_mutex;
   int m_iCurrRAMLoad;
};
