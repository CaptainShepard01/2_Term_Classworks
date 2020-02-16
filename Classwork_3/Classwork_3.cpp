#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <direct.h>
#include <cstdlib>
//#include "Header.h"
using namespace std;

struct Autobus
{
	int num;
	char fio[100];
	int route;
};

struct Autopark
{
	Autobus aut;
	Autopark* next;
	Autopark* prev;
};

struct Routes
{
	Autobus aut;
	Routes* next;
	Routes* prev;
};

struct Node {
	Autobus aut;
	Node* next;
	Node* prev;
};

struct NodeList {
	Node* head;

};

Node* first(Autobus a) {
	Node* cur = new Node;
	cur->aut = a;
	cur->next = 0;
	cur->prev = 0;
	return cur;
}

/*Routes* firstRoutes(Autobus a) {
	Routes* cur = new Routes;
	cur->aut = a;
	cur->next = 0;
	cur->prev = 0;
	return cur;
}
*/

void add(Node** pend, Autobus b)
{
	Node* cur = new Node;
	cur->aut = b;
	cur->next = 0;
	cur->prev = *pend;
	(*pend)->next = cur;
	*pend = cur;
}

/*void addRoutes(Routes** pend, Autobus b)
{
	Routes* cur = new Routes;
	cur->aut = b;
	cur->next = 0;
	cur->prev = *pend;
	(*pend)->next = cur;
	*pend = cur;
}*/

Node* find(Node* const pbeg, Autobus key)
{
	Node* cur = pbeg;
	while (cur)
	{
		if (cur->aut.num == key.num)break;
		cur = cur->next;
	}
	return cur;
}

/*Routes* findRoutes(Routes* const pbeg, Autobus key)
{
	Routes* cur = pbeg;
	while (cur)
	{
		if (cur->aut.num == key.num)break;
		cur = cur->next;
	}
	return cur;
}*/

bool remove(Node** pbeg, Node** pend, Autobus key)
{
	if (Node* pkey = find(*pbeg, key)) {
		if (pkey == *pbeg) {
			*pbeg = (*pbeg)->next;
			(*pbeg)->next = 0;
		}
		else if (pkey == *pend) {
			*pend = (*pend)->prev;
			(*pend)->next = 0;
		}
		else {
			(pkey->prev)->next = pkey->next;
			(pkey->next)->prev = pkey->prev;
		}
		delete pkey;
		return true;
	}
	return false;
}

/*bool removeRoutes(Routes** pbeg, Routes** pend, Autobus key)
{
	if (Routes* pkey = findRoutes(*pbeg, key)) {
		if (pkey == *pbeg) {
			*pbeg = (*pbeg)->next;
			(*pbeg)->next = 0;
		}
		else if (pkey == *pend) {
			*pend = (*pend)->prev;
			(*pend)->next = 0;
		}
		else {
			(pkey->prev)->next = pkey->next;
			(pkey->next)->prev = pkey->prev;
		}
		delete pkey;
		return true;
	}
	return false;
}*/

Node* insert(Node* const pbeg, Node** pend, Autobus key, Autobus ins)
{
	if (Node* pkey = find(pbeg, key)) {
		Node* cur = new Node;
		cur->aut = ins;
		cur->next = pkey->next;
		cur->prev = pkey;
		pkey->next = cur;
		if (pkey != *pend)(cur->next)->prev = cur;
		else *pend = cur;
		return cur;
	}
	return 0;
}

/*Routes* insertRoutes(Routes* const pbeg, Routes** pend, Autobus key, Autobus ins)
{
	if (Routes* pkey = findRoutes(pbeg, key)) {
		Routes* cur = new Routes;
		cur->aut = ins;
		cur->next = pkey->next;
		cur->prev = pkey;
		pkey->next = cur;
		if (pkey != *pend)(cur->next)->prev = cur;
		else *pend = cur;
		return cur;
	}
	return 0;
}*/

void busAdder(int d)
{
	ofstream f("Buses.bin", ios::binary, ios::app);
	Autobus cur;
	for (int i = 0; i < d; ++i) {
		cout << "Enter fio of the driver: ";
		cin.clear;
		cin.getline(cur.fio, 100);
		cout << "Enter number of route: ";
		cin.clear();
		cin >> cur.route;
		cur.num = i;
		f.write((char*)&cur, sizeof(Autobus));
	}
	
	f.close();
}

Autobus* busReader(int &count) 
{
	ifstream f("Buses.bin", ios::binary);
	int cnt = 0;
	Autobus tmp;
	while (f.read((char*)&tmp, sizeof(Autobus))) {
		cnt++;
	}
	f.seekg(0);
	Autobus* mas = new Autobus[cnt];
	for (int i = 0; i < cnt; ++i) {
		f.read((char*)&mas[i], sizeof(Autobus));
	}
	delete[]mas;
	f.close();
	count = cnt;
	return mas;
}

int main()
{

	return 0;
}
