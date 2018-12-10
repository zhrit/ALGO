#ifndef TREE_H
#define TREE_H

// ˳�򴢴�ṹ������
template <class T>
class Tree_A{
public:
	Tree_A(int size, T *pRoot);
	~Tree_A();
	// ��������Ѱ�ҽ��
	T *SearchNode(int nodeIndex);
	// ��ӽ��
	bool AddNode(int nodeIndex, int direction, T *pNode);
	// ɾ�����
	bool DeleteNode(int nodeIndex, T *pNode);
	// �������
	void TreeTraverse();

private:
	T *m_pTree;
	int m_iSize;
};

// ��ʽ����ṹ������
template <class T>
class BiTree {
public:
	BiTree();
	~BiTree();
	// ����������
	void CreateBiTree(T data[], int num, T emptyData, int index = 0);
	// ���ٶ�����
	void DestroyBiTree(BiTree<T> *biNode = m_pRoot);
	// ��ȡ���
	int GetDepth(BiNode<T> *pRoot = m_pRoot);
	// ��ȡ������
	int GetNodeNum(BiNode<T> *pRoot = m_pRoot);
	// ��ȡҶ�ӽ��ĸ���
	int GetLeafNodeNum(BiNode<T> *pRoot = m_pRoot);
	// �Ƿ�Ϊƽ�������
	bool IsAVL(BiNode<T> *pRoot = m_pRoot, int *pHeight = NULL);
	// ǰ�����������
	void PreOrderTraverse(BiNode<T> *pRoot = m_pRoot, bool brec = true);
	// �������������
	void InOrderTraverse(BiNode<T> *pRoot = m_pRoot, bool brec = true);
	// �������������
	void PostOrderTraverse(BiNode<T> *pRoot = m_pRoot, bool brec = true);
	// �������������
	void LevelOrderTraverse(BiNode<T> *pRoot = m_pRoot);
	// ��ȡ���ڵ�
	BiNode<T> *GetRoot();
	// ������������󹫹�����
	void Ancestor();
private:
	BiNode<T> *create(T data[], int num, T emptyData, int &pos, int index);
	BiNode<T> *m_pRoot;
};

#endif
