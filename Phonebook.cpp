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

// ��ʼ��ͨѶ¼�����������ݿ�
int  initPhoneBook() {
	int userOrder = 0;

	// ����ͨѶ¼
	LList<Person> *pList = new LList<Person>();

	while (userOrder != 4) {
		userOrder = menu();
		switch (userOrder) {
		case 1:
			cout << "�û�ָ�� ---> �½���ϵ��: " << endl;
			createPerson(pList);
			break;
		case 2:
			cout << "�û�ָ�� ---> ɾ����ϵ��: " << endl;
			deletePerson(pList);
			break;
		case 3:
			cout << "�û�ָ�� ---> ���ͨѶ¼: " << endl;
			checkPhoneBook(pList);
			break;
		case 4:
			cout << "�û�ָ�� ---> �˳�ͨѶ¼: " << endl;
			break;
		default:
			cout << "���Ϸ��Ĳ�����" << endl;
			break;
		}
		cout << endl;
	}
	// �Ƴ�ͨѶ¼
	delete pList;
	pList = NULL;

	return 0;
}

// �˵�
int menu() {
	cout << "�˵�����" << endl;
	cout << "1.�½���ϵ��" << endl;
	cout << "2.ɾ����ϵ��" << endl;
	cout << "3.���ͨѶ¼" << endl;
	cout << "4.�˳�ͨѶ¼" << endl;

	cout << "�����룺 ";

	int order = 0;
	cin >> order;
	return order;
}

// �½���ϵ��
void createPerson(LList<Person> *pList) {
	Node<Person> newPerson;
	cout << "������������ ";
	cin >> newPerson.data.name;
	cout << "������绰�� ";
	cin >> newPerson.data.phone;
	pList->ListInsertTail(&newPerson);
}

//  ���ͨѶ¼
void checkPhoneBook(LList<Person> *pList) {
	pList->ListTraversel();
}

// ɾ����ϵ��
void deletePerson(LList<Person> *pList) {
	Node<Person> newPerson;
	cout << "������������ ";
	cin >> newPerson.data.name;
	cout << "������绰�� ";
	cin >> newPerson.data.phone;
	int l = pList->LocateElem(&newPerson);
	if (l == -1) {
		cout << "ͨѶ¼�в����ڸ�����¼" << endl;
		return;
	}
	pList->ListDelete(l, &newPerson);
}
