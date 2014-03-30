#pragma once
#include <qobject.h>
#include "core\test_perfomance_interface.h"

class CLinearDifferenceTest : public QObject, public ITestPerfomance
{
   Q_OBJECT
public:
   CLinearDifferenceTest( QObject* parent = nullptr );
   ~CLinearDifferenceTest();

   bool checkPerfomance( QList<int> dataList );

   bool checkCPUValues( QList<int> dataList );
   bool checkRAMValues( QList<int> dataList );
};
