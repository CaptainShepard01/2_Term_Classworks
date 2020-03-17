#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

//template <typename t>
struct Node
{
	int data;
	Node* right = nullptr; Node *left = nullptr;
	/*Node(t data = t(), right = nullptr, left = nullptr)
	{
		this->data = data;
		this->right = right;
		this->left = left;
	}*/
};

//template <typename t>
struct Tree
{
	Node* root = nullptr;

	Node* first(int data) {
		root = new Node;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}
	

	void search_insert(Node* root, int data)
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

		Node* current = root; Node* prev = new Node;
			bool found = false;
			while (current && !found) {
				prev = current;
				if (data == current->data)found = true;
				else if (data < current->data)current = current->left;
				else current = current->right;
			}
			Node* pnew = new Node;
			pnew->data = data;
			pnew->left = nullptr;
			pnew->right = nullptr;
			if (data < prev->data)prev->left = pnew;
			else prev->right = pnew;
			return;
	}

	void print_tree(Node* p,int level) 
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
	int level = 0;
	Tree* tree = new Tree;
	int b[] = { 10, 25, 20, 6, 21, 8, 1, 30 };
	Node* root = tree->first(b[0]);
	for (int i = 1; i < 8; i++)tree->search_insert(root, b[i]);
	tree->print_tree(root, level);
	system("pause");
	delete tree;
	return 0;
}