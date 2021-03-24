#include "linklist.h"
#include "iostream"
using namespace std;

/*
template <class T>
LinkList<T>::LinkList(T a [], int n) //头插法建立单链表
{
	first = new Node <T>;
	first ->next = NULL; //构造空单链表
	for (int i=n-1;i>=0;i--)
	{
		Node <T> * s = new Node <T>;//①建立新结点
		s->data = a[i];				//②将a[i]写入到新结点的数据域
		s->next = first->next;		//③修改新结点的指针域
		first->next = s;			//④修改头结点的指针域，将新结点加入到链表中
	}
}

*/

template <class T>
LinkList<T>::LinkList(T a [], int n) //尾插法建立单链表
/*
①	在堆中建立新结点：Node <T> * s = new Node <T>;
②	将a[i]写入到新结点的数据域：s->data = a[i];
③	将新结点加入到链表中： r->next = s;
④	修改尾指针：r = s;
*/
{
	first = new Node <T>;
	Node <T> * r = first; 
	for (int i=0;i<n;i++)
	{
		Node <T> * s = new Node <T>;//①建立新结点
		s->data = a[i];				//②将a[i]写入到新结点的数据域
		r->next = s;				//③将新结点加入到链表中
		r = s;						//④修改尾指针
	}
	r->next = NULL;					//终端结点的指针域设为空
}

template <class T>
LinkList<T>::~LinkList() //析构函数
{
	Node <T> * p = first;	//初始化工作指针p 
	while (p)				//要释放的结点存在
	{
		first = p;			//暂存要释放的结点
		p = p -> next;		//移动工作指针
		delete first;		//释放结点
	}
}

template <class T>
Node <T> * LinkList<T>::Get(int i)	//获取线性表第i个位置上的元素
{
	Node <T> * p = first -> next;	//初始化工作指针
	int j = 1;						//初始化计数器
	while ( p && j != i )			//两个条件都满足，则继续循环
	{
		p = p -> next;				//工作指针后移
		j++;	
	}
	if (!p) throw "查找位置非法";	//工作指针已经为空
	else return p;			//查找到第i个元素
}

template <class T>
int LinkList<T>::Locate (T x)		//查找线性表中值为x的元素，找到后返回其位置
{
	Node <T> * p = first ->next;	//初始化工作指针
	int j=1;
	while (p)
	{
		if (p->data == x) return j;	//找到被查元素，返回位置
		p = p->next;
		j++;
	}
	return -1;		//若找不到，返回错误标识-1
}

template <class T>
void LinkList<T>::Insert (int i, T x)//在线性表的第i个位置上插入值为x的新元素
{
	Node <T> * p = first;		//初始化工作指针
	if (i != 1) p = Get(i-1);	//若不是在第一个位置插入，得到第i-1个元素的地址。
	Node <T> * s = new Node <T>;//建立新结点
	s->data = x;				
	s->next = p->next;
	p->next = s;				//将新结点插入到p所指结点的后面
}

template <class T>
T LinkList<T>::Delete(int i)	//删除线性表第i个元素，并将该元素返回
{
	Node <T> * p = first;		//初始化工作指针
	if (i != 1) p = Get(i-1);	//若不是在第一个位置插入，得到第i-1个元素的地址。
	Node <T> * q = p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}

template <class T>
void LinkList<T>::PrintList()	//按次序遍历线性表中的各个数据元素
{
	Node <T> * p = first->next ;		//初始化工作指针
	while (p){
		cout << p->data << endl;
		p = p-> next;
	}
}