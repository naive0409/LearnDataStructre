//#include <iostream>
//using namespace std;
//class box
//{
//private:
//	float a, b, c;
//public:
//	box(float i = 0, float j = 0, float k = 0) { a = i; b = j; c = k; }
//	float V() { return a * b * c; }
//	box operator+(box& m)
//	{
//		box g;
//		g.a = /*this->*/a + m.a;
//		g.b = /*this->*/b + m.b;
//		g.c = /*this->*/c + m.c;
//		return g; 
//	}
//	void print()
//	{
//		cout << this << a << '\t' << b << '\t' << c << '\t' << endl;
//	}
//
//};
//
//int main()
//{
//	box a(1, 3, 5);
//	box b(5, 7, 9);
//	box c = a + b;
//	box d;
//	d = d.operator+(c);
//	c.print();
//	d.print();
//	return 0;
//}