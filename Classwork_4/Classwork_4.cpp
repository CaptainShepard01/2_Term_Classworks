#include <iostream>
#include <stdio.h>
using namespace std;


struct vagon {
	enum type{pass, cargo};
	vagon* next;
};


struct train {
	vagon* first;
	vagon* last;
};

template <typename T>
struct Stack {
	//vagon arr[10];
	int top = -1;
	T* array;

	Stack() {}

	Stack(int n) {
		this->array = new T[n];
	}

	~Stack() {
		delete[]this->array;
	}
	vagon* peek() 
	{
		return &arr[top];
	};
	void push(vagon& v)
	{
		arr[++top] = v;
	};
	vagon* pop() 
	{
		return &arr[top--];
	};
};

void VagonMaker(int k)
{
	for (int i = 0; i < k; ++k) {
		cout << "";
	}
}

int main()
{
	Stack<vagon> Train, pass, cargo;
	
	return 0;
}
