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

	int data[10] = { 154, 5, 37, 56, 8, 72, 1233, 649, 1, 6 };
	int n = 10;
	for (int i = 0; i < n; i++) {
		cout << data[i] << ", ";
	}
	cout << endl;
	RadixSort(data, n);
	for (int i = 0; i < n; i++) {
		cout << data[i] << ", ";
	}
	cout << endl;
}