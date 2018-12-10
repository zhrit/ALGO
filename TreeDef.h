#ifndef TREEDEF_H
#define TREEDEF_H

#include "Tree.h"
#include "QueueDef.h"
#include "MyStackDef.h"
#include <iostream>
using namespace std;

template <class T>
Tree_A<T>::Tree_A(int size, T *pRoot) {
	m_iSize = size;
	m_pTree = new T[size];
	for (int i = 0; i < size; i++) {
		m_pTree[i] = NULL;
	}
	m_pTree[0] = *pRoot;
}

template <class T>
Tree_A<T>::~Tree_A() {
	delete []m_pTree;
}

// 根据索引寻找结点
template <class T>
T *Tree_A<T>::SearchNode(int nodeIndex) {
	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
		return NULL;
	}
	if (m_pTree[nodeIndex] == NULL) {
		return NULL;
	}
	return &m_pTree[nodeIndex];
}

// 添加结点
template <class T>
bool Tree_A<T>::AddNode(int nodeIndex, int direction, T *pNode) {
	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
		return false;
	}
	if (m_pTree[nodeIndex] == NULL) {
		return false;
	}
	if (direction == 0) {
		if (nodeIndex * 2 + 1 >= m_iSize) {
			return false;
		}
		if (m_pTree[nodeIndex * 2 + 1] != NULL) {
			return false;
		}
		m_pTree[nodeIndex * 2 + 1] = *pNode;
	}
	if (direction == 1) {
		if (nodeIndex * 2 + 2 >= m_iSize) {
			return false;
		}
		if (m_pTree[nodeIndex * 2 + 2] != NULL) {
			return false;
		}
		m_pTree[nodeIndex * 2 + 2] = *pNode;
	}
	return true;
}

// 删除结点 没有递归删除子结点
template <class T>
bool Tree_A<T>::DeleteNode(int nodeIndex, T *pNode) {
	if (nodeIndex < 0 || nodeIndex >= m_iSize) {
		return false;
	}
	if (m_pTree[nodeIndex] == NULL) {
		return false;
	}
	*pNode = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = NULL;
	return true;
}

// 遍历结点
template <class T>
void Tree_A<T>::TreeTraverse() {
	for (int i = 0; i < m_iSize; i++) {
		cout << m_pTree[i] << ", ";
	}
	cout << endl;
}



/* 链式储存结构二叉树 */
template <class T>
BiTree<T>::BiTree() {
	m_pRoot = NULL;
}

template <class T>
BiTree<T>::~BiTree() {
	DestroyBiTree();
}

/** 
 * 创建二叉树
 * data 源数据
 * num 源数据长度
 * emptyData 空结点数据
 * pos 当前数据位置
 * index 遍历顺序标识 0 - 前序遍历， 1 - 层序遍历
*/
template <class T>
BiNode<T> *BiTree<T>::create(T data[], int num, T emptyData, int &pos, int index) {
	pos++;
	BiNode<T> *t;
	if (pos >= num) {
		return NULL;
	}
	else {
		if (data[pos] == emptyData) {
			t = NULL;
		}
		else {
			t = new BiNode<T>;
			t->data = data[pos];
			t->lChild = create(data, num, emptyData, pos, index);
			t->rChild = create(data, num, emptyData, pos, index);
		}
		return t;
	}
}

template <class T>
void BiTree<T>::CreateBiTree(T data[], int num, T emptyData, int index) {
	int pos = -1;
	m_pRoot = create(data, num, emptyData, pos, index);
}

// 销毁二叉树
template <class T>
void BiTree<T>::DestroyBiTree(BiTree<T> *biNode) {
	if (biNode) {
		DestroyBiTree(biNode->lChild);
		DestroyBiTree(biNode->rChild);
		delete biNode;
		biNode = NULL;
	}
}

// 获取深度
template <class T>
int BiTree<T>::GetDepth(BiNode<T> *pRoot ) {
	if (pRoot) {
		int depthLeft = GetDepth(pRoot->lChild);
		int depthRight = GetDepth(pRoot->rChild);
		return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
	}

	return 0;
}

// 获取结点个数
template <class T>
int BiTree<T>::GetNodeNum(BiNode<T> *pRoot) {
	int num = 0;
	if (pRoot) {
		num += 1;
		num += GetNodeNum(pRoot->lChild);
		num += GetNodeNum(pRoot->rChild);
	}

	return num;
}

