#include <iostream>
#include "tree.h"
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

template <class T> Node<T>*& BiTree<T>::Root()
{
	return root;
}
//ʹ��˳��ṹ�洢�����ݽ�������������
template <class T> void BiTree<T>::Create(Node<T> *&R,T* buf,int i)
{
  	if (buf[i-1]==0)
		R = NULL;
	else
	{
		R=new Node<T>;
		R->data = buf[i-1];
		Create(R->lch, buf, 2*i);
        Create(R->rch, buf, 2*i+1);
	}
}
//���ٶ�����
template <class T> void BiTree<T>::Destroy(Node<T> *R)
{
	if (R!=NULL) {
              Destroy(R->lch);   
              Destroy(R->rch);  
              delete R;            
     }
}
template <class T> void BiTree<T>::Preorder(Node<T> *R)
{
	if (R!=NULL) {
              Print(R->data);            
              Preorder(R->lch); 
              Preorder(R->rch);
     }

}
template <class T> void BiTree<T>::Inorder(Node<T> *R)
{
	if (R!=NULL) {
              Inorder(R->lch);   
              Print(R->data);            
              Inorder(R->rch);  
     }
}
template <class T> void BiTree<T>::Postorder(Node<T> *R)
{
	if (R!=NULL) {
              Postorder(R->lch);   
              Postorder(R->rch);  
              Print(R->data);            
     }
}

template <class T> void BiTree<T>::Print(T e)
{
	cout<<e;
}

template <class T> BiTree<T>::~BiTree()
{
	Destroy(root);
}
//��ѯ���еĽ��
template <class T>  int BiTree<T>::Lookup(Node<T> *R,T e, Node<T> *&p)
{
	if (R!=NULL)
	{
		if (R->data == e) { p=R; return 1;}
		if (Lookup(R->lch,e,p))
			return  1;
		else 
			return 	Lookup(R->rch,e,p);
	}
	return 0;
}
//������Ҷ�����
template <class T> int BiTree<T>::CountLeaf(Node<T> *R)
{
    if (R==NULL) return 0;
	if ((R->lch==NULL) && (R->rch==NULL)) 
         return 1;            
    else
	{
		int n=CountLeaf(R->lch); 
        int m=CountLeaf(R->rch);
		return m+n;
	}
}
//�����Ľ������
template <class T> int BiTree<T>::Count(Node<T> *R)
{
	if (R==NULL) return 0;
	else
	{
		int m=Count(R->lch);
		int n=Count(R->rch);
		return m+n+1;
	}
}
//���������
template <class T> int BiTree<T>::Depth(Node<T> *R,int d)
{
    if (R==NULL) return d;
    if ((R->lch==NULL) && (R->rch==NULL))
		return d+1;
    else
	{
		int m = Depth(R->lch,d+1);
		int n = Depth(R->rch,d+1);
		return n>m? n:m;
	}
}
//���ƶ�����
template <class T> void BiTree<T>::CopyTree(Node<T> *R,Node<T>*& R1)
{
	if (R==NULL)	R1=NULL;
	else
	{
		R1=new Node<T>;
		R1->data = R->data;
		CopyTree(R->lch,R1->lch);
        CopyTree(R->rch,R1->rch);
	}
	
}
//�ǵݹ��������
template <class T> void BiTree<T>::Preorder1(Node<T> *R)
{
	Stack<Node<T>*> S;
	while(!S.IsEmpty() || (R!=NULL))
	{
		if (R!=NULL)
		{
			Print(R->data);       
			S.Push(R);
			R=R->lch;
		}
		else
		{
			R=S.Pop();
			R=R->rch;
		}
	}
}
//�ǵݹ��������
template <class T> void BiTree<T>::Inorder1(Node<T> *R)
{
    Stack<Node<T>*> S;
    while(!S.IsEmpty() || (R!=NULL))
    {
	   if (R!=NULL)	
       {  	
		   S.Push(R);	
		   R=R->lch;
	   }
	   else	
       {	
		   R=S.Pop();	
		   Print(R->data);
		   R=R->rch;   
	   }
	 }
	
 }
//�ǵݹ�������
 /* ���ں���������ʸ�����ָ�����ڱ���������������������������Ҫ
�б������������ػ������������أ����ջ���Ľṹ��Ҫ�����һ�����
tag��0�������������أ�1�������������ء�*/
template <class T> void BiTree<T>::Postorder1(Node<T> *R)
{
    stacknode<T> x;
	Stack<stacknode<T> > S;
    do
	{
	   while (R!=NULL)	//����������
       {  	
		   x.treenode = R;
		   x.tag = 0;
		   S.Push(x);	
		   R=R->lch;
	   }
	   if (!S.IsEmpty())  //����������
	   {
			x=S.Pop();
			x.tag = 1;
			R=x.treenode->rch;
			S.Push(x);
	   }
	   while((!S.IsEmpty())	&& (S.GetTop().tag==1))
       {	
		   x=S.Pop();	
		   Print(x.treenode->data);  //���ʸ����
	   }
	   
	}while(!S.IsEmpty());
    
 }
//��ȱ���������
template <class T> void BiTree<T>::Levelorder(Node<T> *R)
{
	Queue<Node<T>*> Q;
	while(!Q.IsEmpty() || (R!=NULL))
	{
		if (R!=NULL)
		{
			Print(R->data);
			Q.EnQueue(R->lch);
			Q.EnQueue(R->rch);
		}
		R=Q.DelQueue();
	}
}
//�������������
template <class T> void BiTree<T>::InThread(Node<T> *R, Node<T> *&pre)
{
	if (R!=NULL)
	{
		InThread(R->lch,pre);
		if (R->lch==NULL){ 	R->ltag =1; R->lch = pre;		}
		if (pre->rch==NULL){ pre->rtag =1; pre->rch = R;			}
		pre = R;
		InThread(R->rch,pre);
	}
}
template <class T> void BiTree<T>::InorderThreading(Node<T> *&Thrt,Node<T> *R)
{
	Node<T>* pre;

	Thrt = new Node<T>;
	Thrt->ltag = 0;
    Thrt->rtag = 0;
	Thrt->rch = Thrt;

	if (R==NULL) Thrt->lch = Thrt;
	else
	{
        Thrt->lch = R;
		pre = Thrt;
		InThread(R,pre);   
        pre->rtag = 1;		pre->rch = Thrt;
        Thrt->rtag = 1;		Thrt->rch = pre;
     }
}
//��������������
template <class T> void BiTree<T>::InorderThread(Node<T> *Thrt)
{
	Node<T> *R = Thrt->lch;
	while (R!=Thrt)
	{
		while (R->ltag==0)
			R=R->lch;
		Print(R->data);
		while ((R->rtag==1) && (R->rch!=Thrt))
		{	
			R=R->rch;
			Print(R->data);
		}
		R=R->rch;
   	}
}
//������������ͺ�������������ɶ�����
template <class T> int BiTree<T>::Find(T x, T* Inbuf,int b,int e)
{
	for(int i=b; i<=e; i++)
		if (Inbuf[i]==x) return i;
	return -1;
}
template <class T> void BiTree<T>::Create(Node<T>* &R,T* PreBuf, int& i,T* InBuf, int b,int e)
{
	if(b<=e)
	{
		int pos=Find(PreBuf[i],InBuf,b,e);
		if (pos==-1)
			R=NULL;
		else
		{
			R=new Node<T>;
			R->data = PreBuf[i];
			Create(R->lch,PreBuf,++i,InBuf,b,pos);
			Create(R->rch,PreBuf,i,InBuf,pos+1,e);
		}
	}
}