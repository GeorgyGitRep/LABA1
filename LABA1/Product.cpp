#include "Product.h"
#include <iostream>
//#include <stdio.h>
using namespace std;
Product::Product() {


	name = new char[1];
	*name = '\0';
	date[0] = '\0';
	count = 0;
	price = 0.0;


}
Product::Product(const char* ValueName, const char* ValueDate, int ValueCount, double ValuePrice) {


	name = new char[strlen(ValueName) + 1];
	strcpy_s(name, strlen(ValueName) + 1, ValueName);
	strcpy_s(date, sizeof date, ValueDate);
	count = ValueCount;
	price = ValuePrice;


}
void Product::dispose() {
	delete[] name;
}
Product::~Product() {
	dispose();
}
Product* Product::copy() {
	return new Product(*this);
}
int Product::equal(const Product& t) {
	return ((name && t.name[0] != 0) ? !strcmp(name, t.name) : 1) && ((date[0] != 0) ? !strcmp(date, t.date) : 1) &&		((count != 0) ? count == t.count : 1) && ((price != 0) ? price == t.price : 1);
}
int Product::cmp(const Product& t) {
	int cond;

	if (name[0] != 0 && (cond = strcmp(name, t.name)))return cond;
	else if (date[0] != 0 && (cond = strcmp(date, t.date)))return cond;
	else return count - t.count;
}
int Product::inputF()
{
	ofstream fout;
	string path = name;
	path = path + ".txt";
	fout.open(path);
	if (fout.is_open()) {
		fout <<name<<endl<<date<<endl<<count<<endl<<price<<endl ;

	}
	else {
		cout << "file is not open";
		return 0;
	}
	fout.close(); 
	return !cin.eof();
}
int Product::input() {
	static int number;
	char c, endline, end;
	char buf[256];//delete title[]

	cout.width(10); cout << "name" << " ";
	cin.getline(buf, 254, '\n');
	if (cin.eof())return 0;
	name = new char[strlen(buf) + 1];
	strcpy_s(name, strlen(buf) + 1, buf);

	cout.width(10); cout << "date" << " ";
	cin.getline(buf, sizeof date, '\n');
	strcpy_s(date, sizeof date, buf);

	cout.width(10); cout << "count" << " ";
	cin >> count; cin.get(endline);

	cout.width(10); cout << "price" << " ";
	cin >> price; cin.get(endline);
	if (!cin.eof()) {
		//cin.unget();
		cout << "---------------------" << number++ << "\n";
		return 1;
	}
	return 0;

}
void Product::outputF() {
	ifstream fin;
	string s;
	int index = 0;
	string sArr[4];
	string path = name;
	path = path + ".txt";
	fin.open(path);
	if (fin.is_open()) {
		while (getline(fin, s)) {
			sArr[index] = s;
			index++;
		}
		cout.width(35); cout << "+=+=+=+=+=+=+=+=+=+=+=+PRODUCT+=+=+=+=+=+=+=+=+=+=+=+" << endl;
		cout.width(13); cout << "NAME";
		cout.width(13); cout << "DATE";
		cout.width(13); cout << "COUNT";
		cout.width(13); cout << "PRICE" << endl;
		cout.width(13); cout << sArr[0];
		cout.width(13); cout << sArr[1];
		cout.width(13); cout << sArr[2];
		cout.width(13); cout << sArr[3] << endl;
		cout.width(35); cout << "+=+=+=+=+=+=+=+=+=+=+=+PRODUCT+=+=+=+=+=+=+=+=+=+=+=+" << endl;
	}
	else {
		cout << "file is not open";
	}
	fin.close();
};
void Product::output() {
	
		cout.width(35); cout << "+=+=+=+=+=+=+=+=+=+=+=+PRODUCT+=+=+=+=+=+=+=+=+=+=+=+" << endl;
		cout.width(13); cout << "NAME";
		cout.width(13); cout << "DATE";
		cout.width(13); cout << "COUNT";
		cout.width(13); cout << "PRICE" << endl;
		cout.width(13); cout << name;
		cout.width(13); cout << date;
		cout.width(13); cout << count;
		cout.width(13); cout << price << endl;
		cout.width(35); cout << "+=+=+=+=+=+=+=+=+=+=+=+PRODUCT+=+=+=+=+=+=+=+=+=+=+=+" << endl;
		cout << "\n";
	
}