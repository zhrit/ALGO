#ifndef NODE_H
#define NODE_H

// ���
template <class T>
class Node {
public:
	T data;
	Node *next;
	void printNode();
};

// �������н��
template <class T>
class BiNode {
public:
	T data;
	BiNode *lChild, *rChild;
};

#endif
