#include "core\calculator_cpu.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

CCalculatorCPU::CCalculatorCPU( QObject* parent ) :
   QObject( parent ),
	m_iCurrCPUValue( 0 )
{
   calculateCurrValue();

   bool res = connect( this, &CCalculatorCPU::nextValue, this, &CCalculatorCPU::calculateCurrValue, Qt::QueuedConnection );
	Q_ASSERT( res );
}

CCalculatorCPU::~CCalculatorCPU()
{
}

void CCalculatorCPU::calculateCurrValue()
{
#ifdef Q_OS_WIN

     FILETIME ftIdleTime;
    FILETIME ftKernelTime;
    FILETIME ftUserTime;
    BOOL res = GetSystemTimes( &ftIdleTime, &ftKernelTime, &ftUserTime );
    Q_ASSERT( res );
    Sleep(100);

    FILETIME ftNewIdleTime;
    FILETIME ftNewKernelTime;
    FILETIME ftNewUserTime;
    res = GetSystemTimes(&ftNewIdleTime, &ftNewKernelTime, &ftNewUserTime );
    Q_ASSERT( res );
    int i_OldIdle = ftIdleTime.dwLowDateTime;
    int i_NewIdle = ftNewIdleTime.dwLowDateTime;
    int idle = i_NewIdle - i_OldIdle;

    int i_OldKernel = ftKernelTime.dwLowDateTime;
    int i_NewKernel = ftNewKernelTime.dwLowDateTime;
    int kernel = i_NewKernel - i_OldKernel;

    int i_OldUser = ftUserTime.dwLowDateTime;
    int i_NewUser = ftNewUserTime.dwLowDateTime;
    int user = i_NewUser - i_OldUser;

    double sys = kernel + user;

    m_iCurrCPUValue = ( (sys-idle)/sys)*100;


#else
   m_iCurrCPUValue = 0;
#error ("Can't get CPU for this OS");
#endif
}

int CCalculatorCPU::getCurrValue()
{
   Q_EMIT nextValue();
   return m_iCurrCPUValue;
}
