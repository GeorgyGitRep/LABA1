#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
class Product
{
public:
	Product();
	Product(const char* ValueName, const char* ValueDate, int ValueCount, double ValuePrice);
	
	~Product();
	void dispose();
	Product* copy();
	int equal(const Product&);
	int cmp(const Product&);
	int inputF();
	int input();
	void outputF();
	void output();
private:
	char* name;
	double price;
	int count;
	char date[15];
};
typedef Product* T;
