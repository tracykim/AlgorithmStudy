#include <vector>
using namespace std;
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int n = matrix.size();
		int m = matrix[0].size();
		int i = 0, j = m - 1; // 从右上角开始遍历
		while (i<n && j>=0)
		{
			if (target == matrix[i][j])
				return true;
			else if (target < matrix[i][j])
				j--;
			else
				i++;
		}
		return false;
	}
};

int main()
{
	vector<vector<int>> matrix = {
		{1,4,7,11,15},
		{2,5,8,12,19},
		{3,6,9,16,22},
		{10,13,14,17,24},
		{18,21,23,26,30}	 
	};
	Solution sol;
	sol.findNumberIn2DArray(matrix, 5);
}