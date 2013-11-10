#pragma once

#include "data_calculator.h"
#include <qobject.h>

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
   const int  GetCurrValue();
private:
   Q_SLOT void CalculateCurrValue();
   Q_SIGNAL void GetNextValue();

   int m_iCurrRAMLoad;
};
