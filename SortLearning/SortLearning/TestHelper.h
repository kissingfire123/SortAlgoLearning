#ifndef  __TEST_HELPER_H__
#define  __TEST_HELPER_H__

#include "Common.h"


//运行时间(单位：秒)保留到小数点后的几位
#define DECIMAL_PRECISION   3    

namespace SortTestHelper
{
	//生成一个长度nLen的随机数组，范围为[minVal,maxVal],初始逆序次数为nSwapTimes
	template <typename T>
	T* NewRandArr(int nLen, T minVal, T maxVal)
	{
		assert(minVal < maxVal);
		srand((unsigned int)time(NULL));
		T *pRandArr = new T[nLen];
		for (int ii = 0; ii < nLen; ii++)
		{
			pRandArr[ii] = rand() % (maxVal - minVal + 1) + minVal;
		}
		return pRandArr;
	}

	//生成一个长度nLen的近乎有序的数组，startVal为起始值，新建数组时的步进为interval,将有序数组随机交换nSwapTime次
	template <typename T>
	T* NewAlmostRandArr(int nLen, T startVal, T interval, int nSwapTimes)
	{
		srand(time(NULL));
		T *pRandArr = new T[nLen];
		for (int ii = 0; ii < nLen; ii++)
		{
			pRandArr[ii] = startVal + ii*interval;
		}
		for (int jj = 0; jj < nSwapTimes; jj++)
		{
			int Index1 = rand() % nLen;
			int Index2 = rand() % nLen;
			swap(pRandArr[Index1],pRandArr[Index2]);
		}
		return pRandArr;
	}

	//释放空间
	template <typename T>
	bool DeleteRandArr(T* &pRandArr)
	{
		if (nullptr != pRandArr)
		{
			delete[]pRandArr;
			pRandArr = nullptr;
		}
		else{
			return false;
		}
		
		return true;
	}

	//打印一个数组
	template <typename T>
	void PrintArr(string strArrName, T arr[], int nLen,int nDataBitWidth=0)
	{
		cout << strArrName.c_str() << " is :" << endl;
		for (int ii = 0; ii < nLen; ii++)
		{
			if (0 != nDataBitWidth)//设置打印时候的位宽
			{
				cout <<setw(nDataBitWidth)<< arr[ii] << " ";
			}
			else{
				cout << arr[ii] << " ";
			}

			
			if (0 == (ii+1) % 20)
			{
				cout << endl;
			}
		}
	}

	//测试一个排序函数 ,注意函数指针的用法
	template <typename T>
	void  TestSortPerform(string strSortName, void (*pSortFunc)(T[], int), T arr[], int nLen)
	{
		clock_t tStartTime = clock();
		pSortFunc(arr, nLen);
		clock_t tStopTIme = clock();
		if (!IsSorted(arr, nLen))
		{
			cout << "Array haven't been sorted!" << endl;
			return;
		}
		///设置一定的浮点精度
		cout << setiosflags(ios::fixed);//保证setprecision()是设置小数点后的位数,而不是整数和小数总位数
		cout << strSortName.c_str() << ":" << setprecision(DECIMAL_PRECISION) << double(tStopTIme - tStartTime) / CLOCKS_PER_SEC << "s" << endl;
	}

	//判断一个数组是否是从小到大排序成功的
	template <typename T>
	bool IsSorted(T arr[],int nLen)
	{
		for (int ii = 0; ii < nLen-1; ii++)
		{
			if (arr[ii] > arr[ii + 1])
			{
				return false;
			}
		}
		return true;
	}

	template <typename T>
	T*  NewCopyArray( T*arrSrc, int nLen)
	{
		T *pNewCopyArr = new T[nLen];
		memcpy_s(pNewCopyArr, nLen*sizeof(T),arrSrc, nLen*sizeof(T));
		return pNewCopyArr;
	}
	
};
#endif