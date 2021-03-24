
#include "SeqList.cpp"

void main()
{
	int a[7]={1,2,3,4,5,6,7};
	SeqList <int> list(a,7);
	list.PrintList ();
	list.Insert (1,0);
	list.PrintList ();
	int x = list.Delete (8);
	cout << "删除元素："<< x << endl;
	list.PrintList ();
	int p = list.Locate (4);
	cout << "元素4的位置：" << p << endl;
	
}