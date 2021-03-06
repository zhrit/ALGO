// ALGO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "ListDef.h"
#include "Person.h"
#include "MyStackDef.h"
#include "Coordinate.h"
#include "QueueDef.h"
#include "TreeDef.h"
#include <string>
#include <iostream>
#include "Sort.h"
#include "AVLDef.h"
#include "MapDef.h"

int initPhoneBook();
void sysconvert(int n, int ind);
void bracketMatching(char *str);
#define SQUARE(X) X*X
int main()
{
	//// 建立通讯录
	//initPhoneBook();

	// 栈测试
	//MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);
	//cout << pStack->stackEmpty() << endl;
	//Coordinate e1(1,2), e2(3, 4);
	//pStack->push(&e1);
	//pStack->push(&e2);
	//pStack->stackTraversel();
	//delete pStack;
	//pStack = NULL;
	//return 0;

	//sysconvert(1348, 2);

	/*char str[] = "[()[()]()]";
	bracketMatching(str);*/

	//// 队列测试
	//Queue<int> *p = new Queue<int>(4);
	//int e1 = 10, e2 = 12, e3 = 16, e4 = 18, e5 = 20, e6;
	//p->EnQueue(&e1);
	//p->EnQueue(&e2);
	//p->EnQueue(&e3);
	//p->EnQueue(&e4);
	//p->EnQueue(&e5);

	//p->QueueTraverse();

	//p->DeQueue(&e6);
	//p->DeQueue(&e6);
	//p->QueueTraverse();
	//p->ClearQueue();
	//p->QueueTraverse();
	//p->EnQueue(&e5);
	//p->QueueTraverse();

	// 顺序结构二叉树测试
	/*int root = 1, node1 = 5, node2 = 8, node3 = 2, node4 = 6, node5 = 9, node6 = 7;
	Tree_A<int> *pTree = new Tree_A<int>(10, &root);
	pTree->AddNode(0, 0, &node1);
	pTree->AddNode(0, 1, &node2);
	pTree->AddNode(1, 0, &node3);
	pTree->AddNode(1, 1, &node4);
	pTree->AddNode(2, 0, &node5);
	pTree->AddNode(2, 1, &node6);
	pTree->TreeTraverse();
	int *p = pTree->SearchNode(2);
	cout << *p << endl;
	int node;
	pTree->DeleteNode(6, &node);
	pTree->TreeTraverse();
	delete pTree;
	pTree = NULL;*/

	//int data[10] = { 154, 5, 37, 56, 8, 72, 1233, 649, 1, 6 };
	//int n = 10;
	//for (int i = 0; i < n; i++) {
	//	cout << data[i] << ", ";
	//}
	//cout << endl;
	//RadixSort(data, n);
	//for (int i = 0; i < n; i++) {
	//	cout << data[i] << ", ";
	//}
	//cout << endl;

	////AVL树测试
	//AVLTree<int> *t = new AVLTree<int>();
	//t->Insert(3);
	//t->LevelOrderTraverse();
	//t->Insert(2);
	//t->LevelOrderTraverse();
	//t->Insert(1);
	//t->LevelOrderTraverse();
	//t->Insert(4);
	//t->LevelOrderTraverse();
	//t->Insert(5);
	//t->LevelOrderTraverse();
	//t->Insert(6);
	//t->LevelOrderTraverse();
	//t->Insert(7);
	//t->LevelOrderTraverse();
	//t->Insert(16);
	//t->LevelOrderTraverse();
	//t->Insert(15);
	//t->LevelOrderTraverse();
	//t->Insert(14);
	//t->LevelOrderTraverse();
	//t->Insert(13);
	//t->LevelOrderTraverse();
	//t->Insert(12);
	//t->LevelOrderTraverse();
	//t->Insert(11);
	//t->LevelOrderTraverse();
	//t->Insert(10);
	//t->LevelOrderTraverse();
	//t->Insert(8);
	//t->LevelOrderTraverse();
	//t->Insert(9);
	//t->LevelOrderTraverse();
	//t->Remove(12);
	//t->LevelOrderTraverse();


	//Map<char> *pMap = new Map<char>(10);
	//MapNode<char> *pNodeA = new MapNode<char>('A');
	//MapNode<char> *pNodeB = new MapNode<char>('B');
	//MapNode<char> *pNodeC = new MapNode<char>('C');
	//MapNode<char> *pNodeD = new MapNode<char>('D');
	//MapNode<char> *pNodeE = new MapNode<char>('E');
	//MapNode<char> *pNodeF = new MapNode<char>('F');
	//MapNode<char> *pNodeG = new MapNode<char>('G');
	//MapNode<char> *pNodeH = new MapNode<char>('H');

	//pMap->addNode(pNodeA);
	//pMap->addNode(pNodeB);
	//pMap->addNode(pNodeC);
	//pMap->addNode(pNodeD);
	//pMap->addNode(pNodeE);
	//pMap->addNode(pNodeF);
	//pMap->addNode(pNodeG);
	//pMap->addNode(pNodeH);

	//pMap->setValueToMatrixForUndirectedGraph(0, 1);
	//pMap->setValueToMatrixForUndirectedGraph(0, 3);
	//pMap->setValueToMatrixForUndirectedGraph(1, 2);
	//pMap->setValueToMatrixForUndirectedGraph(1, 5);
	//pMap->setValueToMatrixForUndirectedGraph(3, 6);
	//pMap->setValueToMatrixForUndirectedGraph(3, 7);
	//pMap->setValueToMatrixForUndirectedGraph(6, 7);
	//pMap->setValueToMatrixForUndirectedGraph(2, 4);
	//pMap->setValueToMatrixForUndirectedGraph(0, 7);
	//pMap->setValueToMatrixForUndirectedGraph(4, 5);

	//pMap->printMatrix();
	//cout << endl;

	//pMap->resetNode();
	//pMap->depthFirestTraverse(0);
	//cout << endl;

	//pMap->resetNode();
	//pMap->breadthFirestTraverse(7);
	//cout << endl;

	Map<char> *pMap = new Map<char>(10);
	MapNode<char> *pNodeA = new MapNode<char>('A');
	MapNode<char> *pNodeB = new MapNode<char>('B');
	MapNode<char> *pNodeC = new MapNode<char>('C');
	MapNode<char> *pNodeD = new MapNode<char>('D');
	MapNode<char> *pNodeE = new MapNode<char>('E');
	MapNode<char> *pNodeF = new MapNode<char>('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);

	pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);
	pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);
	pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 4);
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);

	pMap->printMatrix();
	cout << endl;

	pMap->resetNode();
	pMap->depthFirestTraverse(0);
	cout << endl;

	pMap->resetNode();
	pMap->breadthFirestTraverse(0);
	cout << endl;

	pMap->resetNode();
	pMap->primTree(0);
	cout << endl;

	pMap->resetNode();
	pMap->kruskalTree();
	cout << endl;
}