#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		int count=0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] == target)
				count++;
		}
		return count;
	}
};

int main()
{
	vector<int> nums = { 5,7,7,8,8,10 };
	Solution sol;
	sol.search(nums, 8);
}