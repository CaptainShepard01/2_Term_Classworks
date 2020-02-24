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
			tail = node; head = node;
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

	Node* find(int key)
	{
		Node* cur = head;
		while (cur)
		{
			if (cur->info.num == key)break;
			cur = cur->next;
		}
		return cur;
	}

	Node* insert(int key, Autobus ins)
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

	bool remove(int key)
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
		//while (0)continue;
		cin >> cur.route;
		cin.clear();
		while (cin.get() != '\n')continue;
		cur.num = i + 1;
		f.write((char*)&cur, sizeof(Autobus));
	}
	f.close();
}

void busReader(int& count)
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
		cout << "Number: " << tmp.num << endl;
		cout << "Fio: " << tmp.fio << endl;
		cout << "Route number: " << tmp.route << endl << endl;;
	}
	f1.close();
	return;

}

int main()
{
	const int d = 5;
	//busAdder(d);
	int buscnt = 0;
	cout << "Buses:\n\n";
	//Autobus* buses = new Autobus[buscnt];
	//busReader(buscnt);

	ifstream f("Buses.bin", ios::binary);
	int cnt = 0;
	Autobus tmp;
	while (f.read((char*)&tmp, sizeof(Autobus))) {
		cnt++;
	}
	f.close();

	//TODO seekg algorithm and logic to understand!!

	ifstream f1("Buses.bin", ios::binary);
	Autobus* mas = new Autobus[cnt];
	for (int i = 0; i < cnt; ++i) {
		f1.read((char*)&mas[i], sizeof(Autobus));
	}
	f1.close();

	for (int i = 0; i < cnt; ++i) {
		cout << "Number: " << mas[i].num << endl;
		cout << "Fio: " << mas[i].fio << endl;
		cout << "Route number: " << mas[i].route << endl << endl;
	}
	cout << "Total: " << cnt << " buses." << endl;

	NodeList Routes, Park;
	cout << "Which autobus would u like to send on route?\n";
	int key = 0;
	bool flag = 0;
	do {
		cin >> key;
		for (int i = 0; i < cnt; ++i) {
			if (key == mas[i].num) {
				Routes.addLast(mas[i]);
				flag = true;
				break;
			}
		}
	} while (!flag);
	delete[] mas;
	return 0;
}
