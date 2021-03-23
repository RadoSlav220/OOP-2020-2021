#include <iostream>
#include "vector.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	size_t n, m; 
	
	cin >> n;
	Vector a(n);
	a.setVector();
	
	cin >> m;
	Vector b(m);
	b.setVector();

	cout << "a = ";
	a.printVector();
	cout << "b = ";
	b.printVector();

	int x;
	cin >> x;
	b = a/x;
	a /= x;
	cout << (a==b) << endl;
	//cout << "|a| = " << a.vectorLength() << endl;
	//cout << "(a.b) = " << a * b << endl;

	cout << "a = ";
	a.printVector();
	cout << "b = ";
	b.printVector();

	return 0;
}