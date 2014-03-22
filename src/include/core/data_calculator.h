#pragma once

/**
*  Abstract class. Extends by CCalculatorRAM and CCalculatorCPU
*/
class CAbstractDataCalculator
{
public:
   //get curr value
   virtual const int getCurrValue() = 0;
protected:
   //calculate curr value
   virtual void calculateCurrValue() = 0;
};
