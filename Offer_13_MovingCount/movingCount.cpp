/*
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ��
�������ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
�������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
���ʸû������ܹ�������ٸ����ӣ�
*/
#include <vector>
using namespace std;
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> used(m, vector<bool>(n, false)); // �������Ƿ��߹�
		int res = dfs(m, n, k, 0, 0, used);
		return res;
	}
private:
	int dfs(int m, int n, int k, int i, int j, vector<vector<bool>>& used)
	{
		// ����i+j>k��
		if (i<0 || i>=m || j<0 || j>=n || sum0(i) + sum0(j) > k || used[i][j]==true)
			return 0;
		// ��ѡ��
		used[i][j] = true;
		return 1+dfs(m, n, k, i+1, j, used)
			+ dfs(m, n, k, i-1, j, used)
			+ dfs(m, n, k, i, j+1, used)
			+ dfs(m, n, k, i, j-1, used);
		// ע�⣬����û���������⣬���Ի����˲���������
		// ���Բ��ó���ѡ��
		
	}
	// λ����
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