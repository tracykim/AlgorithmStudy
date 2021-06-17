#include<iostream>
#include<vector>
using namespace std;

// �ݹ鷽ʽ���������(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±�)
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index�����ӽڵ�
	int right = 2 * index + 2;// index�����ӽڵ�

	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx])     maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx])     maxIdx = right;

	if (maxIdx != index)
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);
	}

}

// ������
void heapSort(vector<int> &arr, int size)
{
	// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}

	// ���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
		adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
	}
}

int main()
{
	vector<int> arr = { 4,6,8,5,9 }; // { 8, 1, 14, 3, 21, 5, 7, 10 };
	heapSort(arr, arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}