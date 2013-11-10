#pragma once

#include "data_calculator.h"
#include <qobject.h>

struct FILETIME;

class CCalculatorCPU :
   public QObject,
   public CAbstractDataCalculator
{
   Q_OBJECT
public:
   CCalculatorCPU(QObject* parent = nullptr);
   virtual ~CCalculatorCPU();

   //inherited from CAbstractDataCalculator
   const int GetCurrValue();
private:
   Q_SLOT void CalculateCurrValue();
   Q_SIGNAL void GetNextValue();

   FILETIME* m_ftPrevIdleTime;
   FILETIME* m_ftPrevKernelTime;
   FILETIME* m_ftPrevUserTime;

   int m_iCurrCPUValue;
};
