#ifndef __QUICK_SORT__
#define __QUICK_SORT__

#include "Common.h"

//升序排列，从小到大  ,区间 [0,nLen )
template <typename T>
void QuickSort(T arr[], int nLen)
{
	srand(time(NULL));
	__qucikSort(arr, 0, nLen-1);
}

//升序排列，从小到大  ,区间 [idxL,idxR]
template <typename T>
void __qucikSort(T arr[], int idxL, int idxR)
{
	//优化操作2：当快速排序的排序片段短到一定长度时，转而用插入排序方法加速
	if (idxR - idxL < 16)
	{
		InsertionSort_Part(arr, idxL, idxR);
		return;
	}
	int nAnchorIdx = __partition(arr, idxL, idxR);
	__qucikSort(arr, idxL, nAnchorIdx);
	__qucikSort(arr, nAnchorIdx + 1, idxR);
}

//对区间[idxL,idxR]的元素进行partition操作，设定参考锚定值Anchor，左边的元素小于Anchor,右边元素大于Anchor
template <typename T>
int __partition(T arr[], int idxL, int idxR)
{
	//优化操作1：为避免极端数据提升复杂度，先随机一个锚定值放到第一个元素的位置
	int nRandIdx = (int)(idxL +  (rand() % (idxR - idxL + 1 )));
	swap(arr[idxL], arr[nRandIdx]);

	T Anchor = arr[idxL];
	int left  = idxL+1;
	int right = idxR;
	while (true)
	{
		while (arr[left]<Anchor && left <= idxR)left++;
		while (arr[right]>Anchor && idxL < right)right--;
		if (left > right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	//至此，相对位置关系为right ... left
	//即arr[right]是最后一个 ≤ Anchror的元素，arr[left]是第一个≥  Anchror的元素
	swap(arr[idxL], arr[right]);
	return right;
}











#endif