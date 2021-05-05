#ifndef _QUEUE
#define _QUEUE


#include <stdlib.h>

template <class T> class Queue
{
	public:
		Queue();
		int IsEmpty();
		void EnQueue(T);
		T DelQueue();
		T GetFront();
		~Queue();
	protected:
		struct Node{
		   T data;
		   Node *next;
		};
		Node *Front;
		Node *Rear;
};

#endif