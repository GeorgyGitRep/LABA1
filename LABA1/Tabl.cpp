#include "Tabl.h"
Tabl::Tabl(int sz) {
	cur = m = new T[size = sz];
}
Tabl::~Tabl()
{
	clear();
	delete[] m;
}
T* Tabl::begin() { return m; }
T* Tabl::end() { return cur; }
int Tabl::length() { return cur - m; }
int Tabl::getSize() { return size; }
T* Tabl::insert(const T& item){
	if (length() < size)
		*cur++ = item->copy();
	return cur;
}
T* Tabl::erase(T* pos){
	T* i;
	(*pos)->dispose();
	for (i = pos; i < cur; i++)
		*i = *(i + 1);
	cur--;
	return pos;
}
void Tabl::clear(){
	T* i;
	for (i = m; i < cur; i++)
	{
		(*i)->dispose();
		delete (*i);
	}
	cur = m;
}
int Tabl::remove(const T& item){
	T* i, * j = m; int n = 0;
	for (i = m; i < cur; i++)
		if (!(*i)->equal(*item))
			*j++ = *i;
		else { (*i)->dispose(); n++; }
	cur = j;
	return n;
}
int Tabl::find(const T& item){
	T* i;
	for (i = m; i < cur; i++)
		if ((*i)->equal(*item)) return i - m;
	return -1;
}
int Tabl::replace(const T& Old, const T& New){
	T* i; int count = 0;
	for (i = m; i < cur; i++)
		if ((*i)->equal(*Old)){
			(*i)->dispose();
			(*i) = (New)->copy();
			count++;
		}
	return count;
}
void Tabl::sort() {
	int i, j, len = length();
	for (j = 0; j < len - 1; j++)
		for (i = 0; i < len - 1 - j; i++)
			if (m[i]->cmp(*m[i + 1]) > 0)
			{
				T tmp = m[i];
				m[i] = m[i + 1];
				m[i + 1] = tmp;
			}
}
int Tabl::Input(T buf){
	int count;
	for (count = 0; count < getSize() && buf->input(); count++)
		insert(buf);
	return count;
}
void Tabl::Output(){
	T* i;
	for (i = begin(); i != end(); i++)
		(*i)->output();
}