#include "pch.h"
#include "MyStackDef.h"
#include <iostream>
using namespace std;

#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16

// ½øÖÆ×ª»»
void sysconvert(int n, int ind) {
	char num[] = "0123456789ABCDEF";

	MyStack<int> *pStack = new MyStack<int>(30);

	int mod = 0, k = 0;

	do {
		mod = n % ind;
		pStack->push(&mod);
		n = n / ind;
	} while (n != 0);

	while (!pStack->stackEmpty()) {
		k = 0;
		pStack->pop(&k);
		cout << num[k];
	}

	delete pStack;
	pStack = NULL;
}

// À¨ºÅÆ¥Åä
void bracketMatching(char *str) {
	MyStack<char> *pStack = new MyStack<char>(30);
	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char currentNeed = 0;

	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] != currentNeed) {
			pStack->push(&str[i]);
			switch (str[i]) {
			case '[':
				if (currentNeed != 0) {
					pNeedStack->push(&currentNeed);
				}
				currentNeed = ']';
				break;
			case '(':
				if (currentNeed != 0) {
					pNeedStack->push(&currentNeed);
				}
				currentNeed = ')';
				break;
			default:
				cout << "À¨ºÅ²»Æ¥Åä" << endl;
				return;
			}
		}
		else {
			char elem;
			pStack->pop(&elem);
			if (!pNeedStack->pop(&currentNeed)) {
				currentNeed = 0;
			}
		}
	}

	if (pStack->stackEmpty()) {
		cout << "À¨ºÅÆ¥Åä" << endl;
	}
	else {
		cout << "À¨ºÅ²»Æ¥Åä" << endl;
	}

	delete pStack;
	delete pNeedStack;
	pStack = NULL;
	pNeedStack = NULL;
}
