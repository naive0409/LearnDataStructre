//#include <iostream>
//using namespace std;
//
//template <class T>
//
////class LinkList {
////public:
////	LinkList() {};
////prinvate:
////};
//
//LinkList<T>::LinkList(T a[], int n) {
//	Node<T>* first = new Node<T>;
//	first->next = NULL;
//	for (int i = 0; i < n;i++) {//O(n*n)
//		Node<T>* p = new Node<T>;
//		p->data = a[i];
//		p->next = NULL;
//		Node<T>* pre = first;
//		while((pre->next!=NULL)
//			&& (p->data < pre->next->data))
//		{
//			pre = pre->next;
//		}
//		p->next = pre->next;
//		pre->next = p;
//		
//	}
//}
//
//void Convert(Node<T>* first)
//{
//	Node<T> *p=first->next;
//	first->next =NULL;
//	Node<T> *q = NULL;
//	while(p!=NULL)
//	{
//		q = p->next;
//		p->next =first->next;
//		first->next= p;
//		p=q;
//	}
//}