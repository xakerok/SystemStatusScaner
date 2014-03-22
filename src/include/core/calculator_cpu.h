#pragma once

#include "data_calculator.h"
#include <qobject.h>

class CCalculatorCPU :
   public QObject,
   public IDataCalculator
{
   Q_OBJECT
public:
   CCalculatorCPU( QObject* parent = nullptr );
   virtual ~CCalculatorCPU();

   //inherited from IDataCalculator
   const int getCurrValue();
private slots:
   void calculateCurrValue();
signals:
   void nextValue();

private:
   int m_iCurrCPUValue;
};
