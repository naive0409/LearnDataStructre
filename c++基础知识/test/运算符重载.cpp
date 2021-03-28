#include <iostream>
#include "Ä£°åÀà.cpp"
using namespace std;
class box
{
private:
	float a, b, c;
public:
	box(float i = 0, float j = 0, float k = 0) { a = i; b = j; c = k; }
	float V() { return a * b * c; }
	box operator+(box& m)
	{
		box g;
		g.a = /*this->*/a + m.a;
		g.b = /*this->*/b + m.b;
		g.c = /*this->*/c + m.c;
		return g; 
	}
	void print();
	bool operator==(box & f);


};

void box::print()
{
	cout << this << a << '\t' << b << '\t' << c << '\t' << endl;
}

bool box::operator==(box& f)
{
	return(f.a == a && f.b == b && f.c == c);
}

int main()
{
	box a(1, 3, 5);
	box b(5, 7, 9);
	box c = a + b;
	box d;
	d = d.operator+(c);
	c.print();
	d.print();
	cout << "d==c? " << ((d == c) ? "Yes!" : "No!") << endl;
	cout << "______________________________________________________\n";
	box_<float> a1 (1.6, 3.3, 5.6);
	box_<float> a2 (1.4, 3.3, 5.6);
	cout << "a1==a2? " << ((a1 == a2) ? "Yes!" : "No!") << endl;
	a1.print(); a2.print();

	return 0;
}