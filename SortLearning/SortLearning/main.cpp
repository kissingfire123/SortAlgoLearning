#include "Common.h"
#include "TestHelper.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

int main()
{
	int nArrayLen = 1000;
	int nSwapTimes = 20;

	//SortTestHelper::PrintArr("RandomArr", (int*)pRandArr1, nArrayLen, 4);  //For 调试
	//排序过程
	//排序一个随机序列
	int *pRandArr1 = SortTestHelper::NewRandArr<int>(nArrayLen, 0, nArrayLen);
	int *pRandArr2 = SortTestHelper::NewCopyArray<int>(pRandArr1, nArrayLen);
	int *pRandArr3 = SortTestHelper::NewCopyArray<int>(pRandArr1, nArrayLen);
	cout << endl << "Sort a array which is complete random :" <<"  DataLen="<<nArrayLen<<endl;
	SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort   , pRandArr1, nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, pRandArr2, nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, pRandArr3, nArrayLen);

	//排序一个近乎有序的序列
	cout << endl << "Sort a array which is nearly sorted :" << "  DataLen=" << nArrayLen << endl;
	int *pAlmostRandArr1 = SortTestHelper::NewAlmostRandArr<int>(nArrayLen, 0, 1, nSwapTimes);
	int *pAlmostRandArr2 = SortTestHelper::NewCopyArray<int>(pAlmostRandArr1, nArrayLen);
	int *pAlmostRandArr3 = SortTestHelper::NewCopyArray<int>(pAlmostRandArr1, nArrayLen);
	SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort   , pAlmostRandArr1, nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, pAlmostRandArr2, nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, pAlmostRandArr3, nArrayLen);



	//排序一个有大量重复元素的序列
	cout << endl << "Sort a array which contains many same element :" << "  DataLen=" << nArrayLen << endl;
	int *pRepeatedEleArr1 = SortTestHelper::NewRandArr<int>(nArrayLen, 0, 5);
	int *pRepeatedEleArr2 = SortTestHelper::NewCopyArray<int>(pRepeatedEleArr1, nArrayLen);
	int *pRepeatedEleArr3 = SortTestHelper::NewCopyArray<int>(pRepeatedEleArr1, nArrayLen);
	SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort, pRepeatedEleArr1, nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, pRepeatedEleArr2, nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, pRepeatedEleArr3, nArrayLen);


	SortTestHelper::DeleteRandArr <int>(pRepeatedEleArr1);
	SortTestHelper::DeleteRandArr <int>(pRepeatedEleArr2);
	SortTestHelper::DeleteRandArr <int>(pRepeatedEleArr3);
	SortTestHelper::DeleteRandArr <int>(pAlmostRandArr1);
	SortTestHelper::DeleteRandArr <int>(pAlmostRandArr2);
	SortTestHelper::DeleteRandArr <int>(pAlmostRandArr3);
	SortTestHelper::DeleteRandArr <int>(pRandArr1);
	SortTestHelper::DeleteRandArr <int>(pRandArr2);
	SortTestHelper::DeleteRandArr <int>(pRandArr3);
	getchar();
	return 0;
}

//运行结果如下：
/*
Sort a array which is complete random : DataLen = 1000
Bubble Sort : 0.052s
Select Sort : 0.002s
Insert Sort : 0.054s

Sort a array which is nearly sorted : DataLen = 1000
Bubble Sort : 0.005s
Select Sort : 0.002s
Insert Sort : 0.004s

Sort a array which contains many same element : DataLen = 1000
Bubble Sort : 0.046s
Select Sort : 0.002s
Insert Sort : 0.04s
*/