#pragma once

class IDataCalculator
{
public:
    virtual ~IDataCalculator(){}
    virtual int getCurrValue() = 0;

protected:
   virtual void calculateCurrValue() = 0;

};

