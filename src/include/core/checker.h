#pragma once

#include <qobject.h>
#include <QPointer>

#include "linear_difference_test.h"
#include "bds_test.h"
#include "core\data_storage.h"

class CChecker : public QObject
{
   Q_OBJECT
public :
	CChecker( QObject* parent = nullptr );
   ~CChecker();

	void setDataStorage( CDataStorage* dataStorage );

signals:
   void alertGreen ();
   void alertYellow ();
   void alertRed ();

public slots:
	void on_check();

private:
	CDataStorage* m_pDataStorage;

   CLinearDifferenceTest* m_pLinearTest;
   CBDSTest* m_pBDStest;
};