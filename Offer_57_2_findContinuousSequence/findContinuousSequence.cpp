#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1, j = 2, sum=3;
		int mid = (1 + target) >> 1;
		vector<vector<int>> res;
		vector<int> tmp = {1, 2};
		while (i<mid)
		{			
			if (sum == target)
			{
				res.emplace_back(tmp);
			}
			while (sum>target && i<mid)
			{
				sum -= i++;
				tmp.erase(tmp.begin());
				if(sum == target)
					res.emplace_back(tmp);
			}
			sum+=++j;
			tmp.emplace_back(j);
		}
		return res;
	}
};

int main()
{
	Solution sol;
	sol.findContinuousSequence(9);
}