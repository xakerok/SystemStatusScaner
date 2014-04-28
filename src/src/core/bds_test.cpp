#include "core\bds_test.h"

#include <QMap>
#include <QDebug>

CBDSTest::CBDSTest( QObject *parent ) :
QObject( parent )
{
	e = 1;
}

CBDSTest::~CBDSTest()
{
}

int CBDSTest::Ie(double Ei, double Ej)
{
	int E=abs(Ei-Ej);
	if(E>e) return 0;
	else return 1;
}

double CBDSTest::Cmn(int m, int N )
{
	double k=(double)2/((N-m+1)*(N-m));
	int summ = 0;
	int mainsumm = 0;
	for(int s=m;s<N;s++)
	{

		for(int t=s+1;t<N;t++)
		{
			int curr = 1;
			for(int j=0;j<m-1;j++)
			{
				curr *= Ie(pow((double)lst[s-j],m),pow((double)lst[t-j],m));
			}
			summ += curr;
		}
	}
	return summ*k;
}


double CBDSTest::Sum_kForJtoM(int j, int m, double k)
{
	double curr = 0;
	double intermediateValue1 = 0.0;
	double intermediateValue2;
	double intermediateValue3;
	double intermediateValue4;
	double intermediateValue5;

	for(j=1;j<m-1;j++)
	{
		intermediateValue1 += pow(k, m-j) * pow((double)C1n(lst.size()),2*j);
	}

	intermediateValue3 = pow((double)m-1,2);
	intermediateValue4 = pow(C1n(lst.size()),2*m);
	intermediateValue5 = pow((double)m,2)*k*pow(C1n(lst.size()),2*m-2);

	curr += intermediateValue1 + intermediateValue3 * intermediateValue4 - intermediateValue5;


	/*	for(j=1;j<m-1;j++){
	intermediateValue1 = pow(k, m-j);
	intermediateValue2 = pow((double)C1n(lst.size()),2*j);
	intermediateValue3 = pow((double)m-1,2);
	intermediateValue4 = pow(C1n(lst.size()),2*m);
	intermediateValue5 = pow((double)m,2)*k*pow(C1n(lst.size()),2*m-2);
	curr += intermediateValue1 * intermediateValue2 + intermediateValue3 * intermediateValue4 - intermediateValue5;
	}
	*/
	return curr;

}

double CBDSTest::returnK(int N)
{
	double intermediateValue1 = (double)1/((N-2)*(N-1)*N);
	double intermediateValue2 = 0.0;
	double intermediateValue3 = 0.0;
	double intermediateValue4 = 0.0;

	for(int t=1;t<N;t++) {
		for(int s=1;s<N;s++) {
			intermediateValue3 += Ie(lst[t],lst[s]);
		}
		intermediateValue2 += pow(intermediateValue3,2);
		intermediateValue3 = 0.0;
	}
	//	intermediateValue3 = 0.0;
	for(int s=1;s<N;s++) {
		for(int t=s+1;s<N;s++) {
			intermediateValue3 += Ie(lst[t],lst[s]);
		}
	}
	intermediateValue3 *= 3;
	intermediateValue4 = 2*N;
	return intermediateValue1*(intermediateValue2-intermediateValue3+intermediateValue4);
}

double CBDSTest::sko(double k, int m)
{
	double theValueOfTheSquareRoot = pow(k, m) + 2*Sum_kForJtoM(1,m,k);
	return 2*sqrt(abs(theValueOfTheSquareRoot));
}


double CBDSTest::Wmn(int N, int m, double Cmn, double C1N_m, double sko)
{
	return sqrt((double)N-m+1)*(Cmn-pow(C1N_m, m))/sko;
}

int CBDSTest::findZ(int number)
{
	return 0;
}


double CBDSTest::GLOBAL_BDS(int m,int N)
{
	QMap<int,double>values;
	for(int i=0;i<=100;i++)
		values.insert(i,0);
	for(int i=0;i<lst.size();i++)
	{
		double val = values.value(lst[i]);
		values.remove(lst.at(i));
		values.insert(lst.at(i),++val);
	}
	for(int i=0;i<=100;i++)
	{
		double val = values.value(i);
		values.remove(i);
		values.insert(i,(double)val/lst.size());
	}
	double Mx = 0.0;
	for(int i=0;i<=100;i++)
	{
		Mx += i*values.value(i);
	}
	double M2x = 0.0;
	for(int i=0;i<=100;i++)
	{
		M2x += i*i*values.value(i);
	}
	double dispers = M2x - Mx*Mx;
	e = sqrt(dispers);

	qDebug() << "sko = " << dispers;



	return Wmn(N,m,Cmn(m,N),C1n(N),_GLOBAL_SKO(m,N));
}


double CBDSTest::_GLOBAL_SKO(int m, int N)
{
	return sko(returnK(N),m);
}


double CBDSTest::C1n(int N )
{
	double k=(double)2/((N)*(N-1));
	int summ = 0;
	for(int s=1;s<N;s++)
	{
		for(int t=s+1;t<N;t++)
		{
			summ += Ie(lst[s],lst[t]);
		}
	}
	return summ*k;
}

bool CBDSTest::checkPerfomance( QList<int> dataList )
{
	lst = dataList;

   double d = GLOBAL_BDS( 6, lst.size() );
	qDebug() << "bds result = " << d;

	lst.clear();
   if( abs(d) < 1.96 )
      return true;
   return false;
}