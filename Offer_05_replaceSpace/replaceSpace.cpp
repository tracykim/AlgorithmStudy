#include <string>
using namespace std;
class Solution {
public:
	// ´´½¨ÐÂ×Ö·û´®
	string replaceSpace0(string s) {
		string res = "";
		for (char c:s)
		{
			if (c == ' ')
				res+="%20";
			else
				res+=c;
		}
		return res;
	}

	string replaceSpace(string s) {
		int len = 0, count=0;
		for (char c : s)
		{
			if (c == ' ')
				count++;
			len++;
		}
		s.resize(len + 2 * count);
		int p1 = len - 1, p2 = len + 2 * count - 1;
		while (p1!=p2)
		{
			if (s[p1] != ' ')
			{
				s[p2--] = s[p1--];
			}				
			else
			{
				s[p2 - 2] = '%';
				s[p2 - 1] = '2'; 
				s[p2] = '0';
				p1--;
				p2 -= 3;
			}
		}
		return s;
	}
};

int main()
{

}