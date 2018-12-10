#ifndef LIST_H
#define LIST_H

#include "NodeDef.h"

// 顺序表
template <class T>
class SList
{
public:
	SList(int size);
	~SList();
	// 清空
	void ClearList();
	// 是否为空
	bool ListEmpty();
	// 获取长度
	int ListLength();
	// 获取元素
	bool GetElem(int i, T *e);
	// 定位元素
	int LocateElem(T *e);
	// 获取前驱
	bool PriorElem(T *currentElem, T *preElem);
	// 获取后继
	bool NextElem(T *currentElem, T *nextElem);
	// 插入元素
	bool ListInsert(int i, T *e);
	// 删除元素
	bool ListDelete(int i, T *e);
	// 遍历
	void ListTraversel();

private:
	T *m_pList;
	int m_iSize;
	int m_iLength;
};

// 链表
template <class T>
class LList {
public:
	LList();
	~LList();
	// 清空
	void ClearList();
	// 是否为空
	bool ListEmpty();
	// 获取长度
	int ListLength();
	// 获取元素
	bool GetElem(int i, Node<T> *pNode);
	// 定位元素
	int LocateElem(Node<T> *pNode);
	// 获取前驱
	bool PriorElem(Node<T> *pCurrentNode, Node<T> *pPreNode);
	// 获取后继
	bool NextElem(Node<T> *pCurrentNode, Node<T> *pNextNode);
	// 遍历
	void ListTraversel();
	// 插入
	bool ListInsert(int i, Node<T> *pNode);
	// 删除
	bool ListDelete(int i, Node<T> *pNode);
	// 插入到头节点后
	bool ListInsertHead(Node<T> *pNode);
	// 插入最后
	bool ListInsertTail(Node<T> *pNode);
private:
	Node<T> *m_pHead;
	int m_iLength;
};

#endif
