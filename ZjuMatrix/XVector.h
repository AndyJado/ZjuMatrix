//=======================================================================
// �ļ���(File name): XVector.h
// ����(Author):      ������(R.Q.Xu, xurongqiao@zju.edu.cn)
// ����(Date):        2023.02.03
// ----------------------------------------------------------------------
// ����������һ��ģ���࣬���ڱ���һά���顣
// Description: define a template class for one-dimensional array.
//=======================================================================
#pragma once
#include <iostream>

using namespace std;

namespace ZjuMatrix {

	/// Define a template class for one-dimensional array.
	template <class T> class XVector
	{
	protected:
		int m_nSize;     // �����Ĵ�С(the size of vector)
		T* m_pT;         // ָ������Ԫ�ص�ָ��(the pointer to elements)

	public:
		XVector();                 // ȱʡ�Ĺ��캯��(default constructor)
		XVector(int nSize);        // �Զ��幹�캯��(customized constructor)
		XVector(int nSize, T* pT); // �Զ��幹�캯��(customized constructor)
		XVector(XVector<T>& v);    // �������캯��(copy constructor)
		~XVector();                // ��������(destructor)

		XVector<T>& operator=(const XVector<T>& v);  // ���صĸ�ֵ�����(overloaded assignment operator)

	public:
		void resetSize(int nSize);           // ���������Ĵ�С������ʼ��Ϊ��(reset the size of vector and initialized to zero)
		void ones(int nSize);                // ���������Ĵ�С������ʼ��Ϊ1(reset the size of vector and initialized to 1)
		int size() const;                    // ���������Ĵ�С(return the size of vector)

		// ����Ԫ��λ�ô�1��ʼ(iPos = 1, 2, ..., m_nSize)�������Ǵ��㿪ʼ
		// The position of element in the vector count from 1 rather than 0
		void exchange(int iPos, int jPos);   // ��������Ԫ��(exchange two elements)
		T& operator()(int iPos);             // ����Ԫ�ص�����(return the reference of element)
		T Vi(int iPos) const;                // ����Ԫ�ص�ֵ(return the value of element)
	};


	//using namespace ZjuMatrix;

    //---------------------------------------------------------------------------
    //  ������(Function name): XVector()
    //  ����: ȱʡ�Ĺ��캯��
    /// Description: default constructor
    // -------------------------------------------------------------------------
	template<class T>
	inline XVector<T>::XVector()
	{
		m_nSize = 0;
		m_pT = nullptr;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): XVector(int nSize)
    //  ����: �Զ��幹�캯��
    /// Description: customized constructor
    // -------------------------------------------------------------------------
	template<class T>
	inline XVector<T>::XVector(int nSize)
	{
		m_nSize = nSize;
		m_pT = new T[nSize];
		for (int i = 0; i < nSize; i++)
			m_pT[i] = (T)0;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): XVector(int nSize, T* pT)
    //  ����: �Զ��幹�캯��
    /// Description: customized constructor
    // -------------------------------------------------------------------------
	template<class T>
	inline XVector<T>::XVector(int nSize, T* pT)
	{
		m_nSize = nSize;
		m_pT = new T[nSize];
		for (int i = 0; i < nSize; i++)
			m_pT[i] = pT[i];
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): XVector(XVector<T>& v)
    //  ����: �������캯��
    /// Description: copy constructor
    // -------------------------------------------------------------------------
	template<class T>
	inline XVector<T>::XVector(XVector<T>& v)
	{
		m_nSize = v.m_nSize;
		m_pT = new T[m_nSize];
		for (int i = 0; i < m_nSize; i++)
			m_pT[i] = v.m_pT[i];
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): ~XVector()
    //  ����: ��������
    /// Description: destructor
    // -------------------------------------------------------------------------
	template<class T>
	inline XVector<T>::~XVector()
	{
		if (m_pT)
			delete[] m_pT;
	}

