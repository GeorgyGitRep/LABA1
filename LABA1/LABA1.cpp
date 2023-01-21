#include <iostream>
#include "Product.h"
using namespace std;
int main()
{
	int info;

	Product zz("Adsd", "15.08.2012", 42, 9.5);
	Product vv("sdsd", "12.01.2007", 12, 4.5);
	Product tt = Product();
	cout << "input new Product" << endl;
	tt.input();
	vv.output();
	zz.output();
	tt.output();
	const Product & A= zz;
	cout << "equal vv  and  zz" << endl;
	info = vv.equal(A);
	cout << info<<endl;

	cout << "cmp vv  and  zz" << endl;
	info = vv.cmp(A);
	cout << info<<endl;


	zz.inputF();
	vv.inputF();

	cout << "outputF vv  and  zz" << endl;
	zz.outputF();
	vv.outputF();
	return 0;
}
