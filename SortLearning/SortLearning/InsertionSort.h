#ifndef _INSERTION_SORT_H__
#define _INSERTION_SORT_H__

#include "Common.h"

//升序排列，从小到大
template <typename T>
void InsertionSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	for (int ii = 1; ii < nLen; ii++)
	{
		for (int jj = ii; jj > 0 && arr[jj] < arr[jj-1]; jj--)
		{
			swap(arr[jj], arr[jj-1]);
		}
	}
}



#endif