// 获取叶子结点的个数
template <class T>
int BiTree<T>::GetLeafNodeNum(BiNode<T> *pRoot) {
	int num = 0;
	if (pRoot) {
		if (pRoot->lChild == NULL && pRoot->rChild == NULL) {
			num += 1;
		}
		else {
			num += GetLeafNodeNum(pRoot->lChild);
			num += GetLeafNodeNum(pRoot->rChild);
		}
	}
	return num;
}

// 是否为平衡二叉树
template <class T>
bool BiTree<T>::IsAVL(BiNode<T> *pRoot, int *pHeight) {
	if (pRoot) {
		int heightLeft = 0;
		bool resultLeft = IsAVL(pRoot->lChild, &heightLeft);
		int heightRight = 0;
		bool resultRight = IsAVL(pRoot->rChild, &heightRight);

		if (pHeight)
			*pHeight = max(heightLeft, heightRight) + 1;

		if (resultLeft && resultRight && abs(heightLeft - heightRight) <= 1) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (pHeight) {
			*pHeight = 0;
		}
		return true;
	}
}
// 前序遍历二叉树
template <class T>
void BiTree<T>::PreOrderTraverse(BiNode<T> *pRoot, bool brec) {
	if (pRoot) {
		if (brec) {
			cout << pRoot->data << " ";
			PerOrderTraverse(pRoot->lChild, brec);
			PreOrderTraverse(pRoot->rChild, brec);
		}
		else {
			MyStack<BiNode<T>> *s = new MyStack<BiNode<T>>(100);
			BiNode<T> *p = pRoot;
			while (p != NULL || !s->stackEmpty()) {
				if (p != NULL) {
					cout << p->data << " ";
					s->push(p);
					p = p->lChild;
				}
				else {
					s->pop(p);
					p = p->rChild;
				}
			}
			delete s;
			s = NULL;
		}
	}
}

// 中序遍历二叉树
template <class T>
void BiTree<T>::InOrderTraverse(BiNode<T> *pRoot, bool brec) {
	if (pRoot) {
		if (brec) {
			InOrderTraverse(pRoot->lChild, brec);
			cout << pRoot->data << " ";
			InOrderTraverse(pRoot->rChild, brec);
		}
		else {
			MyStack<BiNode<T>> *s = new MyStack<BiNode<T>>(100);
			
			s->push(pRoot);
			BiNode<T> *pre = NULL;
			BiNode<T> *cur = NULL;
			BiNode<T> *p = NULL;
			
			while (!s->stackEmpty()) {
				cur = s->top();
				if ((cur->lChild == NULL && cur->rChild == NULL) || 
					((pre != NULL) && (pre == cur->lChild || pre == cur->rChild))) 
				{
					cout << cur->data << " ";
					s->pop(p);
					pre = cur;
				}
				else {
					if (cur->rChild)
						s->push(cur->rChild);
					if (cur->lChild)
						s->push(cur->lChild);
				}
			}

			delete s;
			s = NULL;
		}
	}
}

// 后序遍历二叉树
template <class T>
void BiTree<T>::PostOrderTraverse(BiNode<T> *pRoot, bool brec) {
	if (pRoot) {
		if (brec) {
			InOrderTraverse(pRoot->lChild, brec);
			InOrderTraverse(pRoot->rChild, brec);
			cout << pRoot->data << " ";
		}
		else {
			MyStack<BiNode<T>> *s = new MyStack<BiNode<T>>(100);
			BiNode<T> *p = pRoot;
			while (p != NULL || !s->stackEmpty()) {
				if (p != NULL) {
					s->push(p);
					p = p->lChild;
				}
				else {
					s->pop(p);
					cout << p->data << " ";
					p = p->rChild;
				}
			}
			delete s;
			s = NULL;
		}
	}
}

// 层序遍历二叉树
template <class T>
void BiTree<T>::LevelOrderTraverse(BiNode<T> *pRoot) {
	if (pRoot) {
		BiNode<T> *p = NULL;
		Queue<BiNode<T>> *q = new Queue<BiNode<T>>(30);
		q->EnQueue(pRoot);
		while (!q->QueueEmpty()) {
			q->DeQueue(p);
			cout << p->data << "  ";

			if (p->lChild)
				q->EnQueue(p->lChild);
			if (p->rChild)
				q->EnQueue(p->rChild);
		}
		delete q;
		q = NULL;
	}
}

// 获取根节点
template <class T>
BiNode<T> *BiTree<T>::GetRoot() {
	return m_pRoot;
}

// 求两个结点的最大公共祖先
template <class T>
void BiTree<T>::Ancestor() {

}

#endif
