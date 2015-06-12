#include "core\linear_difference_test.h"

CLinearDifferenceTest::CLinearDifferenceTest( QObject * parent ) :
   QObject( parent )
{
}

CLinearDifferenceTest::~CLinearDifferenceTest()
{
}

bool CLinearDifferenceTest::checkPerfomance( QList<int> values )
{
   return false;
}

bool CLinearDifferenceTest::checkCPUValues( QList<int> values )
{
   for( int index=1; index < values.size(); index ++ )
	{
      if(values.at( index-1 ) >=90 && values.at( index ) >= 90 )
		{
			return false;
		}
	}
	return true;
}

bool CLinearDifferenceTest::checkRAMValues( QList<int> values )
{
   for( int index=1; index < values.size(); index ++ )
	{
        if( abs( values.at( index-1 ) - values.at( index ) ) >= 10 )
		{
			return false;
		}
	}
	return true;
}
