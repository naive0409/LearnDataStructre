#include "标头.h"
int main()
{
	double floatlist [5] = {1.125,	6.5,	7.625,	5.875,	9.0};
	char charlist[] = "guten tag!";
	doubleLinkList <double> testDouble(floatlist, 5);
	doubleLinkList <char> testChar(charlist, 10);
	testDouble.print();
	testChar.print();
	cout << "链表长度为" << testChar.getLength()<<endl;
	cout << "第三项是" << testChar.get(0)->data << endl;
	return 0;
}