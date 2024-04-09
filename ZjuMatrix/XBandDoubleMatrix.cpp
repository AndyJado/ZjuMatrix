#include "XBandDoubleMatrix.h"

using namespace ZjuMatrix;

//---------------------------------------------------------------------------
//  ������(Function name): XBandDoubleMatrix()
//  ����: Ĭ�Ϲ��캯��
/// Description: default constructor
// -------------------------------------------------------------------------
XBandDoubleMatrix::XBandDoubleMatrix()
{
	m_nRow = 0;
	m_nCol = 0;
}

//---------------------------------------------------------------------------
//  ������(Function name): XBandDoubleMatrix(XIntVector& viSkyline)
//  ����: ���캯��1
/// Description: constructor 1
// -------------------------------------------------------------------------
XBandDoubleMatrix::XBandDoubleMatrix(XIntVector& viSkyline)
{
	int nSize = viSkyline.size();
	m_nRow = nSize;
	m_nCol = nSize;
	m_viDiagonalPos.resetSize(nSize);
	m_viSkyline = viSkyline;
	m_viDiagonalPos(1) = viSkyline(1);
	for (int i = 2; i <= nSize; i++)
		m_viDiagonalPos(i) = m_viDiagonalPos(i - 1) + viSkyline(i - 1);
	m_vdEntry.resetSize(m_viDiagonalPos(nSize) + viSkyline(nSize) - 1);
}

//---------------------------------------------------------------------------
//  ������(Function name): XBandDoubleMatrix(XBandDoubleMatrix& m)
//  ����: ���ƹ��캯��
/// Description: copy constructor
// -------------------------------------------------------------------------
XBandDoubleMatrix::XBandDoubleMatrix(XBandDoubleMatrix& m)
{
	m_nRow = m.m_nRow;
	m_nCol = m.m_nCol;
	m_vdEntry = m.m_vdEntry;
	m_viSkyline = m.m_viSkyline;
	m_viDiagonalPos = m.m_viDiagonalPos;
}

//---------------------------------------------------------------------------
//  ������(Function name): =(const XBandDoubleMatrix& m)
//  ����: ��ֵ�����
/// Description: assignment operator
// -------------------------------------------------------------------------
XBandDoubleMatrix& XBandDoubleMatrix::operator=(const XBandDoubleMatrix& m)
{
	m_nRow = m.m_nRow;
	m_nCol = m.m_nCol;
	m_vdEntry = m.m_vdEntry;
	m_viSkyline = m.m_viSkyline;
	m_viDiagonalPos = m.m_viDiagonalPos;
	return (*this);
}

//---------------------------------------------------------------------------
//  ������(Function name): =(const XSymDoubleMatrix& m)
//  ����: ��ֵ�����
/// Description: assignment operator
// -------------------------------------------------------------------------
XBandDoubleMatrix& XBandDoubleMatrix::operator=(const XSymDoubleMatrix& m)
{
	int nSize = m.size();
	m_nRow = nSize;
	m_nCol = nSize;
	m_viSkyline.resetSize(nSize);
	m_viDiagonalPos.resetSize(nSize);
	m_vdEntry.resetSize(nSize * (nSize + 1) / 2);
	for (int i = 1; i <= nSize; i++)
	{
		m_viSkyline(i) = i;
		m_viDiagonalPos(i) = i * (i - 1) / 2 + 1;
	}
	for (int i = 1; i <= nSize; i++)
		for (int j = 1; j <= i; j++)
			(*this)(i, j) = m.Aij(i, j);

	return (*this);
}

//---------------------------------------------------------------------------
//  ������(Function name): =(const XSquareDoubleMatrix& m)
//  ����: ��ֵ�����
/// Description: assignment operator
// -------------------------------------------------------------------------
XBandDoubleMatrix& XBandDoubleMatrix::operator=(const XSquareDoubleMatrix& m)
{
	int nSize = m.size();
	m_nRow = nSize;
	m_nCol = nSize;
	m_viSkyline.resetSize(nSize);
	m_viDiagonalPos.resetSize(nSize);
	m_vdEntry.resetSize(nSize * (nSize + 1) / 2);
	for (int i = 1; i <= nSize; i++)
	{
		m_viSkyline(i) = i;
		m_viDiagonalPos(i) = i * (i - 1) / 2 + 1;
	}
	for (int i = 1; i <= nSize; i++)
		for (int j = 1; j <= i; j++)
			(*this)(i, j) = m.Aij(i, j);

	return (*this);
}

