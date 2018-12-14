#pragma once

#include <vector>

//顶点
template <class T>
class MapNode {
public:
	MapNode(T data = 0) {
		m_tData = data;
		m_bIsVisited = false;
	}

	T m_tData;
	bool m_bIsVisited;
};

//边
class Edge {
public:
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0) :
		m_iNodeIndexA(nodeIndexA), m_iNodeIndexB(nodeIndexB), 
		m_iWeightValue(weightValue), m_bSelected(false) {

	}
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;
	bool m_bSelected;
};

//图
template <class T> 
class Map {
public:
	Map(int capacity);
	~Map();

	bool addNode(MapNode<T> * pNode);
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);

	bool printMatrix();

	void depthFirestTraverse(int nodeIndex);
	void breadthFirestTraverse(int nodeIndex);

	void primTree(int nodeIndex); //prim生成树
	void kruskalTree();//kruskalTree生成树

private:
	bool getValueFromMatrix(int row, int col, int &val);
	int getMinEdge(vector<Edge> edgeVec);

	bool isInSet(vector<int> nodeVec, int index);
	void mergeNodeSet(vector<vector<int>> &nodeSets, int indexA, int indexB);

private:
	int m_iCapacity;
	int m_iNodeCount;
	MapNode<T> *m_pNodeArray;
	int *m_pMatrix;

	Edge *m_pEdge;//存最小生成树的边
};