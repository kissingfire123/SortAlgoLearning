#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "Common.h"
#include "InsertionSort.h"


//升序排列，从小到大  ,区间 [0,nLen )
template <typename T>  
void MergeSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	__mergeSort(arr, 0, nLen - 1);
}


//对[arr[iLeft],arr[iRight]闭区间范围内进行递归排序
template <typename T>
void __mergeSort(T arr[], int iLeft, int iRight)
{
	if (iLeft >= iRight)
	{
		return;
	}

	//优化操作2：当归并排序的排序片段短到一定长度时，转而用插入排序方法加速
	if (iRight - iLeft < 16)
	{
		InsertionSort_Part(arr, iLeft,iRight);
		return;
	}

	int iMiddle = (iRight - iLeft) / 2 + iLeft;//不用相加求平均，防止溢出int范围
	__mergeSort(arr, iLeft, iMiddle);
	__mergeSort(arr, iMiddle + 1, iRight);

	//优化操作 1 ：加上这个if判定，可以在数组arr排序提前完成后省去多余的操作；即如果if不成立，表示此时整个arr排序好了
	//针对情况：数组arr本身是近乎有序的
	if (arr[iMiddle] > arr[iMiddle + 1]) 
	{
		__mergeOperation(arr, iLeft, iMiddle, iRight);
	}
}



//对2段有序数组进行合并操作
template <typename T>
void __mergeOperation(T arr[], int iLeft, int iMiddle, int iRight)
{
	assert(iLeft <= iMiddle);
	assert(iMiddle <= iRight);

	T *pSortBuffer = new T[iRight - iLeft + 1];//归并排序需要额外开辟一段空间给合并操作使用
	memcpy_s(pSortBuffer, (iRight - iLeft + 1)*sizeof(T), &arr[iLeft], (iRight - iLeft + 1)*sizeof(T));

	int idxL = iLeft;
	int idxR = iMiddle+1;
	int kk = iLeft;

	///首先确保左右下标的合法性
	for (int kk = iLeft; kk <= iRight; kk++)
	{
		if (idxL > iMiddle)
		{
			arr[kk] = pSortBuffer[idxR - iLeft];
			idxR++;
		}
		else if (idxR > iRight)
		{
			arr[kk] = pSortBuffer[idxL - iLeft];
			idxL++;
		}
		else if (pSortBuffer[idxL - iLeft] < pSortBuffer[idxR - iLeft])
		{
			arr[kk] = pSortBuffer[idxL - iLeft];
			idxL++;
		}
		else  /// if (pSortBuffer[idxL - iLeft] >= pSortBuffer[idxR - iLeft])
		{
			arr[kk] = pSortBuffer[idxR - iLeft];
			idxR++;
		}
	}
	SortTestHelper::DeleteRandArr(pSortBuffer);
}










#endif