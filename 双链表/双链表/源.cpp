#include "��ͷ.h"
int main()
{
	double floatlist [5] = {1.125,	6.5,	7.625,	5.875,	9.0};
	char charlist[] = "guten tag!";
	doubleLinkList <double> testDouble(floatlist, 5);
	doubleLinkList <char> testChar(charlist, 10);
	testDouble.print();
	testChar.print();
	cout << "������Ϊ" << testChar.getLength()<<endl;
	cout << "��������" << testChar.get(0)->data << endl;
	return 0;
}