#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int i=0, j=0;//i指向买入点，j指向卖出点
		int m=0, cur; // 最大利润，当前利润
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
		int mi = prices[0], profit=0; // 前i-1个最小值, 前i-1个最大利润、
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