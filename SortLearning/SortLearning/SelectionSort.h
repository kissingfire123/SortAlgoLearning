#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

//选择排序
//升序排列，从小到大  ,区间 [0,nLen )
template <typename T>
void SelectionSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	for (int ii = 0; ii < nLen-1; ii++)
	{
		T nTargetMin = arr[ii];//一轮选择中的最小值,优化算法所用
		int nTargetIndex = ii;//一轮选择中的最小值对应的索引号，这样保存Target值和索引的目的是避免频繁做swap操作
		for (int jj = ii + 1; jj < nLen; jj++)
		{
			if (arr[jj] < nTargetMin)
			{
				nTargetMin = arr[jj];
				nTargetIndex = jj;
			}
		}
		swap(arr[ii], arr[nTargetIndex]);
	}
}






#endif