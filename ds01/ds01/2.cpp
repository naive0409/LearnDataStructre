#include <iostream>
using namespace std;

template <class T>

//class LinkList {
//public:
//	LinkList() {};
//prinvate:
//};

LinkList<T>::LinkList(T a[], int n) {
	Node<T>* first = new Node<T>;
	first->next = NULL;
	for (int i = 0; i < n;i++) {
		Node<T>* p = new Node<T>;
		p->data = a[i];
		p->next = NULL;
	}

}