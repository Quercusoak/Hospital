#include "BaseFunc.h"


void* rerealloc(void* arr, int elemSize, int numElem, int newElemSize)
{
	BYTE* temp = new BYTE[elemSize * newElemSize];

	for (int i = 0; i < elemSize * numElem; i++) {
		temp[i] = ((BYTE*)arr)[i];	
	}

	delete[]((BYTE*)arr);
	return temp;
}