#ifndef _STACK
#define _STACK
#include <stdlib.h>

template <class T> class Stack {
     public:
  	    Stack ():Top(NULL){}
		int IsEmpty();
        T GetTop();
		void Push(T);
		T Pop();
		~Stack();
	protected:
		struct Node{
            T data;
            Node *next;
        };
        Node *Top;
};

#endif