#pragma once

#include <vector>

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

private:
	bool getValueFromMatrix(int row, int col, int &val);
	void breadthFirstTraverseImpl(vector<int> preVec);

private:
	int m_iCapacity;
	int m_iNodeCount;
	MapNode<T> *m_pNodeArray;
	int *m_pMatrix;
};