/*
数组中出现次数超过一半的数
*/
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int len = nums.size();
		int mid = len / 2;
		int index = partition(nums, 0, len - 1);

		while (index != mid)
		{
			if (index<mid)
				index = partition(nums, index + 1, len - 1);
			else
				index = partition(nums, 0, index - 1);
		}
		return nums[index];
	}
	int partition(vector<int>& arr, int left, int right)
	{
		int pivot = arr[RandomInRange(left, right)];
		while (left<right)
		{
			// 右边找到比基准值小的，交换
			while (left<right && arr[right] >= pivot)
				right--;
			swap(arr, left, right);
			// 左边找到比基准值大的的，交换
			while (left<right && arr[left] <= pivot)
				left++;
			swap(arr, left, right);
		}
		return left;
	}


	void swap(vector<int>& num, int i, int j)
	{
		int temp = num[i];
		num[i] = num[j];
		num[j] = temp;
	}
	// Random Partition
	int RandomInRange(int min, int max)
	{
		int random = rand() % (max - min + 1) + min;
		return random;
	}
};
int main()
{
	vector<int> nums = { 2,2,1,1,1,2,2 };
	Solution sol;
	int res = sol.majorityElement(nums);
}