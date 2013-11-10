#pragma once

/**
*  Abstract class. Extends by CCalculatorRAM and CCalculatorCPU
*/
class CAbstractDataCalculator
{
   //get curr value
   virtual const int GetCurrValue() = 0;
protected:
   //calculate curr value
   virtual void CalculateCurrValue() = 0;
};
