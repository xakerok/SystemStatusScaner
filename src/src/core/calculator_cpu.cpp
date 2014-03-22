#include "core\calculator_cpu.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

void copyFileTimes( SFileTime* ft, FILETIME& winFT )
{
   ft->dwHighDateTime = winFT.dwHighDateTime;
   ft->dwLowDateTime = winFT.dwLowDateTime;
}

CCalculatorCPU::CCalculatorCPU( QObject* parent ) :
   QObject( parent ),
	m_iCurrCPUValue( 0 )
{
#ifdef Q_OS_WIN
   m_ftPrevIdleTime = new SFileTime;
   m_ftPrevKernelTime = new SFileTime;
   m_ftPrevUserTime = new SFileTime;

   FILETIME ftIdleTime;
   FILETIME ftKernelTime;
   FILETIME ftUserTime;

   BOOL bResult = GetSystemTimes( &ftIdleTime, &ftKernelTime, &ftUserTime );

   copyFileTimes( m_ftPrevIdleTime,ftIdleTime );
   copyFileTimes( m_ftPrevKernelTime,ftKernelTime );
   copyFileTimes( m_ftPrevUserTime,ftUserTime );

#endif
	bool res = connect( this, &CCalculatorCPU::nextValue, this, &CCalculatorCPU::calculateCurrValue, Qt::QueuedConnection );
	Q_ASSERT( res );
}

CCalculatorCPU::~CCalculatorCPU()
{
#ifdef Q_OS_WIN
   delete m_ftPrevIdleTime;
   delete m_ftPrevKernelTime;
   delete m_ftPrevUserTime;
#endif
}

void CCalculatorCPU::calculateCurrValue()
{
#ifdef Q_OS_WIN
   FILETIME ftNewIdleTime;
   FILETIME ftNewKernelTime;
   FILETIME ftNewUserTime;
   
//TODO: Fix crash divide by zero
//   ::Sleep(50);
   
   BOOL bResult = ::GetSystemTimes( &ftNewIdleTime, &ftNewKernelTime, &ftNewUserTime );

   ULONG iOldIdle = m_ftPrevIdleTime->dwLowDateTime;
   ULONG iNewIdle = ftNewIdleTime.dwLowDateTime;
   ULONG idle = iNewIdle - iOldIdle;

   ULONG iOldKernel = m_ftPrevKernelTime->dwLowDateTime;
   ULONG iNewKernel = ftNewKernelTime.dwLowDateTime;
   ULONG kernel = iNewKernel - iOldKernel;

   ULONG iOldUser = m_ftPrevUserTime->dwLowDateTime;
   ULONG iNewUser = ftNewUserTime.dwLowDateTime;
   ULONG user = iNewUser - iOldUser;

   ULONG sys = kernel + user;
   m_iCurrCPUValue = ( ( sys-idle ) / sys ) * 100;

   copyFileTimes( m_ftPrevIdleTime,ftNewIdleTime );
   copyFileTimes( m_ftPrevKernelTime,ftNewKernelTime );
   copyFileTimes( m_ftPrevUserTime,ftNewUserTime );

#else
   m_iCurrCPUValue = 0;
#error ("Can't get CPU for this OS");
#endif
}

const int CCalculatorCPU::getCurrValue()
{
   emit nextValue();
   return m_iCurrCPUValue;
}