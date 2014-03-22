#pragma once

#include "data_calculator.h"
#include <qobject.h>

/**
*  class for calculating ram
*/
class CCalculatorRAM :
   public QObject,
   public IDataCalculator
{
   Q_OBJECT
public:
   CCalculatorRAM( QObject* parent = nullptr );
	virtual ~CCalculatorRAM();

   //inherited from IDataCalculator
   const int  getCurrValue();
private slots:
   void calculateCurrValue();
signals:
   void nextValue();

private:
   int m_iCurrRAMLoad;
};
