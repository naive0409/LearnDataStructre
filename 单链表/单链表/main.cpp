
#include "linklist.cpp"


class ComplexNumber	//自定义类：复数类
{
public:
	ComplexNumber(){a=0;b=0;}	//无参构造函数
	ComplexNumber(double a1, double b1){a=a1;b=b1;}	//有参构造函数
	bool operator ==(ComplexNumber & cn)	//==操作符重载
	{return (a == cn.a && b == cn.b); }
private:
	double a; //a + bi的实部虚部
	double b; //a + bi的虚部虚部
};

int maintest()//测试数据类型为复数
{
	LinkList <ComplexNumber> cnlist;
	cnlist.Insert (1,ComplexNumber(1,2));
	ComplexNumber cn(1,2);
	int pos = cnlist.Locate(cn);
	cout << "(1,2)的位置为"<< pos << endl;
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
	cout << "删除元素："<< x << endl;
	list.PrintList ();
	int p = list.Locate (4);
	cout << "元素4的位置：" << p << endl;
	maintest(); //测试数据类型为复数
	return 0;
}
