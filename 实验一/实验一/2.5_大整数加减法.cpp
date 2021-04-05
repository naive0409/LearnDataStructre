/*
2.5 ��Ŀ 5����Ӧ��ʵ��
������ʵ�ִ������Ӽ���������
32 λ����ֱ�Ӳ������������Ϊ 32 �� bit�������� 32bit������Ҫ��������㷨������
�����������ÿ�����洢��������ÿһλ��ʮ�������֣�����Խ��д��������������㣬
��ʵ���ʵ�ּӼ���������
Ҫ��:
1�� ������� 2 �� 1~50 λ�����ִ������洢�� 2 �������С�
2�� ���мӷ����������������洢���µ������С�
3�� ��ӡ��������
*/

#include <iostream>
#include <random>
#include <time.h>
#include <string>
using namespace std;

struct node
{
	short data;
	struct node* next;
	struct node* prior;
};

class veryLong
{
private:
	struct node* front;
	struct node* rear;
	node i;
public:
	veryLong();
	veryLong(string s);
	veryLong plus(veryLong l);
	veryLong minus(veryLong l);
	int len();
	void print();
	void addF(short d);
};

void veryLong::addF(short d)
{

	node* x = new node;
	x->data = d;

	front->next->prior = x;
	x->next = front->next;
	front->next = x;
	x->prior = front;

}

int veryLong::len()
{
	int z = -1;
	node* p = front;
	do
	{
		p = p->next;
		z++;
	} while (p!=front);
	return z;
}

veryLong::veryLong()
{
	node* p = new node;
	p->data = -1;
	p->prior = p;
	p->next = p;
	front = p;
	rear = p;
}

veryLong::veryLong(string c)
{
	node* x = new node;
	x->prior = x;
	x->next = x;
	front = x;
	rear = x;
	for (int i = 0; i < c.size(); i++)
	{
		node* p = new node;
		p->data = short(c[i])-48;

		x->next = p;
		p->prior = x;

		p->next = front;
		front->prior = p;
		
		x = p;
	}
	rear = x;
}

void veryLong::print()
{
	//node* p = this->front->next;
	node * p = front->next->data == 0 ? front->next->next : front->next;
	do
	{cout << p->data;
		p = p->next;
	} while (p != rear);
	cout << endl;
}

veryLong veryLong::plus(veryLong l)
{
	veryLong res("0");
	node* r = res.rear;
	node* r1 = this->rear;
	node* r2 = l.rear;
	static short k = 0;//��λ��1
	do
	{
		r->data = r1->data + r2->data + k;

		if (r->data >= 10) { k = 1; r -> data -= 10; }
		else { k = 0; }

		res.addF(0);

		r = r->prior;
		r1 = r1->prior;
		r2 = r2->prior;

	} while (r2 != l.front && r1 != this->front);//����һ����ͷ�˾�ֹͣ

	if (r2 == l.front && r1 == this->front) {
		r->data = k;
		return res;
	}//������λ��һ��

	veryLong* n = l.len() > this->len() ? &l : this;
	node* m = l.len() > this->len() ? r2 : r1;//������

	do
	{	r->data = m->data + k;
		res.addF(0);

		if (r->data >= 10) { k = 1; r->data -= 10; }
		else { k = 0; }

		r = r->prior;
		m = m->prior;
	} while (m!=n->front);
	return res ;
}

veryLong veryLong::minus(veryLong l)
{
	return l;
}

void randVeryLong(veryLong x, int n)
{
	for (int i = 0 ;i<n;i++)
	{
		x.addF(rand() % 10);
	}
}


int main()
{
	srand(time(NULL));

	veryLong L1("");
	veryLong L2("");
	veryLong L3("0");
	randVeryLong(L1, 1+rand() % 50);
	randVeryLong(L2, 1+rand() % 50);

	L3 = L1.plus(L2);

	cout << "L1=\t"; L1.print();
	cout << "L2=\t"; L2.print();
	cout << "L1+L2=\t"; L3.print();

	return 0;
}