//---------------------------------------------------------------------------
//  ������(Function name): =(const XDoubleMatrix& m)
//  ����: ��ֵ�����
/// Description: assignment operator
// -------------------------------------------------------------------------
XBandDoubleMatrix& XBandDoubleMatrix::operator=(const XDoubleMatrix& m)
{
	int nSize;
	int nRow = m.rowSize();
	int nCol = m.colSize();
	nSize = nRow < nCol ? nRow : nCol;

	m_nRow = nSize;
	m_nCol = nSize;
	m_viSkyline.resetSize(nSize);
	m_viDiagonalPos.resetSize(nSize);
	m_vdEntry.resetSize(nSize * (nSize + 1) / 2);
	for (int i = 1; i <= nSize; i++)
	{
		m_viSkyline(i) = i;
		m_viDiagonalPos(i) = i * (i - 1) / 2 + 1;
	}
	for (int i = 1; i <= nSize; i++)
		for (int j = 1; j <= i; j++)
			(*this)(i, j) = m.Aij(i, j);

	return (*this);
}

//---------------------------------------------------------------------------
//  ������(Function name): ~XBandDoubleMatrix()
//  ����: ��������
/// Description: destructor
// -------------------------------------------------------------------------
XBandDoubleMatrix::~XBandDoubleMatrix()
{
	m_nRow = 0;
	m_nCol = 0;
}

//---------------------------------------------------------------------------
//  ������(Function name): resetSkyline(XIntVector& viSkyline)
//  ����: �������ô���
/// Description: reset the skyline of band matrix
// -------------------------------------------------------------------------
void XBandDoubleMatrix::resetSkyline(XIntVector& viSkyline)
{
	int nSize = viSkyline.size();
	m_nRow = nSize;
	m_nCol = nSize;
	m_viDiagonalPos.resetSize(nSize);
	m_viSkyline = viSkyline;
	m_viDiagonalPos(1) = viSkyline(1);
	for (int i = 2; i <= nSize; i++)
		m_viDiagonalPos(i) = m_viDiagonalPos(i - 1) + viSkyline(i - 1);
	m_vdEntry.resetSize(m_viDiagonalPos(nSize) + viSkyline(nSize) - 1);
}

//---------------------------------------------------------------------------
//  ������(Function name): resetSize(int nSize)
//  ����: �������þ����С����ʼ��Ϊ��
/// Description: resize the matrix and initialized to zero
// -------------------------------------------------------------------------
void XBandDoubleMatrix::resetSize(int nSize)
{
	// ��״�����������þ����С��ֻ�ǰ�Ԫ��ȫ����ʼ��Ϊ��
	// The banded matrix does not resize the matrix,
	// but simply initializes all the elements to zero
	resetSize();
}

//---------------------------------------------------------------------------
//  ������(Function name): resetSize()
//  ����: �������þ����С����ʼ��Ϊ��
/// Description: resize the matrix and initialized to zero
// -------------------------------------------------------------------------
void XBandDoubleMatrix::resetSize()
{
	for (int i = 1; i <= m_nRow; i++)
	{
		int iM = i - m_viSkyline(i) + 1;
		for (int j = iM; j <= i; j++)
			(*this)(i, j) = 0.0;
	}
}

//---------------------------------------------------------------------------
//  ������(Function name): eye(int nSize)
//  ����: �Ѿ�������Ϊ��λ����
/// Description: reset matrix to identity
// -------------------------------------------------------------------------
void XBandDoubleMatrix::eye(int nSize)
{
	// ��״�����������þ����С��ֻ�ǰѾ����Ϊ��λ����
	// The banded matrix does not resize the matrix,
	// but simply changes the matrix to an identity
	eye();
}

//---------------------------------------------------------------------------
//  ������(Function name): eye()
//  ����: �Ѿ�������Ϊ��λ����
/// Description: reset matrix to identity
// -------------------------------------------------------------------------
void XBandDoubleMatrix::eye()
{
	for (int i = 1; i <= m_nRow; i++)
	{
		int iM = i - m_viSkyline(i) + 1;
		for (int j = iM; j <= i; j++)
		{
			if (i == j)
				(*this)(i, j) = 1.0;
			else
				(*this)(i, j) = 0.0;
		}
	}
}

//---------------------------------------------------------------------------
//  ������(Function name): random(int nSize)
//  ����: �Ѿ�������Ϊ�������
/// Description: reset matrix to a random one
// -------------------------------------------------------------------------
void XBandDoubleMatrix::random(int nSize)
{
	// �����Ԫ�ض���Ϊ�������
	// Both the skyline and elements are set to random
	m_nRow = nSize;
	m_nCol = nSize;
	m_viSkyline.resetSize(nSize);
	m_viDiagonalPos.resetSize(nSize);
	
	for (int i = 1; i <= nSize; i++)
	{
		int nMaxHalfOfWidth = (nSize / 2) < 25 ? nSize / 2 : 25;
		int nRand = (rand() % nMaxHalfOfWidth + 1);
		m_viSkyline(i) = nRand < i ? nRand : i;
	}
	m_viDiagonalPos(1) = m_viSkyline(1);
	for (int i = 2; i <= nSize; i++)
		m_viDiagonalPos(i) = m_viDiagonalPos(i - 1) + m_viSkyline(i - 1);
	m_vdEntry.resetSize(m_viDiagonalPos(nSize) + m_viSkyline(nSize) - 1);
	random();
}

