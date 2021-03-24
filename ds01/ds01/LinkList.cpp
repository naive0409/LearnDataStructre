#include "linklist.h"
#include "iostream"
using namespace std;

/*
template <class T>
LinkList<T>::LinkList(T a [], int n) //ͷ�巨����������
{
	first = new Node <T>;
	first ->next = NULL; //����յ�����
	for (int i=n-1;i>=0;i--)
	{
		Node <T> * s = new Node <T>;//�ٽ����½��
		s->data = a[i];				//�ڽ�a[i]д�뵽�½���������
		s->next = first->next;		//���޸��½���ָ����
		first->next = s;			//���޸�ͷ����ָ���򣬽��½����뵽������
	}
}

*/

template <class T>
LinkList<T>::LinkList(T a [], int n) //β�巨����������
/*
��	�ڶ��н����½�㣺Node <T> * s = new Node <T>;
��	��a[i]д�뵽�½���������s->data = a[i];
��	���½����뵽�����У� r->next = s;
��	�޸�βָ�룺r = s;
*/
{
	first = new Node <T>;
	Node <T> * r = first; 
	for (int i=0;i<n;i++)
	{
		Node <T> * s = new Node <T>;//�ٽ����½��
		s->data = a[i];				//�ڽ�a[i]д�뵽�½���������
		r->next = s;				//�۽��½����뵽������
		r = s;						//���޸�βָ��
	}
	r->next = NULL;					//�ն˽���ָ������Ϊ��
}

template <class T>
LinkList<T>::~LinkList() //��������
{
	Node <T> * p = first;	//��ʼ������ָ��p 
	while (p)				//Ҫ�ͷŵĽ�����
	{
		first = p;			//�ݴ�Ҫ�ͷŵĽ��
		p = p -> next;		//�ƶ�����ָ��
		delete first;		//�ͷŽ��
	}
}

template <class T>
Node <T> * LinkList<T>::Get(int i)	//��ȡ���Ա��i��λ���ϵ�Ԫ��
{
	Node <T> * p = first -> next;	//��ʼ������ָ��
	int j = 1;						//��ʼ��������
	while ( p && j != i )			//�������������㣬�����ѭ��
	{
		p = p -> next;				//����ָ�����
		j++;	
	}
	if (!p) throw "����λ�÷Ƿ�";	//����ָ���Ѿ�Ϊ��
	else return p;			//���ҵ���i��Ԫ��
}

template <class T>
int LinkList<T>::Locate (T x)		//�������Ա���ֵΪx��Ԫ�أ��ҵ��󷵻���λ��
{
	Node <T> * p = first ->next;	//��ʼ������ָ��
	int j=1;
	while (p)
	{
		if (p->data == x) return j;	//�ҵ�����Ԫ�أ�����λ��
		p = p->next;
		j++;
	}
	return -1;		//���Ҳ��������ش����ʶ-1
}

template <class T>
void LinkList<T>::Insert (int i, T x)//�����Ա�ĵ�i��λ���ϲ���ֵΪx����Ԫ��
{
	Node <T> * p = first;		//��ʼ������ָ��
	if (i != 1) p = Get(i-1);	//�������ڵ�һ��λ�ò��룬�õ���i-1��Ԫ�صĵ�ַ��
	Node <T> * s = new Node <T>;//�����½��
	s->data = x;				
	s->next = p->next;
	p->next = s;				//���½����뵽p��ָ���ĺ���
}

template <class T>
T LinkList<T>::Delete(int i)	//ɾ�����Ա��i��Ԫ�أ�������Ԫ�ط���
{
	Node <T> * p = first;		//��ʼ������ָ��
	if (i != 1) p = Get(i-1);	//�������ڵ�һ��λ�ò��룬�õ���i-1��Ԫ�صĵ�ַ��
	Node <T> * q = p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}

template <class T>
void LinkList<T>::PrintList()	//������������Ա��еĸ�������Ԫ��
{
	Node <T> * p = first->next ;		//��ʼ������ָ��
	while (p){
		cout << p->data << endl;
		p = p-> next;
	}
}