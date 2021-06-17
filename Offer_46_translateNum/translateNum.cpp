#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int translateNum(int num) {
		string s = to_string(num);
		int len = s.length();
		int p=1, q=1, r=1; // f(i-2),f(i-1),f(i)
		int n;
		for (int i = 0; i < len; i++)
		{
			if (i == 0)
			{
				continue;
			}
			
			r = 0;
			r += q;				
			n = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (n >= 10 && n <= 25)
				r += p;				
			
			p = q;
			q = r;
		}
		return r;
	}
};

int main()
{
	Solution sol;
	sol.translateNum(122);
}