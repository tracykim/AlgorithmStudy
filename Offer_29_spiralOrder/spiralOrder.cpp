#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder0(vector<vector<int>>& matrix) {
		if (matrix.size() <= 0 || matrix[0].size()<=0)
			return{};
		int rows = matrix.size();
		int cols = matrix[0].size();
		
		vector<int> ans;
		int start = 0;
		while (2 * start<rows && 2 * start<cols)
		{
			// 打印一圈
			printCircle(ans, matrix, rows, cols, start);
			start++;
		}
		return ans;
	}
	void printCircle(vector<int>& ans, vector<vector<int>> matrix, int rows, int cols, int start)
	{
		int endX = rows - start - 1, endY = cols - start - 1;
		for (int j = start; j <= endY; j++)
			ans.push_back(matrix[start][j]);
		if (start < endX)
			for (int i = start + 1; i <= endX; i++)
				ans.push_back(matrix[i][endY]);
		if (start < endX && start < endY)
			for (int j = endY - 1; j >= start; j--)
				ans.push_back(matrix[endX][j]);
		if (start < endY && start<endX - 1)
			for (int i = endX - 1; i >= start + 1; i--)
				ans.push_back(matrix[i][start]);
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector <int> ans;
		if (matrix.empty()) return ans; //若数组为空，直接返回答案
		int u = 0; //赋值上下左右边界
		int d = matrix.size() - 1;
		int l = 0;
		int r = matrix[0].size() - 1;
		while (true)
		{
			for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
			if (++u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
			for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
			if (--r < l) break; //重新设定右边界
			for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
			if (--d < u) break; //重新设定下边界
			for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
			if (++l > r) break; //重新设定左边界
		}
		return ans;
	}

};

int main()
{
	vector<vector<int>> matrix = {
		{1,2,3,4},{5,6,7,8},{9, 10, 11,12}
	};
	Solution sol;
	vector<int> ans = sol.spiralOrder(matrix);
}