#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

template <typename t>
struct Node
{
	t data;
	Node<t>* right, * left;
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
	Node<t>* root;

	Node<t>* first(t* data) {
		this->root = new Node<t>*(data);
		return root;
	}
	

	void search_insert(t* data, Node<t>* cur_root = this->root)
	{
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
				else if (data < current->data)current = current->left;
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

	void print_tree(Node<t>* p,int level) 
	{
		if (p) {
			print_tree(p->left, level + 1);
			for (int i = 0; i < level; ++i)cout << "    ";
			cout << p->data << endl;
			print_tree(p->right, level + 1);
		}
	}
};


int main()
{
	Tree<int>* tree = new Tree<int>;
	int b[] = { 10, 25, 20, 6, 21, 8, 1, 30 };
	Node<int>* root = tree->first(&b[0]);
	for (int i = 1; i < 8; i++)tree->search_insert(&b[i], root);
	tree->print_tree(root, 0);
	return 0;
}