    //---------------------------------------------------------------------------
    //  ������(Overloading name): =(const XVector<T>& v)
    //  ����: ���صĸ�ֵ�����
    /// Description: overloaded assignment operator
    // -------------------------------------------------------------------------
	template<class T>
	inline XVector<T>& XVector<T>::operator=(const XVector<T>& v)
	{
		this->resetSize(v.m_nSize);
		for (int i = 0; i < m_nSize; i++)
			m_pT[i] = v.m_pT[i];
		return *this;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): resetSize(int nSize)
    //  ����: ���������Ĵ�С������ʼ��Ϊ��
    /// Description: Reset the size of vector and initialized to zero.
    // -------------------------------------------------------------------------
	template<class T>
	inline void XVector<T>::resetSize(int nSize)
	{
		if (m_nSize != nSize)
		{
			if (m_pT)
				delete[] m_pT;
			m_nSize = nSize;
			m_pT = new T[nSize];

		}
		for (int i = 0; i < nSize; i++)
			m_pT[i] = (T)0;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): ones(int nSize)
    //  ����: ���������Ĵ�С������ʼ��Ϊ1
    /// Description: Reset the size of vector and initialized to 1.
    // -------------------------------------------------------------------------
	template<class T>
	inline void XVector<T>::ones(int nSize)
	{
		if (m_nSize != nSize)
		{
			if (m_pT)
				delete[] m_pT;
			m_nSize = nSize;
			m_pT = new T[nSize];
		}
		for (int i = 0; i < nSize; i++)
			m_pT[i] = (T)1;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): size() const
    //  ����: ���������Ĵ�С��
    /// Description: Return the size of vector.
    // -------------------------------------------------------------------------
	template<class T>
	inline int XVector<T>::size() const
	{
		return m_nSize;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): exchange(int iPos, int jPos)
    //  ����: ��������Ԫ��
    /// Description: Exchange two elements.
    // -------------------------------------------------------------------------
	template<class T>
	inline void XVector<T>::exchange(int iPos, int jPos)
	{
		if (iPos <= 0 || iPos > m_nSize || jPos <= 0 || jPos > m_nSize)
		{
			throw("����Ԫ��ָ�곬���˷�Χ(The index exceed the size!)");
			return;
		}
		T dummy = Vi(iPos);
		operator()(iPos) = Vi(jPos);
		operator()(jPos) = dummy;
	}

    //---------------------------------------------------------------------------
    //  ������(Overloading name): ()(int iIndex)
    //  ����: ����Ԫ�ص�����
    /// Description: Return the reference of element.
    // -------------------------------------------------------------------------
	template<class T>
	inline T& XVector<T>::operator()(int iIndex)
	{
		if (iIndex <= 0 || iIndex > m_nSize)
		{
			throw("����Ԫ��ָ�곬���˷�Χ(The index beyond the scope)!");
			return m_pT[0];
		}
		return m_pT[iIndex - 1];
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): Vi(int iIndex) const
    //  ����: ����Ԫ�ص�ֵ
    /// Description: Return the value of element.
    // -------------------------------------------------------------------------
	template<class T>
	inline T XVector<T>::Vi(int iIndex) const
	{
		if (iIndex <= 0 || iIndex > m_nSize)
		{
			throw("����Ԫ��ָ�곬���˷�Χ(The index beyond the scope)!");
			return m_pT[0];
		}
		return m_pT[iIndex - 1];
	}

    //---------------------------------------------------------------------------
    //  ������(Overloading name): << (ostream& os, XVector<T>& v)
    //  ����: �����
    /// Description: stream output
    // -------------------------------------------------------------------------
	template <class T>
	ostream& operator<< (ostream& os, XVector<T>& v)
	{
		os << endl;
		for (int i = 1; i <= v.size(); i++)
			os << v(i) << "  ";
		os << endl;
		return os;
	}

	typedef XVector<int> XIntVector;           // ������������(a vector class for int)
	typedef XVector<double> XDoubleVector;     // ˫������������(a vector class for double)

	double max(XDoubleVector v);   // ���ֵ(maximum element)
	double min(XDoubleVector v);   // ��Сֵ(minimum element)
	double sum2(XDoubleVector v);  // ƽ����(summation of squares)
}