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
	Autobus info;
	Node* next;
	Node* prev;
};

struct NodeList {
	Node* head;
	Node* tail;

	void addLast(Autobus i) {
		Node* node = new Node;
		node->info = i;
		node->next = NULL;
		if (head == NULL) {
			tail = node;head = node;
		}
		else {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}

	void addFirst(Autobus i) {
		Node* node = new Node;
		node->info = i;
		node->next = NULL;
		if (head == NULL) {
			head = node; tail = node;
		}
		else {
			node->next = head;
			head->prev = node;
			head = node;
		}
	}

	Node* find(Autobus key)
	{
		Node* cur = head;
		while (cur)
		{
			if (cur->info.num == key.num)break;
			cur = cur->next;
		}
		return cur;
	}

	Node* insert(Autobus key, Autobus ins)
	{
		if (Node* pkey = find(key)) {
			Node* cur = new Node;
			cur->info = ins;
			cur->next = pkey->next;
			cur->prev = pkey;
			pkey->next = cur;
			if (pkey != tail)(cur->next)->prev = cur;
			else tail = cur;
			return cur;
		}
		return 0;
	}

	bool remove(Autobus key)
	{
		if (Node* pkey = find(key)) {
			if (pkey == head) {
				head = (head)->next;
				(head)->prev = 0;
			}
			else if (pkey == tail) {
				tail = (tail)->prev;
				(tail)->next = 0;
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
};

void busAdder(int d)
{
	ofstream f("Buses.bin", ios::binary);
	Autobus cur;
	for (int i = 0; i < d; ++i) {
		cout << "Enter fio of the driver: ";
		cin.clear();
		
		cin.getline(cur.fio, 100);
		cout << "Enter number of route: ";
		cin.clear();
		while (0)continue;
		cin >> cur.route;
		cin.clear();
		while (cin.get() != '\n')continue;
		cur.num = i;
		f.write((char*)&cur, sizeof(Autobus));
	}
	f.close();
}

Autobus* busReader(int& count)
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
	f.close();
	count = cnt;
	ifstream f1("Buses.bin", ios::binary);
	
	for (int i = 0; i < cnt; ++i) {
		f1.read((char*)&tmp, sizeof(Autobus));
		cout << tmp.fio << endl;
		cout << tmp.route << endl << endl;
	}
	f1.close();
	return mas;
	
}

int main()
{
	const int d = 10;
	//busAdder(3);
	int buscnt = 0;
	busReader(buscnt);
	return 0;
}
