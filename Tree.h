#ifndef TREE_H
#define TREE_H

// 顺序储存结构二叉树
template <class T>
class Tree_A{
public:
	Tree_A(int size, T *pRoot);
	~Tree_A();
	// 根据索引寻找结点
	T *SearchNode(int nodeIndex);
	// 添加结点
	bool AddNode(int nodeIndex, int direction, T *pNode);
	// 删除结点
	bool DeleteNode(int nodeIndex, T *pNode);
	// 遍历结点
	void TreeTraverse();

private:
	T *m_pTree;
	int m_iSize;
};

// 链式储存结构二叉树
template <class T>
class BiTree {
public:
	BiTree();
	~BiTree();
	// 创建二叉树
	void CreateBiTree(T data[], int num, T emptyData, int index = 0);
	// 销毁二叉树
	void DestroyBiTree(BiTree<T> *biNode = m_pRoot);
	// 获取深度
	int GetDepth(BiNode<T> *pRoot = m_pRoot);
	// 获取结点个数
	int GetNodeNum(BiNode<T> *pRoot = m_pRoot);
	// 获取叶子结点的个数
	int GetLeafNodeNum(BiNode<T> *pRoot = m_pRoot);
	// 是否为平衡二叉树
	bool IsAVL(BiNode<T> *pRoot = m_pRoot, int *pHeight = NULL);
	// 前序遍历二叉树
	void PreOrderTraverse(BiNode<T> *pRoot = m_pRoot, bool brec = true);
	// 中序遍历二叉树
	void InOrderTraverse(BiNode<T> *pRoot = m_pRoot, bool brec = true);
	// 后序遍历二叉树
	void PostOrderTraverse(BiNode<T> *pRoot = m_pRoot, bool brec = true);
	// 层序遍历二叉树
	void LevelOrderTraverse(BiNode<T> *pRoot = m_pRoot);
	// 获取根节点
	BiNode<T> *GetRoot();
	// 求两个结点的最大公共祖先
	void Ancestor();
private:
	BiNode<T> *create(T data[], int num, T emptyData, int &pos, int index);
	BiNode<T> *m_pRoot;
};

#endif
