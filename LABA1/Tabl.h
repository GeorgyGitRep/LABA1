#pragma once
#include"Product.h"
class Tabl {
private:
	T* m;
	T* cur;
	int size;
public:
	Tabl(int sz = 10);
	~Tabl();
	T* begin();
	T* end();
	int length();
	T* insert(const T& item);
	T* erase(T* pos);
	void clear();
	int getSize();
	int remove(const T& item);
	int find(const T& item);
	int replace(const T& Old, const T& New);
	void sort();
	int Input(T buf);
	void Output();
};
