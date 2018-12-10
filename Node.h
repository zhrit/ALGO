#ifndef NODE_H
#define NODE_H

// 结点
template <class T>
class Node {
public:
	T data;
	Node *next;
	void printNode();
};

// 二叉树中结点
template <class T>
class BiNode {
public:
	T data;
	BiNode *lChild, *rChild;
};

#endif
