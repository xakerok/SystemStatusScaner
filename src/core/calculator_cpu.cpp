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

   int iOldIdle = m_ftPrevIdleTime->dwLowDateTime;
   int iNewIdle = ftNewIdleTime.dwLowDateTime;
   int idle = iNewIdle - iOldIdle;

   int iOldKernel = m_ftPrevKernelTime->dwLowDateTime;
   int iNewKernel = ftNewKernelTime.dwLowDateTime;
   int kernel = iNewKernel - iOldKernel;

   int iOldUser = m_ftPrevUserTime->dwLowDateTime;
   int iNewUser = ftNewUserTime.dwLowDateTime;
   int user = iNewUser - iOldUser;

   int sys = kernel + user;
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