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
			// ��ӡһȦ
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
		if (matrix.empty()) return ans; //������Ϊ�գ�ֱ�ӷ��ش�
		int u = 0; //��ֵ�������ұ߽�
		int d = matrix.size() - 1;
		int l = 0;
		int r = matrix[0].size() - 1;
		while (true)
		{
			for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //�����ƶ�ֱ������
			if (++u > d) break; //�����趨�ϱ߽磬���ϱ߽�����±߽磬�����������ɣ���ͬ
			for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //����
			if (--r < l) break; //�����趨�ұ߽�
			for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //����
			if (--d < u) break; //�����趨�±߽�
			for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //����
			if (++l > r) break; //�����趨��߽�
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