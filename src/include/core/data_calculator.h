#pragma once

/**
*  Abstract class. Extends by CCalculatorRAM and CCalculatorCPU
*/
class IDataCalculator
{
public:
   virtual const int getCurrValue() = 0;
protected:
   virtual void calculateCurrValue() = 0;
};
