#include "core\calculator_ram.h"
#include <QMutexLocker>

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

CCalculatorRAM::CCalculatorRAM (QObject* parent) :
   QObject(parent)
{
   m_pTimer = new QTimer(this);
   Q_ASSERT( connect( m_pTimer, SIGNAL( timeout() ), this, SLOT( calculateCurrValue() ) ) );
   m_pTimer->setInterval(1000);
   m_pTimer->start();
}

CCalculatorRAM::~CCalculatorRAM()
{
}

const int CCalculatorRAM::getCurrValue()
{
   QMutexLocker lock( &m_mutex );
   return m_iCurrRAMLoad;
}

void CCalculatorRAM::calculateCurrValue()
{
#ifdef Q_OS_WIN
   MEMORYSTATUSEX statex;
   statex.dwLength = sizeof (statex);
   GlobalMemoryStatusEx (&statex);

   QMutexLocker lock( &m_mutex );
   m_iCurrRAMLoad = statex.dwMemoryLoad;
#else
   m_iCurrRAMLoad = 0;
#error ("Can't get RAM value for this OS")
#endif
}

