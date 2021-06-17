/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格
（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？
*/
#include <vector>
using namespace std;
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> used(m, vector<bool>(n, false)); // 机器人是否走过
		int res = dfs(m, n, k, 0, 0, used);
		return res;
	}
private:
	int dfs(int m, int n, int k, int i, int j, vector<vector<bool>>& used)
	{
		// 计算i+j>k？
		if (i<0 || i>=m || j<0 || j>=n || sum0(i) + sum0(j) > k || used[i][j]==true)
			return 0;
		// 做选择
		used[i][j] = true;
		return 1+dfs(m, n, k, i+1, j, used)
			+ dfs(m, n, k, i-1, j, used)
			+ dfs(m, n, k, i, j+1, used)
			+ dfs(m, n, k, i, j-1, used);
		// 注意，本体没有限制问题，所以机器人不用往回走
		// 所以不用撤销选择
		
	}
	// 位数和
	int sum0(int i)
	{
		int res = 0;
		while (i != 0)
		{
			res += i % 10;
			i = i / 10;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	int m = 4, n = 6, k = 15;
	int res = sol.movingCount(m, n, k);
}