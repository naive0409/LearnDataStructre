#pragma once
#include <iostream>
using namespace std;

template <class x>
struct node
{
	x data;
	struct node <x>* prior;
	struct node <x>* next;
};


template <class x>
class doubleLinkList
{
private:
	node <x>* front;
	node <x>* rear;

public:

	doubleLinkList();
	doubleLinkList(x in[], int n);
	//~doubleLinkList();
	//x del(int i);
	void print();
	int getLength();
	node <x>* get(int i);
	//int locate(x loc);
};

template <class x>
doubleLinkList<x>::doubleLinkList() 
{
	node <x> * p = new node<x> ;
	front = p;
	rear = p;
	p->next = p;
	p->prior = p;
};

template <class x>
doubleLinkList<x>::doubleLinkList(x in[], int n)
{
	node <x>* p = new node<x>;
	front = p;
	for (int i = 0; i < n; i++)
	{
		node <x>* s = new node <x>;
		s->data = in[i];
		s->prior = p;
		p->next = s;
		p = s;
	}
	rear = p;
	front->prior = p;
	p->next = front;	
}

template <class x>
void doubleLinkList<x>::print()
{
	node<x>* p = front->next;
	int k = 1;
	cout << endl << "内容如下:" << endl;
	cout << "序号" << '\t' << "内容" << endl;
	while (p!=front)
	{
		cout << k++ << '\t' << p->data << endl;
		p = p->next;
	}
}

//template <class x>
//doubleLinkList<x>::~doubleLinkList()
//{
//	node<x>* p = front;
//	while (p)
//	{
//		p = p->next;
//		delete front;
//		front = p;
//
//	}
//}

template <class x>
int doubleLinkList<x>::getLength()
{
	node <x>* p = front;
	int j = 0;
	
	do
	{
		j++;
		p = p->next;

	} while (p != front);
	return j-1 ;
}

template <class x>
node <x>* doubleLinkList<x>::get(int i)
{
	node <x>* p = front->next;
	if (i > getLength() || i <= 0) { cout << "参数非法"; node <x>* n = new node <x>; return n; }
	int k = 1;
	while (k!=i)
	{
		p = p->next;
		k++;
	}
	return p;
}