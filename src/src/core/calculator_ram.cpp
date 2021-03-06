#include "core\calculator_ram.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

CCalculatorRAM::CCalculatorRAM( QObject* parent ) :
   QObject( parent )
{
   calculateCurrValue();
   bool res = connect( this, &CCalculatorRAM::nextValue, this, &CCalculatorRAM::calculateCurrValue );
	Q_ASSERT( res );
}

CCalculatorRAM::~CCalculatorRAM()
{
}

const int CCalculatorRAM::getCurrValue()
{
   emit nextValue();
   return m_iCurrRAMLoad;
}

void CCalculatorRAM::calculateCurrValue()
{
#ifdef Q_OS_WIN
   MEMORYSTATUSEX statex;
   statex.dwLength = sizeof( statex );
   GlobalMemoryStatusEx( &statex );

   m_iCurrRAMLoad = statex.dwMemoryLoad;
#else
   m_iCurrRAMLoad = 0;
#error ("Can't get RAM value for this OS")
#endif
}

