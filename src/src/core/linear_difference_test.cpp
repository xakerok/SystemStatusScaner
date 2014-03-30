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
      if(values.at( index-1 ) >=50 && values.at( index ) >= 50 )
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
		if( abs( values.at( index-1 ) - values.at( index ) ) >= 5 )
		{
			return false;
		}
	}
	return true;
}