//---------------------------------------------------------------------------
//  ������(Function name): random()
//  ����: �Ѿ�������Ϊ�������
/// Description: reset matrix to a random one
// -------------------------------------------------------------------------
void XBandDoubleMatrix::random()
{
	// ���ı�������ԣ�ֻ�ǰ�Ԫ������Ϊ�����
	// The skyline remains and the elements are set to random 
	for (int i = 1; i <= m_nRow; i++)
	{
		int iM = i - m_viSkyline(i) + 1;
		for (int j = iM; j <= i; j++)
			(*this)(i, j) = double(rand() % 100000) / 100000.0;
	}
}

//---------------------------------------------------------------------------
//  ������(Function name): viSkyline()
//  ����: ���ش�״����ÿ�е�skyline
/// Description: Return the matrix's skyline
// -------------------------------------------------------------------------
XIntVector XBandDoubleMatrix::viSkyline()
{
	return this->m_viSkyline;
}

//---------------------------------------------------------------------------
//  ������(Function name): viDiagonalPos()
//  ����: ���ش�״����ÿ�жԽ���Ԫ����һά�����е�λ��
/// Description: return the position at 1D array for the diagnal element of each row
// -------------------------------------------------------------------------
XIntVector XBandDoubleMatrix::viDiagonalPos()
{
	return this->m_viDiagonalPos;
}

//---------------------------------------------------------------------------
//  ������(Function name): ()(int iRow, int jCol)
//  ����: ����Ԫ�ص�����
/// Description: Return the reference of an element
// -------------------------------------------------------------------------
double& XBandDoubleMatrix::operator()(int iRow, int jCol)
{
	if (iRow <= 0 || iRow > m_nRow || jCol <= 0 || jCol > m_nCol)
	{
		throw("Ԫ���кŻ��кų����˾����С(The index of matrix exceed the size)!");
		return m_vdEntry(1);
	}

	int i = iRow < jCol ? iRow : jCol;
	int j = iRow > jCol ? iRow : jCol;

	int k = j - i;
	if (k >= m_viSkyline(j))
	{
		throw("������Ԫ�س�����skyline(The element referred beyound the skyline)!");
		return m_vdEntry(1);
	}
	else
		return m_vdEntry(m_viDiagonalPos(j) + k);
}

//---------------------------------------------------------------------------
//  ������(Function name): Aij(int iRow, int jCol) const
//  ����: ����Ԫ�ص�ֵ
/// Description: Return the value of an element
// -------------------------------------------------------------------------
double XBandDoubleMatrix::Aij(int iRow, int jCol) const
{
	if (iRow <= 0 || iRow > m_nRow || jCol <= 0 || jCol > m_nCol)
	{
		throw("Ԫ���кŻ��кų����˾����С(The index of matrix exceed the size)!");
		return 0.0;
	}

	int i = iRow < jCol ? iRow : jCol;
	int j = iRow > jCol ? iRow : jCol;

	int k = j - i;
	if (k >= m_viSkyline.Vi(j))
	{
		return 0.0;
	}
	else
		return m_vdEntry.Vi(m_viDiagonalPos.Vi(j) + k);
}

//---------------------------------------------------------------------------
//  ������(Function name): ldl()
//  ����: �Գƴ�״�����LDL�ֽ⣬ԭ���󱻷ֽ�������
/// Description: LDL factorization and this symmetical banded matrix is overwritten by the resulting matrix of LDL factorization
// -------------------------------------------------------------------------
void XBandDoubleMatrix::ldl()
{
	for (int i = 2; i <= m_nRow; i++)
	{
		int iM = i - m_viSkyline(i) + 1;
		for (int j = iM; j <= i - 1; j++)
		{
			double TikLjk = 0.0;
			int jM = j - m_viSkyline(j) + 1;
			for (int k = (iM > jM ? iM : jM); k <= j - 1; k++)
			{
				TikLjk += Aij(i, k) * Aij(j, k);
			}
			(*this)(i, j) = Aij(i, j) - TikLjk;
		}
		for (int j = iM; j <= i - 1; j++)
		{
			(*this)(i, j) = Aij(i, j) / Aij(j, j);
		}
		double TikLik = 0;
		for (int k = iM; k <= i - 1; k++)
		{
			TikLik += Aij(i, k) *Aij(i, k) * Aij(k, k);
		}
		(*this)(i, i) = Aij(i, i) - TikLik;
	}
}

