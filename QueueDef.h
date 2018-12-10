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

// 清空队列
template <class T>
void Queue<T>::ClearQueue() {
	m_iHead = 0;
	m_iTail = 0;
	m_iLength = 0;
}

// 是否为空
template <class T>
bool Queue<T>::QueueEmpty() const {
	return m_iLength == 0 ? true : false;
}

// 是否为满
template <class T>
bool Queue<T>::QueueFull() const {
	return m_iLength == m_iSize ? true : false;
}

// 长度
template <class T>
int Queue<T>::QueueLength() const {
	return m_iLength;
}

// 入队
template <class T>
bool Queue<T>::EnQueue(T *e) {
	if (QueueFull()) {
		cout << "队列已满" << endl;
		return false;
	}
	m_pQueue[m_iTail] = *e;
	m_iTail++;
	m_iTail %= m_iSize;
	m_iLength++;
	return true;
}

//出对
template <class T>
bool Queue<T>::DeQueue(T *e) {
	if (QueueEmpty()) {
		cout << "队列已空" << endl;
		return false;
	}
	*e = m_pQueue[m_iHead];
	m_iHead++;
	m_iHead %= m_iSize;
	m_iLength--;
	return true;
}

// 遍历
template <class T>
void Queue<T>::QueueTraverse() {
	for (int i = 0; i < m_iLength; i++) {
		cout << m_pQueue[(m_iHead + i) % m_iSize] << ", ";
	}
	cout << endl;
}

#endif
