#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int i=0, j=0;//iָ������㣬jָ��������
		int m=0, cur; // ������󣬵�ǰ����
		while (i<len)
		{
			for (; j < len;j++)
			{
				if (prices[j] < prices[i])
					i = j;
				else
				{
					cur = prices[j] - prices[i];
					m = cur > m ? cur : m;
				}
			}
			i++;
		}
		return m;
	}

	int maxProfit2(vector<int>& prices) {
		int len = prices.size();
		if (len == 0)
			return 0;
		int mi = prices[0], profit=0; // ǰi-1����Сֵ, ǰi-1���������
		for (int i = 1; i < len;i++)
		{
			profit = prices[i] - mi > profit ? prices[i] - mi : profit;
			mi = prices[i] < mi ? prices[i] : mi;
		}
		
		return profit;
	}
};
int main()
{

}