#pragma once

#include <qobject.h>
#include <QPointer>

#include "bds_test.h"
#include "core\data_storage.h"

class CChecker : public QObject
{
   Q_OBJECT
public :
	CChecker( QObject* parent = nullptr );
   ~CChecker();

	void setDataStorage( CDataStorage* dataStorage );

public slots:
	void on_check();

private:
	CDataStorage* m_pDataStorage;

   CBDSTest* m_pBDStest;
};