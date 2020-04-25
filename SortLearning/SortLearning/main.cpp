#include "Common.h"
#include "TestHelper.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

#define SORT_KINDS_NUM 4 

int main()
{
	int nArrayLen = 10000;
	int nSwapTimes = 20;
	int * ppTestArray[3 * SORT_KINDS_NUM] = { 0 };  //有3种类型的测试数据，并且有 SORT_KINDS_NUM 种待测试的排序方法

	//SortTestHelper::PrintArr("RandomArr", (int*)pRandArr1, nArrayLen, 4);  //For 调试
	//排序过程
	//排序一个随机序列
	ppTestArray[0] = SortTestHelper::NewRandArr<int>(nArrayLen, 0, nArrayLen);
	for (int ii = 1; ii < SORT_KINDS_NUM; ii++)
	{
		ppTestArray[ii] = SortTestHelper::NewCopyArray<int>(ppTestArray[0], nArrayLen);
	}
	cout << endl << "Sort a array which is complete random :" <<"  DataLen="<<nArrayLen<<endl;
	//SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort,    ppTestArray[0], nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, ppTestArray[1], nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, ppTestArray[2], nArrayLen);
	SortTestHelper::TestSortPerform("Merge  Sort", MergeSort,     ppTestArray[3], nArrayLen);

	//排序一个近乎有序的序列
	cout << endl << "Sort a array which is nearly sorted :" << "  DataLen=" << nArrayLen << endl;
	ppTestArray[SORT_KINDS_NUM] = SortTestHelper::NewAlmostRandArr<int>(nArrayLen, 0, 1, nSwapTimes);
	for (int ii = SORT_KINDS_NUM + 1; ii < 2*SORT_KINDS_NUM; ii++)
	{
		ppTestArray[ii] = SortTestHelper::NewCopyArray<int>(ppTestArray[SORT_KINDS_NUM], nArrayLen);
	}
	//SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort,    ppTestArray[SORT_KINDS_NUM],     nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, ppTestArray[SORT_KINDS_NUM + 1], nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, ppTestArray[SORT_KINDS_NUM + 2], nArrayLen);
	SortTestHelper::TestSortPerform("Merge  Sort", MergeSort,     ppTestArray[SORT_KINDS_NUM + 3], nArrayLen);

	//排序一个有大量重复元素的序列
	cout << endl << "Sort a array which contains many same element :" << "  DataLen=" << nArrayLen << endl;
	ppTestArray[2 * SORT_KINDS_NUM] = SortTestHelper::NewRandArr<int>(nArrayLen, 0, 5);
	for (int ii = 2 * SORT_KINDS_NUM + 1; ii < 3 * SORT_KINDS_NUM; ii++)
	{
		ppTestArray[ii] = SortTestHelper::NewCopyArray<int>(ppTestArray[2 * SORT_KINDS_NUM], nArrayLen);
	}

	//SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort,    ppTestArray[2 * SORT_KINDS_NUM],     nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, ppTestArray[2 * SORT_KINDS_NUM + 1], nArrayLen);
	SortTestHelper::TestSortPerform("Insert Sort", InsertionSort, ppTestArray[2 * SORT_KINDS_NUM + 2], nArrayLen);
	SortTestHelper::TestSortPerform("Merge  Sort", MergeSort,     ppTestArray[2 * SORT_KINDS_NUM + 3], nArrayLen);

	for (int ii = 0; ii < 3 * SORT_KINDS_NUM; ii++)
	{
		SortTestHelper::DeleteRandArr <int>(ppTestArray[ii]);
	}

	cout << endl << "There are all results above ..." << endl;
	getchar();
	return 0;
}

///         以下所以结果都是我自己的旧电脑，应该是会偏慢，i3-2330M的hp电脑（自己加了ssd和内存），8年前买的了[捂脸]
//运行结果如下： V1.0.1
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



//运行结果如下： V1.0.2
//优化了插入排序
/*
Sort a array which is complete random : DataLen = 1000
Bubble Sort : 0.056s
Select Sort : 0.002s
Insert Sort : 0.001s

Sort a array which is nearly sorted : DataLen = 1000
Bubble Sort : 0.003s
Select Sort : 0.002s
Insert Sort : 0.001s

Sort a array which contains many same element : DataLen = 1000
Bubble Sort : 0.033s
Select Sort : 0.002s
Insert Sort : 0.001s
*/


//运行结果如下： V1.0.3
//加入了归并排序(未优化的归并)
/*数据长度1000
Sort a array which is complete random : DataLen = 1000
Bubble Sort : 0.056s
Select Sort : 0.002s
Insert Sort : 0.001s
Merge  Sort : 0.002s

Sort a array which is nearly sorted : DataLen = 1000
Bubble Sort : 0.004s
Select Sort : 0.002s
Insert Sort : 0s
Merge  Sort : 0.002s

Sort a array which contains many same element : DataLen = 1000
Bubble Sort : 0.035s
Select Sort : 0.002s
Insert Sort : 0.001s
Merge  Sort : 0.003s
*/
/* 数据长度10000
Sort a array which is complete random :  DataLen=10000
Bubble Sort:4.498s
Select Sort:0.206s
Insert Sort:0.106s
Merge  Sort:0.02s

Sort a array which is nearly sorted :  DataLen=10000
Bubble Sort:0.183s
Select Sort:0.197s
Insert Sort:0.000s
Merge  Sort:0.019s

Sort a array which contains many same element :  DataLen=10000
Bubble Sort:3.72s
Select Sort:0.195s
Insert Sort:0.099s
Merge  Sort:0.02s
*/  

//运行结果如下： V1.0.4
//加入了归并排序(优化后的归并)
/* 数据长度10000
Sort a array which is complete random : DataLen = 10000
Select Sort : 0.194s
Insert Sort : 0.105s
Merge  Sort : 0.006s

Sort a array which is nearly sorted : DataLen = 10000
Select Sort : 0.191s
Insert Sort : 0.001s
Merge  Sort : 0.002s

Sort a array which contains many same element : DataLen = 10000
Select Sort : 0.195s
Insert Sort : 0.078s
Merge  Sort : 0.004s

There are all results above ...
*/