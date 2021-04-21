#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* lch;
	Node<T>* rch;
};

template <class T> class BiTree
{
protected:

	void Create(Node<T>*& R, T data[], int i, int n);
	void Release(Node<T>* R);
public:
	Node<T>* root;
	BiTree() : root(NULL) {}
	BiTree(T data[], int n);
	void PreOrder(Node<T>* R); //ǰ��
	void InOrder(Node<T>* R);   //����
	void PostOrder(Node<T>* R); //����
	void LevelOrder(Node<T>* R);  //����
	~BiTree();
};
template <class T>
BiTree<T>::BiTree(T data[], int n)
{
	Create(root, data, 1, n);
}
template <class T>
BiTree<T>::~BiTree()
{
	Release(root);
}
template <class T>
void  BiTree<T>::Create(Node<T>*& R, T data[], int i, int n)
{
	if (data[i] == 0 || i > n)
		R = NULL;
	else
	{
		R = new Node<T>;
		R->data = data[i];
		Create(R->lch, data, 2 * i, n);
		Create(R->rch, data, 2 * i + 1, n);
	}
}
template < class T >
void BiTree<T>::PreOrder(Node<T>* R)
{
	if (R != NULL)
	{
		cout << R->data;             // ���ʽ��
		PreOrder(R->lch);    // ����������
		PreOrder(R->rch);   // ����������
	}
}
template < class T >
void BiTree<T>::InOrder(Node<T>* R)
{
	if (R != NULL)
	{
		InOrder(R->lch);     // ����������
		cout << R->data;            // ���ʽ��
		InOrder(R->rch);    // ����������
	}
}
template < class T >
void BiTree<T>::PostOrder(Node<T>* R)
{
	if (R != NULL)
	{
		PostOrder(R->lch);     // ����������
		PostOrder(R->rch);    // ����������
		cout << R->data;      // ���ʽ��
	}
}
template < class T >
void BiTree<T>::LevelOrder(Node<T>* R) //����
{
	Node<T>* queue[100];
	int f = -1;
	int r = -1;
	queue[++r] = R;//���
	while (f != r)
	{
		Node<T>* p = queue[++f];
		cout << p->data;
		if (p->lch != NULL) queue[++r] = p->lch;
		if (p->rch != NULL) queue[++r] = p->rch;
	}
}

template < class T >
void BiTree<T>::Release(Node<T>* R)
{
	if (R != NULL)
	{
		Release(R->lch);
		Release(R->rch);
		delete R;
	}
}
void main()
{
	char a[] = { 0,'A','B','C','D','E','G',0,0,0,'F',0,0,'H' };
	BiTree<char> tree(a, 13);
	tree.PreOrder(tree.root);
	cout << endl;
	tree.InOrder(tree.root);
	cout << endl;
	tree.PostOrder(tree.root);
	cout << endl;
	tree.LevelOrder(tree.root);
	cout << endl;
}