//---------------------------------------------------------------------------
//  ������(Function name): ldl(XBandDoubleMatrix& mLDL)
//  ����: �Գƴ�״�����LDL�ֽ⣬ԭ��������
/// Description: LDL decomposition and this symmetical banded matrix remains
// -------------------------------------------------------------------------
void XBandDoubleMatrix::ldl(XBandDoubleMatrix& mLDL)
{
	mLDL = *this;
	for (int i = 2; i <= m_nRow; i++)
	{
		int iM = i - m_viSkyline(i) + 1;
		for (int j = iM; j <= i - 1; j++)
		{
			double TikLjk = 0.0;
			int jM = j - m_viSkyline(j) + 1;
			for (int k = (iM > jM ? iM : jM); k <= j - 1; k++)
			{
				TikLjk += mLDL.Aij(i, k) * mLDL.Aij(j, k);
			}
			mLDL(i, j) = mLDL.Aij(i, j) - TikLjk;
		}
		for (int j = iM; j <= i - 1; j++)
		{
			mLDL(i, j) = mLDL.Aij(i, j) / mLDL.Aij(j, j);
		}
		double TikLik = 0;
		for (int k = iM; k <= i - 1; k++)
		{
			TikLik += mLDL.Aij(i, k) * mLDL.Aij(i, k) * mLDL.Aij(k, k);
		}
		mLDL(i, i) = mLDL.Aij(i, i) - TikLik;
	}
}

//---------------------------------------------------------------------------
//  ������(Function name): solve(XDoubleMatrix& mC)
//  ����: ����LDL�ֽ���ⷽ��A*B=C
/// Description: Solve equation A*B=C using LDL factorization.
// -------------------------------------------------------------------------
void XBandDoubleMatrix::solve(XDoubleMatrix& mC)
{
	int nSize = size();
	if (mC.rowSize() != nSize)
	{
		throw("ϵ�������С���Ҷ��ƥ��(The sizes of matrices of the equation do not matched to solve)!");
	}

	XBandDoubleMatrix mLDL;
	ldl(mLDL);
	int nCol = mC.colSize();
	for (int jCol = 1; jCol <= nCol; jCol++)
	{
		for (int i = 1; i <= nSize; i++)
		{
			double LikYk = 0.0;
			for (int k = 1; k <= i - 1; k++)
				LikYk += mLDL.Aij(i, k) * mC.Aij(k, jCol);
			mC(i, jCol) = mC.Aij(i, jCol) - LikYk;
		}
		for (int i = nSize; i >= 1; i--)
		{
			double LkiXk = 0.0;
			for (int k = i + 1; k <= nSize; k++)
				LkiXk += mLDL.Aij(k, i) * mC.Aij(k, jCol);
			mC(i, jCol) = mC.Aij(i, jCol) / mLDL.Aij(i, i) - LkiXk;
		}
	}
}


//---------------------------------------------------------------------------
//  ������(Function name): solve(XBandDoubleMatrix& mA, XDoubleMatrix& mC)
//  ����: ����LDL�ֽ���ⷽ��A*B=C
/// Description: Solve equation A*B=C using LDL factorization.
// -------------------------------------------------------------------------
XDoubleMatrix ZjuMatrix::solve(XBandDoubleMatrix& mA, XDoubleMatrix& mC)
{
	XDoubleMatrix mB;
	mB = mC;
	mA.solve(mB);
	return mB;
/*
	XDoubleMatrix mB;
	int nSize = mA.size();
	if (mC.rowSize() != nSize)
	{
		throw("ϵ�������С���Ҷ��ƥ��(The sizes of matrices of the equation do not matched to solve)!");
		return mB;
	}

	mB = mC;
	XBandDoubleMatrix mLDL;
	mA.ldl(mLDL);
	int nCol = mB.colSize();
	for (int jCol = 1; jCol <= nCol; jCol++)
	{
		for (int i = 1; i <= nSize; i++)
		{
			double LikYk = 0.0;
			for (int k = 1; k <= i - 1; k++)
				LikYk += mLDL.Aij(i, k) * mB.Aij(k, jCol);
			mB(i, jCol) = mB.Aij(i, jCol) - LikYk;
		}
		for (int i = nSize; i >= 1; i--)
		{
			double LkiXk = 0.0;
			for (int k = i + 1; k <= nSize; k++)
				LkiXk += mLDL.Aij(k, i) * mB.Aij(k, jCol);
			mB(i, jCol) = mB.Aij(i, jCol) / mLDL.Aij(i, i) - LkiXk;
		}
	}

	return mB;
//*/
}

