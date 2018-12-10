#ifndef QUEUEDEF_H
#define QUEUEDEF_H

#include "Queue.h"
#include <iostream>
using namespace std;

template <class T>
Queue<T>::Queue(int size) {
	m_iSize = size;
	m_iLength = 0;
	m_iHead = 0;
	m_iTail = 0;
	m_pQueue = new T[m_iSize];
}

template <class T>
Queue<T>::~Queue() {
	delete[]m_pQueue;
	m_pQueue = NULL;
}

// ��ն���
template <class T>
void Queue<T>::ClearQueue() {
	m_iHead = 0;
	m_iTail = 0;
	m_iLength = 0;
}

// �Ƿ�Ϊ��
template <class T>
bool Queue<T>::QueueEmpty() const {
	return m_iLength == 0 ? true : false;
}

// �Ƿ�Ϊ��
template <class T>
bool Queue<T>::QueueFull() const {
	return m_iLength == m_iSize ? true : false;
}

// ����
template <class T>
int Queue<T>::QueueLength() const {
	return m_iLength;
}

// ���
template <class T>
bool Queue<T>::EnQueue(T *e) {
	if (QueueFull()) {
		cout << "��������" << endl;
		return false;
	}
	m_pQueue[m_iTail] = *e;
	m_iTail++;
	m_iTail %= m_iSize;
	m_iLength++;
	return true;
}

//����
template <class T>
bool Queue<T>::DeQueue(T *e) {
	if (QueueEmpty()) {
		cout << "�����ѿ�" << endl;
		return false;
	}
	*e = m_pQueue[m_iHead];
	m_iHead++;
	m_iHead %= m_iSize;
	m_iLength--;
	return true;
}

// ����
template <class T>
void Queue<T>::QueueTraverse() {
	for (int i = 0; i < m_iLength; i++) {
		cout << m_pQueue[(m_iHead + i) % m_iSize] << ", ";
	}
	cout << endl;
}

#endif
