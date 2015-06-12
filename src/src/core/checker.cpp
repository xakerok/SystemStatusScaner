#include "core\checker.h"


CChecker::CChecker( QObject* parent )
	: QObject( parent )
{
	m_pBDStest = new CBDSTest( this );
   m_pLinearTest = new CLinearDifferenceTest( this );
}

CChecker::~CChecker()
{
	//delete m_pBDStest;
}

void CChecker::setDataStorage( CDataStorage* dataStorage )
{
	m_pDataStorage = dataStorage;
}

void CChecker::on_check()
{
	QList<SDataValue*> dataList = m_pDataStorage->getListDataValues();

	QList<int> dataCPUList;
	for( auto currItem : dataList )
	{
		dataCPUList.push_back( currItem->usCPU );
	}

	QList<int> dataRAMList;
	for( auto currItem : dataList )
	{
		dataRAMList.push_back( currItem->usRAM );
	}

   if( ( !m_pLinearTest->checkCPUValues( dataCPUList ) && !m_pBDStest->checkPerfomance( dataCPUList ) ) &&
      (  !m_pLinearTest->checkRAMValues( dataRAMList ) && !m_pBDStest->checkPerfomance( dataRAMList  ) ) )
      emit alertRed();
   else 
      if( m_pLinearTest->checkCPUValues( dataCPUList ) && m_pBDStest->checkPerfomance( dataCPUList )  && 
          m_pLinearTest->checkRAMValues( dataRAMList ) && m_pBDStest->checkPerfomance( dataRAMList ) ) 
         emit alertGreen();
      else
         emit alertYellow();

}
