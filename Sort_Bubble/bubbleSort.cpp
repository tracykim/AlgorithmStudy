#include <iostream>
using namespace std;
void bubbleSort(int a[], int len)
{
	for (int i = 0; i < len - 1;i++)
	{
		for (int j = 0; j < len - i - 1;j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int a[] = { 3,5,2,1,4,2 };
	int len = sizeof(a) / sizeof(int);
	bubbleSort(a, len);
}