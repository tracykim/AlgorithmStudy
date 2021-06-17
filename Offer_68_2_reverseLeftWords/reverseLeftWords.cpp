#include <string>
using namespace std;
class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int len = s.length();
		string s1 = s.substr(0, n%len);
		string s2 = s.substr(n%len, len - n%len);
		return s2 + s1;
	}
};

int main()
{
	string s = "abcdefg";
	Solution sol;
	string res = sol.reverseLeftWords(s, 2);

}