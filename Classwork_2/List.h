#pragma once
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include "Header.h"


using namespace std;

struct dict {
	char angl[100] = {};
	char rus[100] = {};
};

struct Node {
	dict info;
	Node* next = NULL;
	Node* prev = NULL;
};

struct NodeList {
	Node* head = NULL;
	Node* tail = NULL;

	void addLast(dict i) {
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

	Node* find_translation(char* key)
	{
		Node* cur = head;
		while (cur)
		{
			if (!strcmp(cur->info.rus, key))break;
			cur = cur->next;
		}
		return cur;
	}

	Node* find_word(char* key)
	{
		Node* cur = head;
		while (cur)
		{
			if (!strcmp(cur->info.angl, key))break;
			cur = cur->next;
		}
		return cur;
	}

	bool remove_complete(char* key)
	{
		if (Node * pkey = find_word(key)) {
			if (pkey == head) {
				head = (head)->next;
				(head)->prev = NULL;
			}
			else if (pkey == tail) {
				tail = (tail)->prev;
				(tail)->next = NULL;
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

	bool remove_translation(char* key)
	{
		if (Node * pkey = find_translation(key)) {
			if (pkey == head) {
				head = (head)->next;
				(head)->prev = NULL;
			}
			else if (pkey == tail) {
				tail = (tail)->prev;
				(tail)->next = NULL;
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

	bool RemoveLast()
	{
		if (head == NULL) {
			cout << "There are no elements!" << endl << endl;
			return false;
		}
		else {
			Node* cur = tail;
			tail = (tail)->prev;
			(tail)->next = NULL;
			delete cur;
			cout << "Successful!" << endl;
			return true;
		}

	}

	void Print()
	{
		Node* cur = head;
		while (cur) {
			cout/* << "Word: " << cur->info.angl << " ---> " */<< "Translation: " << cur->info.rus << endl;
			cur = cur->next;
		}
	}
};

