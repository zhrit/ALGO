#ifndef MYSTACKDEF_H
#define MYSTACKDEF_H

#include "MyStack.h"
#include <iostream>
using namespace std;

/* ջ */
template <class T>
MyStack<T>::MyStack(int size) {
	m_iSize = size;
	m_pBuffer = new T[m_iSize];
	m_iTop = 0;
}

template <class T>
MyStack<T>::~MyStack() {
	delete[]m_pBuffer;
	m_pBuffer = NULL;
}

// �Ƿ�Ϊ��
template <class T>
bool MyStack<T>::stackEmpty() {
	return 0 == m_iTop ? true : false;
}

// �Ƿ���
template <class T>
bool MyStack<T>::stackFull() {
	return m_iTop == m_iSize ? true : false;
}

// ���ջ
template <class T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}

// ��ȡԪ�ظ���
template <class T>
int MyStack<T>::stackLength() {
	return m_iTop;
}

// ��ջ
template <class T>
bool MyStack<T>::push(T *e) {
	if (stackFull()) {
		return false;
	}
	m_pBuffer[m_iTop++] = *e;
	return true;
}

// ��ջ
template <class T>
bool MyStack<T>::pop(T *e) {
	if (stackEmpty()) {
		return false;
	}
	*e = m_pBuffer[--m_iTop];
	return true;
}

// ����ջ��Ԫ��
template <class T>
T MyStack<T>::top() {
	return m_pBuffer[m_iTop];
}

// ����
template <class T>
void MyStack<T>::stackTraversel() {
	for (int i = 0; i < m_iTop; i++) {
		cout << m_pBuffer[i] << ", ";
	}
	cout << endl;
}

#endif

