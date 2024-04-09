//=======================================================================
// �ļ���(File name): XList.h
// ����(Author):      ������(R.Q.Xu, xurongqiao@zju.edu.cn)
// ����(Date):        2023.03.06
// ----------------------------------------------------------------------
// ����������һ��ģ���࣬����ʵ�����ݽṹ-����
// Description: define a template class for linked list.
//=======================================================================
#pragma once
#include "XVector.h"

namespace ZjuMatrix {

    /// Define a template class for node of linked list.
	template <class T> 
	class XListNode    // ����Ľڵ�(node of list)
	{
	public:
	    /// Description: data
		T m_T;                            // ����(data)
		/// Description: pointer to next node
		XListNode<T>* m_pNext;            // ��һ���ڵ��ָ��(pointer to next node)
	};

    /// Define a template class for linked list.
	template <class T>	
	class XList       // ����(linked list)
	{
	protected:
	    /// Description: head of linked list
		XListNode<T>* m_pHead;            // ����ͷ(head of linked list)

	public:
		XList();
		~XList();

	public:
		void append(T t);                 // ����β׷��һ���ڵ�(append a node at the tail)
		void toVector(XVector<T>& v);     // ������ת��������(convert the list to a vector)
	};


    //---------------------------------------------------------------------------
    //  ������(Function name): XList()
    //  ����: ȱʡ�Ĺ��캯��
    /// Description: default constructor
    // -------------------------------------------------------------------------
	template <class T>
	inline XList<T>::XList()
	{
		m_pHead = nullptr;
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): ~XList()
    //  ����: ��������
    /// Description: destructor
    // -------------------------------------------------------------------------
	template <class T>
	inline XList<T>::~XList()
	{
		XListNode<T>* pCurrent = m_pHead;
		while (pCurrent)
		{
			XListNode<T>* pNext = pCurrent->m_pNext;
			delete pCurrent;
			pCurrent = pNext;
		}
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): toVector(XVector<T>& v)
    //  ����: ������ת��������
    /// Description: Convert the list to a vector.
    // -------------------------------------------------------------------------
	template <class T>
	inline void XList<T>::toVector(XVector<T>& v)
	{
		XListNode<T>* pCurrent = m_pHead;
		int nSize = 0;
		while (pCurrent)
		{
			nSize++;
			pCurrent = pCurrent->m_pNext;
		}

		v.resetSize(nSize);
		int iPos = 0;
		pCurrent = m_pHead;
		while (pCurrent)
		{
			iPos++;
			v(iPos) = pCurrent->m_T;
			pCurrent = pCurrent->m_pNext;
		}
	}

    //---------------------------------------------------------------------------
    //  ������(Function name): append(T t)
    //  ����: ����β׷��һ���ڵ�
    /// Description: Append a node at the tail.
    // -------------------------------------------------------------------------
	template <class T>
	inline void XList<T>::append(T t)
	{
		if (m_pHead == nullptr)
		{
			m_pHead = new XListNode<T>;
			m_pHead->m_T = t;
			m_pHead->m_pNext = nullptr;
			return;
		}
		XListNode<T>* pCurrent = m_pHead;
		while (pCurrent->m_pNext)
		{
			pCurrent = pCurrent->m_pNext;
		}
		XListNode<T>* pTail = new XListNode<T>;
		pTail->m_pNext = nullptr;
		pTail->m_T = t;
		pCurrent->m_pNext = pTail;
	}

	typedef XList<int> XIntList;           // ������������(a list class for int)
	typedef XList<double> XDoubleList;     // ˫������������(a list class for double)

}

