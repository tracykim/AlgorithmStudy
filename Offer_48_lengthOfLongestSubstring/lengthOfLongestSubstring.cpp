#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	// ��������
	int lengthOfLongestSubstring0(string s) {
		if (s.length() == 0)
			return 0;
		int begin = 0, maxCount = 1;
		unordered_set<char> set;
		for (int i = 0; i < s.length(); i++)
		{
			while (set.find(s[i])!=set.end()) // �ַ��ظ�
			{
				set.erase(s[begin]);
				begin++;
			}
			maxCount = max(maxCount, i - begin + 1);
			set.insert(s[i]);
		}
		return maxCount;
	}
	//��̬�滮
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)
			return 0;
		unordered_map<char, int> mp;
		int count=0, maxCount=0, i=-1; // i: �ַ��ϴγ��ֵ�λ��
		
		for (int j = 0; j < s.length(); j++)
		{
			i = -1;
			if (mp.count(s[j]))
				i = mp[s[j]];
			count = count<j-i?count+1:j-i;
			mp[s[j]] = j;
			maxCount = max(maxCount, count);
		}
		return maxCount;
	}
};
int main()
{
	string s = "pwwkew";
	Solution sol;
	sol.lengthOfLongestSubstring(s);
}

