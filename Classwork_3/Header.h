#pragma once


template <typename T>
struct List
{
	typedef struct Node
	{
		Node* pnext = nullptr;
		T data = T();

		Node(T data = T(), Node* pnext = nullptr)
		{
			this->pnext = pnext;
			this->data = data;
		}
	};

	Node* phead;
	int size = 0;

	List()
	{
		size = 0;
		phead = nullptr;
	}

	~List()
	{
		del_list();
	}

	template <typename T>
	void push_back(T data)
	{
		if (phead == nullptr)
		{
			phead = new Node(data);
		}
		else
		{
			Node* current = this->phead;

			while (current->pnext)
			{
				current = current->pnext;
			}
			current->pnext = new Node(data);

		}

		size++;
	}

	template <typename T>
	void push_front(T data)
	{
		phead = new Node(data, phead);
		size++;
	}

	template <typename T>
	void insert(T data, int index)
	{
		if (index > size)
		{
			return;
		}
		else if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* previous = this->phead;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pnext;
			}

			previous->pnext = new Node(data, previous->pnext);

			size++;
		}
	}

	void removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node* previous = this->phead;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pnext;
			}

			Node* toDelete = previous->pnext;

			previous->pnext = toDelete->pnext;

			delete toDelete;

			size--;
		}

	}

	void pop_front()
	{
		Node* temp = phead;
		phead = phead->pnext;
		delete temp;
		size--;
	}

	void  del_list()
	{
		while (size)
		{
			pop_front();
		}
	}
	int getSize()
	{
		return this->size;
	}
};

struct ListBus : List<Bus>
{
	int amount = 0;
	void show()
	{
		Node* cur = phead;
		int i = 1;
		while (cur)
		{
			std::cout << i++ << '.';
			cur->data.show();
			cur = cur->pnext;
		}
	}
	Bus getBus(int n)
	{
		Node* current = this->phead;
		int i = 0;
		while (current)
		{
			if (i == n)
				break;
			current = current->pnext;
			i++;
		}
		return current->data;
	}

	void newBus()
	{
		Bus bus;
		bus.init();
		this->push_back(bus);
	}
};