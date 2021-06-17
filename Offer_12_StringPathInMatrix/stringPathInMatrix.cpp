#include <vector>
using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				// 先在矩阵中找字符串的第一个字符
				if (board[i][j] != word[0])
					continue;
				if (dfs(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
private:
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int k)
	{
		if (i<0 || i>board.size() - 1 || j<0 || j>board[0].size() - 1 
			|| word[k] != board[i][j])
			return false;
		if (k == word.size()-1)
			return true;
		board[i][j] = '\0'; // 走过的路径不能在走
		bool res = dfs(board, word, i, j + 1, k + 1)
			|| dfs(board, word, i, j - 1, k + 1)
			|| dfs(board, word, i + 1, j, k + 1)
			|| dfs(board, word, i - 1, j, k + 1);
		board[i][j] = word[k]; // 撤销选择
		return res;
	}
};

// 剑指offer的做法
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols); // 赋值为false

	int pathLength = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
			{
				return true;
			}
		}
	}

	delete[] visited;

	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row,
	int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength]
		&& !visited[row * cols + col])
	{
		++pathLength;
		visited[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col,
				str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1,
				str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col,
				str, pathLength, visited);

		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}
int main()
{
	Solution sol;
	string word = "AAB";
	vector<vector<char>> board = {
		{ 'C', 'A', 'A' },
		{ 'A', 'A', 'A' },
		{ 'B', 'C', 'D' }
	};
	bool exist = sol.exist(board, word);
}