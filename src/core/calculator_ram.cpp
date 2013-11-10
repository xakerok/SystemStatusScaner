#include "core\calculator_ram.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

CCalculatorRAM::CCalculatorRAM (QObject* parent) :
   QObject(parent)
{
   CalculateCurrValue();
   Q_ASSERT(connect(this,SIGNAL(GetNextValue()),this,SLOT(CalculateCurrValue())));
}

CCalculatorRAM::~CCalculatorRAM()
{
}

const int CCalculatorRAM::GetCurrValue()
{
   emit GetNextValue();
   return m_iCurrRAMLoad;
}

void CCalculatorRAM::CalculateCurrValue()
{
#ifdef Q_OS_WIN
   MEMORYSTATUSEX statex;
   statex.dwLength = sizeof (statex);
   GlobalMemoryStatusEx (&statex);

   m_iCurrRAMLoad = statex.dwMemoryLoad;
#else
   m_iCurrRAMLoad = 0;
#error ("Can't get RAM value for this OS")
#endif
}

