#include "Common.h"
#include "TestHelper.h"
#include "BubbleSort.h"
#include "SelectionSort.h"

int main()
{
	int nArrayLen = 10000;
	int nSwapTimes = 20;
	int *pRandArr = SortTestHelper::NewRandArr<int>(nArrayLen, 0, nArrayLen);
	//SortTestHelper::PrintArr("RandomArr", (int*)pRandArr1, nArrayLen, 4);  //For µ÷ÊÔ
	//ÅÅÐò¹ý³Ì
	SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort, pRandArr, nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, pRandArr, nArrayLen);

	int *pAlmostRandArr = SortTestHelper::NewAlmostRandArr<int>(nArrayLen, 0, 1, nSwapTimes);
	SortTestHelper::TestSortPerform("Bubble Sort", BubbleSort, pAlmostRandArr, nArrayLen);
	SortTestHelper::TestSortPerform("Select Sort", SelectionSort, pAlmostRandArr, nArrayLen);

	SortTestHelper::DeleteRandArr <int>(pAlmostRandArr);
	SortTestHelper::DeleteRandArr <int>(pRandArr);
	getchar();
	return 0;
}