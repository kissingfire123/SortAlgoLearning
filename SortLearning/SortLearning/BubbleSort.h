#ifndef  __BUBBLE_SORT__
#define  __BUBBLE_SORT__
#include "Common.h"


//升序排列，从小到大  ,区间 [0,nLen )
template <typename T>
void BubbleSort(T arr[], int nLen)
{
	if (nullptr == arr || nLen <2)
	{
		return;
	}
	//优化1：如果上一轮没有发生交换，则表示排序提前完成
	bool nSwappedFlag = false;
	//优化2：对于第ii轮，记录最后那个发生交换的位置idx，下一轮ii轮直接从idx开始，避免局部有序列的重复操作. eg:原始6,4,7,5,1,3,2
	int  nLastLoopSwapIdx = 0;//nSwapTimes记录每一轮交换的最右侧，值最大的索引，表示右边已经局部有序
	int  nSwapTimes = nLen - 1;
	for (int ii =nLen - 1; ii > 0; ii--)
	{
		nSwappedFlag = false; 
		for (int jj = 0; jj < nSwapTimes /*ii*/; jj++)//nSwapTimes替换ii，缩短内层循环
		{
			if (arr[jj] > arr[jj + 1])
			{
				swap(arr[jj], arr[jj + 1]);
				nSwappedFlag = true;
				nLastLoopSwapIdx = jj;
			}
		}
		nSwapTimes = nLastLoopSwapIdx;
		if (!nSwappedFlag)
		{
			return;
		}
	}
}


#endif