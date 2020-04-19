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
	T nCurrentTailVal = arr[1];
	int jj = 0;
	for (int ii = 1; ii < nLen; ii++)
	{
		nCurrentTailVal = arr[ii];
		//优化选择排序，保存当前这轮循环的考察值arr[ii]，依次比较，用赋值代替交换操作（一次交换有3次赋值）
		//而且这样做同样可以提前终止循环
		for (jj = ii; jj > 0 && nCurrentTailVal < arr[jj-1]; jj--)
		{
			//swap(arr[jj], arr[jj-1]);
			arr[jj] = arr[jj-1];
		}
		arr[jj] = nCurrentTailVal;//找到了他应该放的位置，直接赋值过去，终止当前内层循环
	}
}



#endif