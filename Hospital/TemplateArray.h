#ifndef __TEMPLATE_ARRAY_H
#define __TEMPLATE_ARRAY_H

#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
#include "BaseFunc.h"

template  <class  T>
class TemplateArray
{
	int physicalSize, logicalSize;
	T** arr;
	void checkCapacity();

public:
	TemplateArray(int size = 1) :physicalSize(size), logicalSize(0) { arr = new T*[size]; }
	~TemplateArray() { delete[]arr; };

	void add(const T& obj);
	void add(T&& obj);

	const int size()		const { return logicalSize; }
	const int capacity()	const { return physicalSize; }

	T& operator[](int i);
	const TemplateArray<T>& operator+=(const T& newVal);
};


//----------------------------------------------------------------------------------------------------//
template <class T>
void TemplateArray<T>::add(const T& obj)
{
	checkCapacity();
	arr[logicalSize] = new T(obj);

	logicalSize++;
}


//----------------------------------------------------------------------------------------------------//
template <class T>
void TemplateArray<T>::add( T&& obj)
{
	checkCapacity();
	arr[logicalSize] = new T(std::move(obj));

	logicalSize++;
}

//----------------------------------------------------------------------------------------------------//
template <class T>
T& TemplateArray<T>::operator[](int i)
{ 
	return *arr[i]; 
}


//----------------------------------------------------------------------------------------------------//
template <class T>
void TemplateArray<T>::checkCapacity()
{
	if (!(physicalSize > logicalSize))
	{
		physicalSize *= 2;
		arr = (T**)rerealloc(arr, sizeof(T*), logicalSize, physicalSize);
	}
}


////----------------------------------------------------------------------------------------------------//
template<class T>
const TemplateArray<T>& TemplateArray<T>::operator+=(const T& obj)
{
	checkCapacity();

	arr[logicalSize] = new T(std::move(obj));

	logicalSize++;

	return *this;
}



#endif