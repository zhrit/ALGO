#pragma once

#include "Map.h"
#include "QueueDef.h"
#include <iostream>

using namespace std;

template <class T>
Map<T>::Map(int capacity) {
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new MapNode<char>[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	memset(m_pMatrix, 0, m_iCapacity * m_iCapacity * sizeof(int));

	m_pEdge = new Edge[m_iCapacity - 1];
}

template <class T>
Map<T>::~Map() {
	delete[] m_pNodeArray;
	delete[] m_pMatrix;
	delete[] m_pEdge;
}

template <class T>
bool Map<T>::addNode(MapNode<T> * pNode) {
	if (m_iNodeCount >= m_iCapacity) return false;
	m_pNodeArray[m_iNodeCount].m_tData = pNode->m_tData;
	m_iNodeCount++;
	return true;
}

template <class T>
void Map<T>::resetNode() {
	for (int i = 0; i < m_iNodeCount; i++) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

template <class T>
bool Map<T>::setValueToMatrixForDirectedGraph(int row, int col, int val) {
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

template <class T>
bool Map<T>::setValueToMatrixForUndirectedGraph(int row, int col, int val) {
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

template <class T>
bool Map<T>::printMatrix() {
	for (int i = 0; i < m_iNodeCount; i++) {
		for (int j = 0; j < m_iNodeCount; j++) {
			cout << m_pMatrix[i * m_iCapacity + j] << " ";
		}
		cout << endl;
	}
	return true;
}

template <class T>
void Map<T>::depthFirestTraverse(int nodeIndex) {
	if (m_pNodeArray[nodeIndex].m_bIsVisited) {
		return;
	}
	cout << m_pNodeArray[nodeIndex].m_tData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	for (int i = 0; i < m_iNodeCount; i++) {
		int val;
		getValueFromMatrix(nodeIndex, i, val);
		if (val != 0) {
			depthFirestTraverse(i);
		}
	}
}

template <class T>
void Map<T>::breadthFirestTraverse(int nodeIndex) {
	Queue<int> *q = new Queue<int>(10 * m_iNodeCount);
	q->EnQueue(&nodeIndex);

	int ind;
	while (!q->QueueEmpty()) {
		q->DeQueue(&ind);
		if (!m_pNodeArray[ind].m_bIsVisited) {
			cout << m_pNodeArray[ind].m_tData << " ";
			m_pNodeArray[ind].m_bIsVisited = true;
			for (int i = 0; i < m_iNodeCount; i++) {
				int val;
				getValueFromMatrix(ind, i, val);
				if (val != 0) {
					q->EnQueue(&i);
				}
			}
		}
	}
}

template <class T>
bool Map<T>::getValueFromMatrix(int row, int col, int &val) {
	if (row >= m_iNodeCount || col >= m_iNodeCount) return false;
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

template <class T>
void Map<T>::primTree(int nodeIndex) {
	int value = 0;//边的权值
	int edgeCount = 0;//边计数器
	vector<int> nodeVec;//点的索引
	vector<Edge> edgeVec;//备选边的集合

	cout << m_pNodeArray[nodeIndex].m_tData << endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	while (edgeCount < m_iNodeCount - 1) {
		int temp = nodeVec.back();

		for (int i = 0; i < m_iNodeCount; i++) {
			getValueFromMatrix(temp, i, value);
			if (value != 0) {
				if (m_pNodeArray[i].m_bIsVisited) {
					continue;
				}
				else {
					Edge edge(temp, i, value);
					edgeVec.push_back(edge);
				}
			}
		}

		// 从可选边集合中选出最小边
		int edgeIndex = getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected = true;

		cout << m_pNodeArray[edgeVec[edgeIndex].m_iNodeIndexA].m_tData << "---" <<
			m_pNodeArray[edgeVec[edgeIndex].m_iNodeIndexB].m_tData << " " << edgeVec[edgeIndex].m_iWeightValue << endl;

		m_pEdge[edgeCount++] = edgeVec[edgeIndex];

		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		cout << m_pNodeArray[nextNodeIndex].m_tData << endl;
	}
}

template <class T>
int Map<T>::getMinEdge(vector<Edge> edgeVec) {
	int minWeight = 0;
	int index = 0;
	int i;
	for (i = 0; i < (int)edgeVec.size(); i++) {
		if (!edgeVec[i].m_bSelected) {
			minWeight = edgeVec[i].m_iWeightValue;
			index = i;
			break;
		}
	}

	if (minWeight == 0) {
		return -1;
	}

	for (; i < (int)edgeVec.size(); i++) {
		if (!edgeVec[i].m_bSelected && 
			edgeVec[i].m_iWeightValue < minWeight) {
			minWeight = edgeVec[i].m_iWeightValue;
			index = i;
		}
	}

	return index;
}

template <class T>
void Map<T>::kruskalTree() {
	int value = 0;
	int edgeCount = 0;
	vector<vector<int>> nodeSets;

	//取出所有边
	vector<Edge> edgeVec;
	for (int i = 0; i < m_iNodeCount; i++) {
		for (int j = i + 1; j < m_iNodeCount; j++) {
			getValueFromMatrix(i, j, value);
			if (value != 0) {
				Edge edge(i, j, value);
				edgeVec.push_back(edge);
			}
		}
	}

	while (edgeCount < m_iNodeCount - 1) {
		//从边集合中选出最小边
		int minEdgeIndex = getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected = true;

		//找出最小边连接的点的索引
		int nodeAIndex = edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex = edgeVec[minEdgeIndex].m_iNodeIndexB;

		//找出点所在的集合
		bool nodeAIsInSet = false;
		bool nodeBIsInSet = false;

		int nodeAInSetLabel = -1;
		int nodeBInSetLabel = -1;

		for (int i = 0; i < (int)nodeSets.size(); i++) {
			nodeAIsInSet = isInSet(nodeSets[i], nodeAIndex);
			if (nodeAIsInSet) {
				nodeAInSetLabel = i;
			}
		}

		for (int i = 0; i < (int)nodeSets.size(); i++) {
			nodeBIsInSet = isInSet(nodeSets[i], nodeBIndex);
			if (nodeBIsInSet) {
				nodeBInSetLabel = i;
			}
		}

		//根据点所在集合的不同做出不同处理
		if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1) {
			//AB不存在于任何集合中
			vector<int> nodeVec;
			nodeVec.push_back(nodeAIndex);
			nodeVec.push_back(nodeBIndex);
			nodeSets.push_back(nodeVec);

			m_pEdge[edgeCount++] = edgeVec[minEdgeIndex];
		}
		else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1) {
			//A不在集合中，B在集合中
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);

			m_pEdge[edgeCount++] = edgeVec[minEdgeIndex];
		}
		else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1) {
			//B不在集合中，A在集合中
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);

			m_pEdge[edgeCount++] = edgeVec[minEdgeIndex];
		}
		else if (nodeAInSetLabel == nodeBInSetLabel) {
			//AB在同一个集合中
			//do nothing
			continue;
		}
		else {
			//AB在不同集合中
			mergeNodeSet(nodeSets, nodeAInSetLabel, nodeBInSetLabel);

			m_pEdge[edgeCount++] = edgeVec[minEdgeIndex];
		}

		cout << m_pNodeArray[edgeVec[minEdgeIndex].m_iNodeIndexA].m_tData << "---" <<
			m_pNodeArray[edgeVec[minEdgeIndex].m_iNodeIndexB].m_tData << " " << 
			edgeVec[minEdgeIndex].m_iWeightValue << endl;
	}
}

template <class T>
bool Map<T>::isInSet(vector<int> nodeVec, int index) {
	for (int item : nodeVec) {
		if (item == index) {
			return true;
		}
	}
	return false;
}

template <class T>
void Map<T>::mergeNodeSet(vector<vector<int>> &nodeSets, int indexA, int indexB) {
	nodeSets[indexA].insert(nodeSets[indexA].end(), nodeSets[indexB].begin(), nodeSets[indexB].end());
	vector<vector<int>>::iterator k = nodeSets.begin() + indexB;
	nodeSets.erase(k);
}