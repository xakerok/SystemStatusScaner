#include "core\calculator_cpu.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

void copyFileTimes(SFileTime& ft, FILETIME& winFT)
{
   ft.dwHighDateTime = winFT.dwHighDateTime;
   ft.dwLowDateTime = winFT.dwLowDateTime;
}

CCalculatorCPU::CCalculatorCPU(QObject* parent) :
   QObject(parent),
   m_iCurrCPUValue(NULL)
{
   m_pTimer = new QTimer(this);
   Q_ASSERT( connect( m_pTimer, SIGNAL( timeout() ), this, SLOT( calculateCurrValue() ) ) );
   m_pTimer->setInterval(1000);
   m_pTimer->start();  


#ifdef Q_OS_WIN
   FILETIME ftIdleTime;
   FILETIME ftKernelTime;
   FILETIME ftUserTime;

   m_ftPrevIdleTime.dwHighDateTime = 0;
   m_ftPrevIdleTime.dwLowDateTime = 0;
   m_ftPrevKernelTime.dwHighDateTime = 0;
   m_ftPrevKernelTime.dwLowDateTime = 0;
   m_ftPrevUserTime.dwHighDateTime = 0;
   m_ftPrevUserTime.dwLowDateTime = 0;

   BOOL bResult = ::GetSystemTimes( &ftIdleTime, &ftKernelTime, &ftUserTime );

   copyFileTimes( m_ftPrevIdleTime,   ftIdleTime);
   copyFileTimes( m_ftPrevKernelTime, ftKernelTime);
   copyFileTimes( m_ftPrevUserTime,   ftUserTime);

#endif
}

CCalculatorCPU::~CCalculatorCPU()
{
}

void CCalculatorCPU::calculateCurrValue()
{

#ifdef Q_OS_WIN
   FILETIME ftNewIdleTime;
   FILETIME ftNewKernelTime;
   FILETIME ftNewUserTime;

   //TODO: Fix crash divide by zero

   BOOL bResult = ::GetSystemTimes( &ftNewIdleTime, &ftNewKernelTime, &ftNewUserTime );

   ULONG iOldIdle = m_ftPrevIdleTime.dwLowDateTime;
   ULONG iNewIdle = ftNewIdleTime.dwLowDateTime;
   ULONG idle = iNewIdle - iOldIdle;

   ULONG iOldKernel = m_ftPrevKernelTime.dwLowDateTime;
   ULONG iNewKernel = ftNewKernelTime.dwLowDateTime;
   ULONG kernel = iNewKernel - iOldKernel;

   ULONG iOldUser = m_ftPrevUserTime.dwLowDateTime;
   ULONG iNewUser = ftNewUserTime.dwLowDateTime;
   ULONG user = iNewUser - iOldUser;

   ULONG sys = kernel + user;
   m_iCurrCPUValue = (double)((sys-idle)/sys)*100;

   copyFileTimes(m_ftPrevIdleTime,   ftNewIdleTime);
   copyFileTimes(m_ftPrevKernelTime, ftNewKernelTime);
   copyFileTimes(m_ftPrevUserTime,   ftNewUserTime);

#else
   m_iCurrCPUValue = 0;
#error ("Can't get CPU for this OS");
#endif
}

const int CCalculatorCPU::getCurrValue()
{
   return m_iCurrCPUValue;
}