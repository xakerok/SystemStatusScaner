#pragma once

/**
*  Abstract class. Extends by CCalculatorRAM and CCalculatorCPU
*/
class CAbstractDataCalculator
class IDataCalculator
{
public:
   //get curr value
   virtual const int GetCurrValue() = 0;
   virtual const int getCurrValue() = 0;

protected:
   //calculate curr value
   virtual void CalculateCurrValue() = 0;
   virtual void calculateCurrValue() = 0;

};
