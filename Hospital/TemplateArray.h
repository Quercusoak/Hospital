#ifndef __TEMPLATE_ARRAY_H
#define __TEMPLATE_ARRAY_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include <vector>

template  <class  T>
class TemplateArray
{
	int physSize, logiSize;
	T* arr;

public:
	TemplateArray(int size) :physSize(size), logiSize(0) { arr = new T[size]; }
	void addObject(vector<T*>& arr, T& obj);

};

//----------------------------------------------------------------------------------------------------//
template <class T>
void TemplateArray<T>::addObject(vector<T*>& arr, T& obj)
{
	if (arr.capacity() == arr.size())
		arr.capacity() *= 2;
	arr.push_back(obj);
};


#endif