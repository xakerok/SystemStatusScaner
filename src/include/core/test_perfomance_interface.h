#pragma once
#include <QList>

class ITestPerfomance
{
public:
   virtual ~ITestPerfomance(){};
   virtual bool checkPerfomance( QList<int> dataList ) = 0;
};