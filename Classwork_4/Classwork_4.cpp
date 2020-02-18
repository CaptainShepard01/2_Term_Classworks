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

struct MyStack {
	vagon arr[10];
	int top = -1;
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



int main()
{
	MyStack Train, pass, cargo;
	
	return 0;
}
