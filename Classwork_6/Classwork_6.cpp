#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

template <typename t>
struct Node
{
	t data;
	Node* right, * left;
	Node(t data = t(), right = nullptr, left = nullptr)
	{
		this->data = data;
		this->right = right;
		this->left = left;
	}
};

template <typename t>
struct Tree
{
	Node* <t> root;

	void search_insert(t* data, Node<t>* cur_root = this->root)
	{
		if (this->root == nullptr)
		{
			this->root = new Node * <t>(data);
			return;
		}
		else {
			/*if (data < current->data)add(data, current->left);
			if (data > current->data)add(data, current->right);
			if (data == current->data) {
				Node<t>* pnew = new Node<t>;
				pnew->data = data;
				pnew->left = nullptr;
				pnew->right = nullptr;
				if (data < prev->data)prev->left = pnew;
				else prev->right = pnew;
				return;
			}*/

			Node<t>* current = root; Node<t>* prev;
			bool found = false;
			while (current && !found) {
				prev = current;
				if (data == current->data)found = true;
				else if (d < current->data)current = current->left;
				else current = current->right;
			}
			Node<t>* pnew = new Node<t>;
			pnew->data = data;
			pnew->left = nullptr;
			pnew->right = nullptr;
			if (data < prev->data)prev->left = pnew;
			else prev->right = pnew;
			return;
		}
	}

	void print_tree() {};
};
