#ifndef MYSTACKDEF_H
#define MYSTACKDEF_H

#include "MyStack.h"
#include <iostream>
using namespace std;

/* 栈 */
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

// 是否为空
template <class T>
bool MyStack<T>::stackEmpty() {
	return 0 == m_iTop ? true : false;
}

// 是否满
template <class T>
bool MyStack<T>::stackFull() {
	return m_iTop == m_iSize ? true : false;
}

// 清空栈
template <class T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}

// 获取元素个数
template <class T>
int MyStack<T>::stackLength() {
	return m_iTop;
}

// 入栈
template <class T>
bool MyStack<T>::push(T *e) {
	if (stackFull()) {
		return false;
	}
	m_pBuffer[m_iTop++] = *e;
	return true;
}

// 出栈
template <class T>
bool MyStack<T>::pop(T *e) {
	if (stackEmpty()) {
		return false;
	}
	*e = m_pBuffer[--m_iTop];
	return true;
}

// 返回栈顶元素
template <class T>
T MyStack<T>::top() {
	return m_pBuffer[m_iTop];
}

// 遍历
template <class T>
void MyStack<T>::stackTraversel() {
	for (int i = 0; i < m_iTop; i++) {
		cout << m_pBuffer[i] << ", ";
	}
	cout << endl;
}

#endif

