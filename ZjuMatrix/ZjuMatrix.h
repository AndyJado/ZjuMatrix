//=======================================================================

// �ļ���(File name):  ZjuMatrix.h
// ����(Author):       ֣ʫ��
// �޸�(Reviser):      ������(R.Q.Xu, xurongqiao@zju.edu.cn)
// ����(Date):         2023.03.13
// �汾(Version):      v1.0
// ----------------------------------------------------------------------
// ����������ZjuMatrix.lib��ͷ�ļ�
//       Description: define a head file for ZjuMatrix.lib
//=======================================================================

#pragma once

#include "XVector.h"
#include "XPVector.h"
#include "XList.h"
#include "XDoubleMatrix.h"
#include "XSquareDoubleMatrix.h"
#include "XSymDoubleMatrix.h"
#include "XBandDoubleMatrix.h"

/// Define a head file for ZjuMatrix.lib.
namespace ZjuMatrix {
	void BtDB(XDoubleMatrix& mB, XSymDoubleMatrix& mD, XSymDoubleMatrix& mK); 
	                                                                 // ʵ������K=BTDB�ľ���˷�������D�ǶԳƾ���
	                                                                 // implement the product like K = tranpose(B) * D * B, where D is symmetric
	int GeneralizedJacobi(XSymDoubleMatrix& mM, XSymDoubleMatrix& mK, 
		                  XDoubleVector& vEigenValue,                //���ù���Jacobi��������ֵ����������
		                  XSquareDoubleMatrix& mEigenVector,         //(eigen-values and eigen-vectors by Generalized Jacobi method)
		                  double dTol, int nMaxIteration);
	double norm2(XDoubleVector& vD);                                 // ��ʵ�������Ķ����� (return the 2-norm of a real vector)
	void initialVector(XBandDoubleMatrix& mK, XBandDoubleMatrix& mM, 
		               XDoubleMatrix& mX0, int np, int nn);          // ���ӿռ�������ĳ�ʼ�������� (obtain the initial vector of subspace iteration method )
	void quickDescendSortVector(int nLeft, int nRight, XDoubleVector& vMK, XIntVector& vI); 
	                                                                 // ���ÿ������򣬶�һάʵ�������н������� 
	                                                                 // (sort one-dimensional real vectors in descending order through quick sort)
	void quickSortEigenSolution(int nLeft, int nRight, XDoubleVector& vEigenValue, XDoubleMatrix& mEigenVector);
	                                                                 // ���ÿ��������㷨������õ�����ֵ���Ӧ����������������ֵ�����������
	                                                                 // (sort the obtained eigenvalues and corresponding eigenvectors in ascending order of eigenvalues through quick sort)
	int subspaceIteration(XBandDoubleMatrix& mK, XBandDoubleMatrix& mM,
		                  XDoubleVector& vEigenValue, XDoubleMatrix& mEigenVector,
		                  double dTol, int nMaxIteration,            // �����ӿռ��������ǰm�׵�����ֵ����Ӧ����������
		                  int nm, int nn);                           // (calculate the first m mode of eigenvalues and corresponding eigenvectors through subspace iteration method)
}