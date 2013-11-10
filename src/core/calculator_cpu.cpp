#include "core\calculator_cpu.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#endif

CCalculatorCPU::CCalculatorCPU(QObject* parent) :
   QObject(parent),
   m_iCurrCPUValue(NULL)
{
#ifdef Q_OS_WIN
   m_ftPrevIdleTime = new FILETIME;
   m_ftPrevKernelTime = new FILETIME;
   m_ftPrevUserTime = new FILETIME;
   BOOL bResult = ::GetSystemTimes( m_ftPrevIdleTime,m_ftPrevKernelTime,m_ftPrevUserTime );
#endif
   Q_ASSERT(connect(this,SIGNAL(GetNextValue()),this,SLOT(CalculateCurrValue())));
}

CCalculatorCPU::~CCalculatorCPU()
{
#ifdef Q_OS_WIN
   delete m_ftPrevIdleTime;
   delete m_ftPrevKernelTime;
   delete m_ftPrevUserTime;
#endif
}


void CCalculatorCPU::CalculateCurrValue()
{
#ifdef Q_OS_WIN
   FILETIME ftNewIdleTime;
   FILETIME ftNewKernelTime;
   FILETIME ftNewUserTime;
   BOOL bResult = ::GetSystemTimes(&ftNewIdleTime,&ftNewKernelTime,&ftNewUserTime);

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
   m_iCurrCPUValue = ((sys-idle)/sys)*100;

   m_ftPrevIdleTime = &ftNewIdleTime;
   m_ftPrevKernelTime = &ftNewKernelTime;
   m_ftPrevUserTime = &ftNewUserTime;

#else
   m_iCurrCPUValue = 0;
#error ("Can't get CPU for this OS");
#endif
   emit GetNextValue();
}

const int CCalculatorCPU::GetCurrValue()
{
   emit GetNextValue();
   return m_iCurrCPUValue;
}