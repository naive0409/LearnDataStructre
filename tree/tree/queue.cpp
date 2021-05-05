#include "queue.h"
#include <iostream>
using namespace std;

template <class T> Queue<T>::Queue()
{
	Front = new Node;
	Front->next = NULL;
	Rear = Front;
}
template <class T> int Queue<T>::IsEmpty()
{
	if (Front==Rear) return 1;
	else  return 0;
}
template <class T> T Queue<T>::GetFront()
{
	return Front==Rear? NULL:Front->data;
}
template <class T> void Queue<T>::EnQueue(T t)
{
	Node *s=new Node;
	s->data = t;
	s->next=NULL;

	Rear->next = s;
    Rear = s;
}
template <class T> T Queue<T>::DelQueue()
{
	T t=NULL;
	if (Front==Rear) 
		cout<<"队列空，无元素出队!"<<endl;
	else
	{
		Node *s=Front->next;
		t=s->data;
		Front->next = s->next;
		delete s;
		if (Front->next==NULL)  
			Rear=Front;
	}
	return t;
}

template <class T> Queue<T>::~Queue()
{
	while(Front!=Rear)
	{
		cout<<DelQueue()<<endl;
	}
}	