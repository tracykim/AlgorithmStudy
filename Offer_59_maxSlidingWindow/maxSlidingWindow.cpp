#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow0(vector<int>& nums, int k) {
		int len = nums.size();
		if (len < k || k < 1)
			return{};		
		vector<int> res;
		// 初始化滑动窗口
		deque<int> deq;
		for (int i = 0; i < k; i++)
		{
			while (!deq.empty() && nums[i] >= nums[deq.back()])
			{
				deq.pop_back();
			}
			deq.push_back(i);
		}

		for (int i = k; i < len; i++)
		{
			res.push_back(nums[deq.front()]);
			while (!deq.empty() && nums[i] >= nums[deq.back()])
				deq.pop_back();
			if (!deq.empty() && deq.front() <= (i - k))
				deq.pop_front();
			deq.push_back(i);
		}
		res.push_back(nums[deq.front()]);
		return res;
	}

	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n < k || k < 1)
			return{};
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < k; ++i) {
			q.emplace(nums[i], i);
		}
		vector<int> ans = { q.top().first };
		for (int i = k; i < n; ++i) {
			q.emplace(nums[i], i);
			while (q.top().second <= i - k) { //最大值被移出去了
				q.pop();
			}
			ans.push_back(q.top().first);
		}
		return ans;
	}

};

int main()
{
	Solution sol;
	vector<int> nums = { 3,3,5,5,6,7 };
	sol.maxSlidingWindow(nums, 3);
}