#pragma once

/**
*  Abstract class. Extends by CCalculatorRAM and CCalculatorCPU
*/
class CAbstractDataCalculator
{
   //get curr value
   virtual int GetCurrValue()const = 0;
protected:
   //calculate curr value
   virtual void CalculateCurrValue() const = 0;
};
