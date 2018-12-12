#pragma once

#define EH 0
#define LH 1
#define RH -1

template <class T>
class BitNode {
public:
	T data; //Êý¾Ý
	int height; //Ê÷¸ß
	BitNode<T> *lchild, *rchild;

	BitNode(){}

	BitNode(T data, BitNode<T> *l, BitNode<T> *r) : 
		data(data), height(0), lchild(l), rchild(r) {

	}
};

template <class T>
class AVLTree {
public:
	AVLTree();

	virtual ~AVLTree();

	void Destroy();

	int Height() const;
	int Height(BitNode<T> *pNode) const;

	T max(T a, T b);

	BitNode<T>* Search(T data, BitNode<T> *pNode) const;
	BitNode<T>* Search(T data) const;

	void Insert(T data);

	BitNode<T>* Insert(BitNode<T>* &pNode, T data);

	void Remove(T data);
	BitNode<T>* Remove(BitNode<T>* &pNode, BitNode<T>* d);

	void InOrderTraverse();

	void LevelOrderTraverse();

private:
	void destroy(BitNode<T> *node);
	void inOrder(BitNode<T> *node);

	BitNode<T>* rotateLL(BitNode<T> *node);
	BitNode<T>* rotateRR(BitNode<T> *node);
	BitNode<T>* rotateLR(BitNode<T> *node);
	BitNode<T>* rotateRL(BitNode<T> *node);

	BitNode<T>* maxNode(BitNode<T>* pNode);
	BitNode<T>* minNode(BitNode<T>* pNode);

private:
	BitNode<T> *m_pRoot;
};
