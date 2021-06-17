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
//	// ���һ��ֵ�������
//	int counter = left;
//	while (left < right) {
//		if (arr[left] < arr[right]) { // ��ǰֵ�ͱ��ֵ�Ƚϣ������Ƿ�����߻����ұ�
//			swap(arr[left], arr[counter]);
//			counter++;
//		}
//		left++;
//	}
//	swap(arr[counter], arr[right]);   // ���ѱ��ֵ�Ƶ��м�λ�ã�Ȼ�󷵻��±ꡣ
//	return counter;
//}

//˫ָ��
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    while(left<right)
    {
        // �ұ��ҵ��Ȼ�׼ֵС�ģ�����
        while(left<right && arr[right] >= pivot)
            right--;
        swap(arr[left], arr[right]);
        // ����ҵ��Ȼ�׼ֵ��ĵģ�����
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