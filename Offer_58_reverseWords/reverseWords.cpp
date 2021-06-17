#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		string res, tmp;
		stack<string> stk;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
				tmp+=s[i];
			else if(s[i] == ' ' && i>=1 && s[i-1]!=' ') {
				if (tmp != "")
				{
					stk.emplace(tmp);
					tmp = "";
				}
			}
		}
		if (tmp != "")
		{
			stk.emplace(tmp);
			tmp = "";
		}
		while (!stk.empty())
		{
			res += stk.top() + " ";
			stk.pop();
		}
		res = std::move(res.substr(0, res.length() - 1));
		return res;
	}

};

int main()
{
	string s = "  hello world! ";
	Solution sol;
	sol.reverseWords(s);
}