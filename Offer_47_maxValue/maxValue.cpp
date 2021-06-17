#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return -1;
		int rows = grid.size();
		int cols = grid[0].size();

		vector<int> dp(cols);
		int up, left; // 上边、左边的礼物最大值
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				up = left = 0;
				if (i > 0)
				{
					up = dp[j];
				}
				if (j > 0)
				{
					left = dp[j - 1];
				}
				dp[j] = max(up, left) + grid[i][j];
			}
		}
		return dp[cols - 1];
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> grid = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	int res = sol.maxValue(grid);
}