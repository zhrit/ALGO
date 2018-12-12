#pragma once

#include "AVL.h"
#include <iostream>

using namespace std;

template <class T>
AVLTree<T>::AVLTree() {
	m_pRoot = nullptr;
}

template <class T>
AVLTree<T>::~AVLTree() {
	Destroy();
}

template <class T>
void AVLTree<T>::Destroy() {
	destroy(m_pRoot);
}
template <class T>
void AVLTree<T>::destroy(BitNode<T> *node) {
	if (node) {
		destroy(node->lchild);
		destroy(node->rchild);
		delete node;
		node = nullptr;
	}
}

template <class T>
BitNode<T>* AVLTree<T>::Search(T data, BitNode<T> *pNode) const {
	if (pNode == nullptr || pNode->data == data) {
		return pNode;
	}
	if (data < pNode->data) {
		return Search(data, pNode->lchild);
	}
	else {
		return Search(data, pNode->rchild);
	}
}

template <class T>
BitNode<T>* AVLTree<T>::Search(T data) const {
	return Search(data, m_pRoot);
}

template <class T>
void AVLTree<T>::Insert(T data) {
	Insert(m_pRoot, data);
}

template <class T>
BitNode<T>* AVLTree<T>::Insert(BitNode<T>* &pNode, T data) {
	if (pNode == nullptr) {
		pNode = new BitNode<T>(data, nullptr, nullptr);
	}
	else if (data < pNode->data) {
		pNode->lchild = Insert(pNode->lchild, data);

		if (Height(pNode->lchild) - Height(pNode->rchild) == 2) {
			if (data < pNode->lchild->data) {
				pNode = rotateLL(pNode);
			}
			else {
				pNode = rotateLR(pNode);
			}
		}
	}
	else if (data > pNode->data) {
		pNode->rchild = Insert(pNode->rchild, data);

		if (Height(pNode->rchild) - Height(pNode->lchild) == 2) {
			if (data < pNode->rchild->data) {
				pNode = rotateRL(pNode);
			}
			else {
				pNode = rotateRR(pNode);
			}
		}
	}
	else {

	}

	pNode->height = max(Height(pNode->lchild), Height(pNode->rchild)) + 1;

	return pNode;
}

template <class T>
void AVLTree<T>::Remove(T data) {
	BitNode<T> *d = Search(data, m_pRoot);
	if (d != nullptr) {
		m_pRoot = Remove(m_pRoot, d);
	}
}

template <class T>
BitNode<T>* AVLTree<T>::Remove(BitNode<T>* &pNode, BitNode<T>* d) {
	if (pNode == nullptr || d == nullptr) {
		return nullptr;
	}

	if (d->data < pNode->data) {
		pNode->lchild = Remove(pNode->lchild, d);

		if (Height(pNode->rchild) - Height(pNode->lchild) == 2) {
			if (Height(pNode->rchild->lchild) > Height(pNode->rchild->rchild)) {
				pNode = rotateRL(pNode);
			}
			else {
				pNode = rotateRR(pNode);
			}
		}
	}
	else if (d->data > pNode->data) {
		pNode->rchild = Remove(pNode->rchild, d);

		if (Height(pNode->lchild) - Height(pNode->rchild) == 2) {
			if (Height(pNode->lchild->lchild) > Height(pNode->lchild->rchild)) {
				pNode = rotateLL(pNode);
			}
			else {
				pNode = rotateLR(pNode);
			}
		}
	}
	else {
		//×óÓÒº¢×Ó·Ç¿Õ
		if ((pNode->lchild != nullptr) && (pNode->rchild != nullptr)) {
			if (Height(pNode->lchild) > Height(pNode->rchild)) {
				BitNode<T> * max = maxNode(pNode->lchild);
				pNode->data = max->data;
				pNode->lchild = Remove(pNode->lchild, max);
			}
			else {
				BitNode<T> * min = minNode(pNode->rchild);
				pNode->data = min->data;
				pNode->rchild = Remove(pNode->rchild, min);
			}
		}
		else {
			pNode = pNode->lchild != nullptr ? pNode->lchild : pNode->rchild;
		}
	}
	return pNode;
}

template <class T>
BitNode<T>* AVLTree<T>::maxNode(BitNode<T>* pNode) {
	if (pNode == nullptr) {
		return nullptr;
	}
	while (pNode->rchild != nullptr) {
		pNode = pNode->rchild;
	}
	return pNode;
}

template <class T>
BitNode<T>* AVLTree<T>::minNode(BitNode<T>* pNode) {
	if (pNode == nullptr) {
		return nullptr;
	}
	while (pNode->lchild != nullptr) {
		pNode = pNode->lchild;
	}
	return pNode;
}

template <class T>
BitNode<T>* AVLTree<T>::rotateLL(BitNode<T> *node) {
	BitNode<T>* temp;
	temp = node->lchild;
	node->lchild = temp->rchild;
	temp->rchild = node;

	temp->height = max(Height(temp->lchild), Height(temp->rchild)) + 1;
	node->height = max(Height(node->lchild), Height(node->rchild)) + 1;

	return temp;
}

template <class T>
BitNode<T>* AVLTree<T>::rotateRR(BitNode<T> *node) {
	BitNode<T>* temp;

	temp = node->rchild;
	node->rchild = temp->lchild;
	temp->lchild = node;

	temp->height = max(Height(temp->lchild), Height(temp->rchild)) + 1;
	node->height = max(Height(node->lchild), Height(node->rchild)) + 1;

	return temp;
}

template <class T>
BitNode<T>* AVLTree<T>::rotateLR(BitNode<T> *node) {
	node->lchild = rotateRR(node->lchild);
	return rotateLL(node);
}

template <class T>
BitNode<T>* AVLTree<T>::rotateRL(BitNode<T> *node) {
	node->rchild = rotateLL(node->rchild);
	return rotateRR(node);
}

template <class T>
int AVLTree<T>::Height() const {
	Height(m_pRoot);
}

template <class T>
int AVLTree<T>::Height(BitNode<T> *pNode) const {
	if (pNode != nullptr) {
		return pNode->height;
	}
	return 0;
}

template <class T>
T AVLTree<T>::max(T a, T b) {
	return a > b ? a : b;
}

template <class T>
void AVLTree<T>::InOrderTraverse() {
	if (m_pRoot) {
		inOrder(m_pRoot);
		cout << endl;
	}
}
template <class T>
void AVLTree<T>::inOrder(BitNode<T> *node) {
	if (node) {
		inOrder(node->lchild);
		cout << node->data <<" ";
		inOrder(node->rchild);
	}
}

template <class T>
void AVLTree<T>::LevelOrderTraverse() {
	if (m_pRoot) {
		BitNode<T> p;
		Queue<BitNode<T>> *q = new Queue<BitNode<T>>(30);
		q->EnQueue(m_pRoot);
		while (!q->QueueEmpty()) {
			q->DeQueue(&p);
			cout << p.data << " ";

			if (p.lchild)
				q->EnQueue(p.lchild);
			if (p.rchild)
				q->EnQueue(p.rchild);
		}
		delete q;
		q = nullptr;
		cout << endl;
	}
}

