#include <iostream>
using namespace std;
void mergeSortCore(int a[], int b[], int start, int end)
{
	if (start >= end)
		return;
	// 继续拆分子数组
	int mid = (start + end) >> 1;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	mergeSortCore(a, b, start1, end1);
	mergeSortCore(a, b, start2, end2);

	// 合并子数组
	int k = start;
	while (start1 <= end1 && start2 <= end2)
	{
		b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	}
	// 把剩下的元素补齐
	while (start1 <= end1)
		b[k++] = a[start1++];
	while (start2 <= end2)
		b[k++] = a[start2++];
	// 更新原始数组
	for (k = start; k <= end; k++)
		a[k] = b[k];
}
void mergeSort(int a[], const int n)
{
	int *b = new int[n];
	mergeSortCore(a, b, 0, n-1);
	delete [] b;
}
int main()
{
	int a[] = { 7, 5, 6, 4 };
	int len = sizeof(a) / sizeof(a[0]);
	cout << sizeof(a) << " " << sizeof(a[0]) << endl;
	mergeSort(a, len);
}