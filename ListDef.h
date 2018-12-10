#ifndef LISTDEF_H
#define LISTDEF_H

#include "List.h"
#include <iostream>
using namespace std;

/*顺序表*/
template <class T>
SList<T>::SList(int size)
{
	m_iSize = size;
	m_pList = new T[m_iSize];
	m_iLength = 0;
}

template <class T>
SList<T>::~SList() {
	delete[]m_pList;
	m_pList = NULL;
}

// 清空
template <class T>
void SList<T>::ClearList() {
	m_iLength = 0;
}

// 是否为空
template <class T>
bool SList<T>::ListEmpty() {
	return m_iLength == 0 ? true : false;
}

// 长度
template <class T>
int SList<T>::ListLength() {
	return m_iLength;
}

// 获取元素
template <class T>
bool SList<T>::GetElem(int i, T *e) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}

	*e = m_pList[i];
	return true;
}

// 定位元素
template <class T>
int SList<T>::LocateElem(T *e) {
	for (int i = 0; i < m_iLength; i++) {
		if (m_pList[i] == *e) {
			return i;
		}
	}

	return -1;
}

// 获取前驱
template <class T>
bool SList<T>::PriorElem(T *currentElem, T *preElem) {
	int l = LocateElem(currentElem);
	if (l <= 0) {
		return false;
	}
	else {
		*preElem = m_pList[l - 1];
		return true;
	}
}

// 获取后继
template <class T>
bool SList<T>::NextElem(T *currentElem, T *nextElem) {
	int l = LocateElem(currentElem);
	if (l == -1 || l == m_iLength - 1) {
		return false;
	}
	else {
		*nextElem = m_pList[l + 1];
		return true;
	}
}

// 插入
template <class T>
bool SList<T>::ListInsert(int i, T *e) {
	if (m_iLength == m_iSize) {
		cout << "顺序表已满" << endl;
		return false;
	}
	if (i < 0 || i > m_iLength) {
		return false;
	}
	for (int k = m_iLength - 1; k >= i; k--) {
		m_pList[k + 1] = m_pList[k];
	}

	m_pList[i] = *e;
	m_iLength++;
	return true;
}

// 删除
template <class T>
bool SList<T>::ListDelete(int i, T *e) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	*e = m_pList[i];
	for (int k = i; k < m_iLength - 1; k++) {
		m_pList[k] = m_pList[k + 1];
	}
	m_iLength--;
	return true;
}

// 遍历输出
template <class T>
void SList<T>::ListTraversel() {
	for (int i = 0; i < m_iLength; i++) {
		cout << m_pList[i] << ' ';
	}
	cout << endl;
}

/* 链表 */
template <class T>
LList<T>::LList() {
	m_pHead = new Node<T>;
	// m_pHead->data = 0;
	m_pHead->next = NULL;
	m_iLength = 0;
}

template <class T>
LList<T>::~LList() {
	ClearList();
	delete m_pHead;
	m_pHead = NULL;
}

// 清空
template <class T>
void LList<T>::ClearList() {
	Node<T> *currentNode = m_pHead->next;
	Node<T> *temp;
	while (currentNode != NULL) {
		temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pHead->next = NULL;
	m_iLength = 0;
}

// 是否为空
template <class T>
bool LList<T>::ListEmpty() {
	return m_iLength == 0 ? true : false;
}

// 获取长度
template <class T>
int LList<T>::ListLength() {
	return m_iLength;
}

// 头部插入
template <class T>
bool LList<T>::ListInsertHead(Node<T> *pNode) {
	Node<T> *temp = m_pHead->next;
	Node<T> *newNode = new Node<T>;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = temp;
	m_pHead->next = newNode;
	m_iLength++;
	return true;
}


// 尾部插入
template <class T>
bool LList<T>::ListInsertTail(Node<T> *pNode) {
	Node<T> *currentNode = m_pHead;
	Node<T> *newNode = new Node<T>;
	if (newNode == NULL) {
		return false;
	}
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

// 插入
template <class T>
bool LList<T>::ListInsert(int i, Node<T> *pNode) {
	if (i < 0 || i >m_iLength) {
		return false;
	}
	Node<T> *newNode = new Node<T>;
	if (newNode == NULL) {
		return false;
	}
	Node<T> *currentNode = m_pHead;
	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

// 删除
template <class T>
bool LList<T>::ListDelete(int i, Node<T> *pNode) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node<T> *currentNode = m_pHead;
	Node<T> *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++) {
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	pNode->next = NULL;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

// 获取元素
template <class T>
bool LList<T>::GetElem(int i, Node<T> *pNode) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node<T> *currentNode = m_pHead;
	for (int k = 0; k <= i; k++) {
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	pNode->next = NULL;
	return true;
}

// 定位元素
template <class T>
int LList<T>::LocateElem(Node<T> *pNode) {
	int count = 0;;
	Node<T> *currentNode = m_pHead;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data) {
			return count;
		}
		count++;
	}
	return -1;
}

// 获取前驱
template <class T>
bool LList<T>::PriorElem(Node<T> *pCurrentNode, Node<T> *pPreNode) {
	Node<T> *currentNode = m_pHead;
	Node<T> *currentNodeBefore = NULL;
	while (currentNode->next != NULL) {
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (currentNodeBefore == m_pHead) {
				return false;
			}
			pPreNode->data = currentNodeBefore->data;
			return true;
		}
	}
	return false;
}

// 获取后继
template <class T>
bool LList<T>::NextElem(Node<T> *pCurrentNode, Node<T> *pNextNode) {
	Node<T> *currentNode = m_pHead;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (currentNode->next == NULL) {
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

// 遍历输出
template <class T>
void LList<T>::ListTraversel() {
	Node<T> *currentNode = m_pHead;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}

#endif
