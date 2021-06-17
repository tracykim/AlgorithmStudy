#include <vector>
#include <iostream>
//#include <stdio.h>
using namespace std;

int partition(vector<int> &arr, int left, int right);
void quickSort(vector<int> &arr, int left, int right);
int RandomInRange(int min, int max);

vector<int> MySort(vector<int>& arr) {
	// write code here
	quickSort(arr, 0, arr.size() - 1);
	return arr;
}

void quickSort(vector<int> &arr, int left, int right)
{
	if (left >= right) return;
	int mid = partition(arr, left, right);
	quickSort(arr, left, mid - 1);
	quickSort(arr, mid + 1, right);
}

//int partition(vector<int> &arr, int left, int right) {
//	// 最后一个值当做标杆
//	int counter = left;
//	while (left < right) {
//		if (arr[left] < arr[right]) { // 当前值和标杆值比较，决定是放在左边还是右边
//			swap(arr[left], arr[counter]);
//			counter++;
//		}
//		left++;
//	}
//	swap(arr[counter], arr[right]);   // 最后把标杆值移到中间位置，然后返回下标。
//	return counter;
//}

//双指针
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    while(left<right)
    {
        // 右边找到比基准值小的，交换
        while(left<right && arr[right] >= pivot)
            right--;
        swap(arr[left], arr[right]);
        // 左边找到比基准值大的的，交换
        while(left<right && arr[left] <= pivot)
            left++;
        swap(arr[left], arr[right]);
    }
    return left;
}

//int partition(vector<int>& nums, int l, int r) {
//	int pivot = nums[r];
//	//int pivot = nums[RandomInRange(l, r)];
//
//	int i = l - 1;
//	for (int j = l; j <= r - 1; ++j) {
//		if (nums[j] <= pivot) {
//			i = i + 1;
//			swap(nums[i], nums[j]);
//		}
//	}
//	swap(nums[i + 1], nums[r]);
//	return i + 1;
//}

int RandomInRange(int min, int max)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

int main()
{
	//vector<int> arr = { 1, 1, 2, 2, 2, 2, 2 };
	vector<int> arr = { 4, 1, 6, 7, 2, 2, 1 };

	quickSort(arr, 0, arr.size()-1);
}