#pragma once

#include "data_calculator.h"
#include <qobject.h>

#ifdef Q_OS_WIN
struct SFileTime 
{
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};
#endif

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
#ifdef Q_OS_WIN
   SFileTime* m_ftPrevIdleTime;
   SFileTime* m_ftPrevKernelTime;
   SFileTime* m_ftPrevUserTime;
#endif
   int m_iCurrCPUValue;
};