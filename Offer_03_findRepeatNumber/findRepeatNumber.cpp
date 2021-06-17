#include <vector>
#include <unordered_set>
using namespace std;
class Solution0 {
public:
	int findRepeatNumber(vector<int>& nums) {
		unordered_set<int> set;
		for (int n:nums)
		{
			if (set.find(n)!=set.end())
				return n;
			set.insert(n);
		}
		return -1;
	}
};

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {	
		int temp;
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i)
			{
				if (nums[i] == nums[nums[i]])
					return nums[i];
				temp = nums[i];
				nums[i] = nums[nums[i]];
				nums[temp] = temp;
			}
		}
		return -1;
	}
};
int main()
{
	vector<int> nums = { 2, 3, 1, 0, 2, 5, 3 };
	Solution sol;
	sol.findRepeatNumber(nums);
}