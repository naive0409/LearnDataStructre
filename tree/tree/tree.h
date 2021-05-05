#include <iostream>
using namespace std;
#ifndef _TREE
#define _TREE
template <class T> class Node
{
    public:
		T data;
		Node<T>* lch;
		Node<T>* rch;
		int ltag;
		int rtag;
	
	Node():lch(NULL),rch(NULL),ltag(0),rtag(0){}
};
template <class T> class stacknode
{
	public:
		Node<T> * treenode;
		int tag;
};
template <class T> class BiTree
{
	protected:
		Node<T> *root;
	
	public:
        BiTree():root(NULL){}
		Node<T>*& Root();
        void Create(Node<T>* &R,T* buf,int i);
		void Destroy(Node<T> *R);
		void Preorder(Node<T> *R);
		void Inorder(Node<T> *R);
		void Postorder(Node<T> *R);
		void Print(T e);
		~BiTree();

		int Lookup(Node<T> *R,T e,Node<T> *&p);
		int CountLeaf(Node<T> *R);
		int Count(Node<T> *R);
		int Depth(Node<T> *R,int d);
		void CopyTree(Node<T> *R,Node<T> *&R1);
		
		void Levelorder(Node<T> *R);
		void Preorder1(Node<T> *R);
		void Inorder1(Node<T> *R);
        void Postorder1(Node<T> *R);
		void InThread(Node<T> *R, Node<T> *&pre);
		void InorderThreading(Node<T> *&Thrt, Node<T> *R);
		void InorderThread(Node<T> *Thrt);
	
		int Find(T x, T* Inbuf,int b,int e);
		void Create(Node<T>* &R,T* PreBuf, int &i,T* InBuf,int b,int e);
};

#endif