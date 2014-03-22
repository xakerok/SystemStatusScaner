#pragma once
#include "test_perfomance_interface.h"
#include <QObject>


class CBDSTest : public QObject,
   public ITestPerfomance
{
   Q_OBJECT
public:
   CBDSTest( QObject* parent = nullptr );
   ~CBDSTest();

   bool checkPerfomance( QList<int> dataList );

signals:
   void errorFound();

private:
   int Ie(double Ei,double Ej);
   double Cmn(int m, int N );
   double Sum_kForJtoM(int j, int m, double k);
   double returnK(int N);
   double sko(double k, int m);
   double Wmn(int N, int m, double Cmn, double C1N_m, double sko);
   double GLOBAL_BDS(int m,int N);
   double _GLOBAL_SKO(int m, int N);
   double C1n(int N);
   double e;
   int findZ(int n);
   QList<int>lst;

};