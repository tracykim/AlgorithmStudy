#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
	bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int diff; //前后两个数字的差
		int count = 0; //统计0的个数
		for (int i = 0; i < nums.size();i++)
		{
			if (nums[i] == 0)
			{
				count++;
				continue;
			}
			if (i >= 1 && nums[i - 1] != 0)
			{
				diff = nums[i] - nums[i - 1];
				if (diff == 0)
					return false;
				else if (diff != 1)
					count -= (diff - 1);
				if (count < 0)
					return false;
			}
		}
		return true;
	}

	bool isStraight2(vector<int>& nums) {
		set<int> s;
		int min0 = 0, max0 = 14;
		for (int i = 0; i < nums.size();i++)
		{
			if (!nums[i]) continue;
			// 如果有重复数字
			if (!s.empty() && s.count(nums[i]))
				return false;
			min0 = min(min0, nums[i]);
			max0 = max(max0, nums[i]);
			s.insert(nums[i]);
		}
		
		return max0-min0<5;
	}

	bool isStraight3(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				count++;
				continue;
			}
			if (i >= 1 && nums[i]==nums[i-1])
			{
				return false;
			}
		}

		return nums[4] - nums[count] < 5;
	}
};

int main()
{
	Solution sol;
	vector<int> n = { 0,0,1,2,5 };
	sol.isStraight(n);

}
