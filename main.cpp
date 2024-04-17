#include <iostream>
#include "matrix.cpp"
#include <iomanip>
#include <string>
#include <initializer_list>

using namespace std;
using namespace linalg;

int main()
{
	/*
	a = Matrix<double>{ { 1,2,1 }, { 2.2,2.3,2 } };
	b = Matrix<int>{ { 1,2,3 }, { 4,5,4}, { 3,6,7 } };

	Matrix<double> c{ {12,18,18},{17.4,27.9,29.8} };
	a = a * b;
	if (a == c) { cout << "good!" << endl; }
	cout << a;
	cout << b;
	cout << c;
	cout << a;*/
	//Matrix<double> a(1, 1);
	//Matrix<double> b(2, 2);
	//a = Matrix<double>{ { 1,2,1 }, { 2.2,2.3,2 } };
	//b = Matrix<int>{ { 1,2,3 }, { 4,5,4}, { 3,6,7 } };

	//linalg::Matrix<double> c{ {12,18,18},{17.4,27.9,29.8} };
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;

	//cout << ((a * b) == c);
	linalg::Matrix<double> a = { { 1.5,2,3.22 }, {1,1.22,5}, { 2,-1.333,2} };
	linalg::Matrix<int> b = { { 1,2,3 }, {1,1,5}, { 2,-1,2} };
	linalg::Matrix<double> c(3, 3);
	a = 5 * a;
	c = b * a;
	cout << c;
	c.reserve(100);
	cout << c.capacity() << endl;
	c.shrink_to_fit();
	cout << c.capacity() << endl;
	c.clear();
	cout << c.capacity() << endl;
	cout << c.rows();
	//linalg::Matrix<double> m2(4, 6);
	//linalg::Matrix<double> m3 = m2;
	//linalg::Matrix<double> m4(std::move(m2));
	//cout << m3;
	//cout << m4;
	////cout << (m4 == m3);
	return 0;
}
