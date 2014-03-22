#pragma once
#include <qobject.h>
#include "bds_test.h"

class CChecker : public QObject
{
   Q_OBJECT
public :
   CChecker();
   ~CChecker();

private:
   CBDSTest* m_pBDStest;

};