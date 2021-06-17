#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.size() <= k || k == 0)
			return{};
		priority_queue<int, vector<int>, less<int>>q; // ´ó¸ù¶Ñ
		for (int i = 0; i<arr.size(); i++)
		{
			if (q.size() < k)
			{
				q.push(arr[i]);
				continue;
			}
			if (arr[i]<q.top())
			{
				q.pop();
				q.push(arr[i]);
			}
		}
		vector<int> res(k, 0);
		for (int i = 0; i<k; i++)
		{
			res[i] = q.top();
			q.pop();
		}
		return res;
	}
};
int main()
{
	vector<int> arr = { 4,5,1,6,2,7,3,8 };
	Solution sol;
	vector<int> res = sol.getLeastNumbers(arr, 4);
}