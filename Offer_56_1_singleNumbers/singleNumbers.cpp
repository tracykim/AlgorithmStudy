// 找到只出现1次的数字（这个数字有2个）
#include <iostream>
#include <vector>
using namespace std;
vector<int> singleNumbers(vector<int>& nums) {
	int res = 0;
	for (int num : nums)
	{
		res ^= num;
	}

	int h = 1;
	while ((res & h) == 0) // 从右往左找第一个不为1的位置
		h = h<<1;
	
	// 分成两组
	//vector<int> nums1, num2; // 没必要
	int res1 = 0, res2 = 0;
	for (int num : nums)
	{
		cout << (num & h) << endl;
		if ((num & h) == 0)
			res1 ^= num;
		else
			res2 ^= num;
	}
	return{res1, res2};
}
int main()
{
	vector<int> nums = { 2, 4, 3, 6, 3, 2, 5, 5 };
	vector<int> res = singleNumbers(nums);
}