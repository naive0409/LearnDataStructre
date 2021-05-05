#include "stack.h"
#include <iostream>
using namespace std;

template <class T> int Stack<T>::IsEmpty()
{
       if (Top==NULL) return 1;
       else           return 0;
}

template <class T> T Stack<T>::GetTop()
{
       if (Top==NULL)   return T(); 
       else   return Top->data;                            
} 	
template <class T> void Stack<T>::Push(T t)
{
        Node *s=new Node;
        s->data = t;
        s->next = Top;
        Top = s;
}	

template <class T> T Stack<T>::Pop()
{
      
      if (Top==NULL)  
            cout<<"Õ»¿Õ£¬Òç³ö"<<endl;
      else{
             T  t;
             t=Top->data;
             Node *s=Top;
             Top=Top->next;
             delete s;
             return t;
      }

}	
template <class T> Stack<T>::~Stack()
{
    Node *p;
	while (Top!=NULL)
	{
		p=Top;
		Top=Top->next;
		delete p;
	}
}
