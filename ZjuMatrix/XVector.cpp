//==================================================================================
// �ļ���(File name): XVector.cpp
// ����(Author):      ������(R.Q.Xu, xurongqiao@zju.edu.cn)
// ����(Date):        2023.02.24
// ---------------------------------------------------------------------------------
// ��������XVector�����Ϊ������һЩ������
// Description: Implement some functions with parameters of objects of XVector.
//==================================================================================
#include "XVector.h"

using namespace ZjuMatrix;

//---------------------------------------------------------------------------
//  ������(Function name): max(XDoubleVector v)
//  ����: ���ֵ
/// Description: maximum element
// -------------------------------------------------------------------------
double ZjuMatrix::max(XDoubleVector v)
{
	int nSize = v.size();
	if (nSize <= 1)
		return 0.0;
	double dMax = v.Vi(1);
	for (int i = 2; i <= nSize; i++)
	{
		if (dMax < v.Vi(i))
			dMax = v.Vi(i);
	}
	return dMax;
}

//---------------------------------------------------------------------------
//  ������(Function name): min(XDoubleVector v)
//  ����: ��Сֵ
/// Description: minimum element
// -------------------------------------------------------------------------
double ZjuMatrix::min(XDoubleVector v)
{
	int nSize = v.size();
	if (nSize <= 1)
		return 0.0;
	double dMin = v.Vi(1);
	for (int i = 2; i <= nSize; i++)
	{
		if (dMin > v.Vi(i))
			dMin = v.Vi(i);
	}
	return dMin;
}

//---------------------------------------------------------------------------
//  ������(Function name): sum2(XDoubleVector v)
//  ����: ƽ����
/// Description: summation of squares
// -------------------------------------------------------------------------
double ZjuMatrix::sum2(XDoubleVector v)
{
	double dSum2 = 0.0;
	int nSize = v.size();
	for(int i=1; i<=nSize; i++)
	{
		double dVi = v.Vi(i);
		dSum2 += dVi * dVi;
	}
	return dSum2;
}
