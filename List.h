#ifndef LIST_H
#define LIST_H

#include "NodeDef.h"

// ˳���
template <class T>
class SList
{
public:
	SList(int size);
	~SList();
	// ���
	void ClearList();
	// �Ƿ�Ϊ��
	bool ListEmpty();
	// ��ȡ����
	int ListLength();
	// ��ȡԪ��
	bool GetElem(int i, T *e);
	// ��λԪ��
	int LocateElem(T *e);
	// ��ȡǰ��
	bool PriorElem(T *currentElem, T *preElem);
	// ��ȡ���
	bool NextElem(T *currentElem, T *nextElem);
	// ����Ԫ��
	bool ListInsert(int i, T *e);
	// ɾ��Ԫ��
	bool ListDelete(int i, T *e);
	// ����
	void ListTraversel();

private:
	T *m_pList;
	int m_iSize;
	int m_iLength;
};

// ����
template <class T>
class LList {
public:
	LList();
	~LList();
	// ���
	void ClearList();
	// �Ƿ�Ϊ��
	bool ListEmpty();
	// ��ȡ����
	int ListLength();
	// ��ȡԪ��
	bool GetElem(int i, Node<T> *pNode);
	// ��λԪ��
	int LocateElem(Node<T> *pNode);
	// ��ȡǰ��
	bool PriorElem(Node<T> *pCurrentNode, Node<T> *pPreNode);
	// ��ȡ���
	bool NextElem(Node<T> *pCurrentNode, Node<T> *pNextNode);
	// ����
	void ListTraversel();
	// ����
	bool ListInsert(int i, Node<T> *pNode);
	// ɾ��
	bool ListDelete(int i, Node<T> *pNode);
	// ���뵽ͷ�ڵ��
	bool ListInsertHead(Node<T> *pNode);
	// �������
	bool ListInsertTail(Node<T> *pNode);
private:
	Node<T> *m_pHead;
	int m_iLength;
};

#endif
