#ifndef NODEDEF_H
#define NODEDEF_H

#include "Node.h"
#include<iostream>
using namespace std;

template <class T>
void Node<T>::printNode() {
	cout << data << endl;
}

#endif
