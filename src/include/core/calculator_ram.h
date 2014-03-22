#pragma once

#include "data_calculator.h"
#include <qobject.h>

/**
*  class for calculating ram
*/
class CCalculatorRAM :
   public QObject,
   public CAbstractDataCalculator
   public IDataCalculator
{
   Q_OBJECT
public:
   CCalculatorRAM(QObject* parent = nullptr);
   virtual ~CCalculatorRAM();
   CCalculatorRAM( QObject* parent = nullptr );
	virtual ~CCalculatorRAM();

   //inherited from CAbstractDataCalculator
   const int  GetCurrValue();
   const int  getCurrValue();
private slots:
   void calculateCurrValue();
signals:
   void nextValue();

private:
   Q_SLOT void CalculateCurrValue();
   Q_SIGNAL void GetNextValue();




   int m_iCurrRAMLoad;
};
