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
   int GetCurrValue() const;
   
protected:
   void GetNextValue();
private:
   FILETIME* m_ftPrevIdleTime;
   FILETIME* m_ftPrevKernelTime;
   FILETIME* m_ftPrevUserTime;
};
