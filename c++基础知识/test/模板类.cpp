#include <iostream>
using namespace std;

template <class x>
class box_
{
private:
	x a, b, c;
public:
	x V() { return a * b * c; }
	box_(x i, x j, x k);
	void print(){ cout << a << '\t' << b << '\t' << c << '\t'  << endl; }
	bool operator==(box_<x>& z);
};


template <class x>
box_<x>::box_(x i, x j, x k) { a = i; b = j; c = k; }

template <class x>
bool box_<x>::operator==(box_<x>& z) { return(a == z.a && b == z.b && c == z.c); }

//int main() {
//	box_<float> a1 (1.6, 3.3, 5.6);
//	box_<float> a2 (1.4, 3.3, 5.6);
//	cout << (a1==a2) <<endl;
//	a1.print(); a2.print();
//	return 0;
//}