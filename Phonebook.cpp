#include "pch.h"
#include <stdlib.h>
#include "ListDef.h"
#include "Person.h"
#include <iostream>
using namespace std;

int menu();
void createPerson(LList<Person> *);
void deletePerson(LList<Person> *);
void checkPhoneBook(LList<Person> *);

// 初始化通讯录，不包含数据库
int  initPhoneBook() {
	int userOrder = 0;

	// 建立通讯录
	LList<Person> *pList = new LList<Person>();

	while (userOrder != 4) {
		userOrder = menu();
		switch (userOrder) {
		case 1:
			cout << "用户指令 ---> 新建联系人: " << endl;
			createPerson(pList);
			break;
		case 2:
			cout << "用户指令 ---> 删除联系人: " << endl;
			deletePerson(pList);
			break;
		case 3:
			cout << "用户指令 ---> 浏览通讯录: " << endl;
			checkPhoneBook(pList);
			break;
		case 4:
			cout << "用户指令 ---> 退出通讯录: " << endl;
			break;
		default:
			cout << "不合法的操作！" << endl;
			break;
		}
		cout << endl;
	}
	// 推出通讯录
	delete pList;
	pList = NULL;

	return 0;
}

// 菜单
int menu() {
	cout << "菜单功能" << endl;
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;

	cout << "请输入： ";

	int order = 0;
	cin >> order;
	return order;
}

// 新建联系人
void createPerson(LList<Person> *pList) {
	Node<Person> newPerson;
	cout << "请输入姓名： ";
	cin >> newPerson.data.name;
	cout << "请输入电话： ";
	cin >> newPerson.data.phone;
	pList->ListInsertTail(&newPerson);
}

//  浏览通讯录
void checkPhoneBook(LList<Person> *pList) {
	pList->ListTraversel();
}

// 删除联系人
void deletePerson(LList<Person> *pList) {
	Node<Person> newPerson;
	cout << "请输入姓名： ";
	cin >> newPerson.data.name;
	cout << "请输入电话： ";
	cin >> newPerson.data.phone;
	int l = pList->LocateElem(&newPerson);
	if (l == -1) {
		cout << "通讯录中不存在该条记录" << endl;
		return;
	}
	pList->ListDelete(l, &newPerson);
}
