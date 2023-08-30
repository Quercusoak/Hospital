#ifndef __CLEAN_BUFFER_H
#define __CLEAN_BUFFER_H

#include <iostream>
using namespace std;

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

#endif