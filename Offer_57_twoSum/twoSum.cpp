#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	// 常规做法 超时！
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		int len = nums.size();
		if (len<2)
			return res;
		for (int i = 0; i<len; i++)
		{
			if (nums[i]>target)
				break;
			for (int j = i + 1; j<len; j++)
			{
				if (nums[i] + nums[j] == target)
					return{ nums[i], nums[j] };
				else if (nums[i] + nums[j]>target)
					break;
			}
		}
		return res;
	}

	/*vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> res;
		int len = nums.size();
		if (len<2)
			return res;
		unordered_map<int, int> mp;
		for (int i = 0; i<len; i++)
		{
			if (mp.count(target - nums[i]))
				return{ mp[target - nums[i]], nums[i] };
			mp.insert(make_pair(nums[i], nums[i]));
		}
		return res;
	}*/
	/*vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> res;
		int len = nums.size();
		if (len<2)
			return res;
		unordered_set<int> set;
		for (int i = 0; i<len; i++)
		{
			if (set.count(target - nums[i]))
				return{ target - nums[i], nums[i] };
			set.insert(nums[i]);
		}
		return res;
	}*/
	// 双指针法
	vector<int> twoSum3(vector<int>& nums, int target) {
		vector<int> res;
		int len = nums.size();
		if (len<2)
			return res;
		int i = 0, j = len - 1;
		while (i<j)
		{
			if (nums[i] + nums[j] == target)
			{
				res.push_back(nums[i]);
				res.push_back(nums[j]);
				break;
			}
			if (nums[i] + nums[j] < target)
				i++;
			if (nums[i] + nums[j] > target)
				j--;

		}
		return res;
	}

};

int main()
{
	vector<int> nums = { 10,26,30,31,47,60 };
	Solution sol;
	vector<int> res = sol.twoSum3(nums, 40);
	unordered_map<string, int>::iterator it;
}