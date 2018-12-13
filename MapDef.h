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
}

template <class T>
Map<T>::~Map() {
	delete[] m_pNodeArray;
	delete[] m_pMatrix;
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
		if (val == 1) {
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
				if (val == 1) {
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
void Map<T>::breadthFirstTraverseImpl(vector<int> preVec) {

}