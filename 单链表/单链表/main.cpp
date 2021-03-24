
#include "linklist.cpp"


class ComplexNumber	//�Զ����ࣺ������
{
public:
	ComplexNumber(){a=0;b=0;}	//�޲ι��캯��
	ComplexNumber(double a1, double b1){a=a1;b=b1;}	//�вι��캯��
	bool operator ==(ComplexNumber & cn)	//==����������
	{return (a == cn.a && b == cn.b); }
private:
	double a; //a + bi��ʵ���鲿
	double b; //a + bi���鲿�鲿
};

int maintest()//������������Ϊ����
{
	LinkList <ComplexNumber> cnlist;
	cnlist.Insert (1,ComplexNumber(1,2));
	ComplexNumber cn(1,2);
	int pos = cnlist.Locate(cn);
	cout << "(1,2)��λ��Ϊ"<< pos << endl;
	return 0;
}

int main()
{
	int a[7]={1,2,3,4,5,6,7};
	LinkList <int> list(a,7);
	list.PrintList ();
	list.Insert (1,0);
	list.PrintList ();
	int x = list.Delete (8);
	cout << "ɾ��Ԫ�أ�"<< x << endl;
	list.PrintList ();
	int p = list.Locate (4);
	cout << "Ԫ��4��λ�ã�" << p << endl;
	maintest(); //������������Ϊ����
	return 0;
}
