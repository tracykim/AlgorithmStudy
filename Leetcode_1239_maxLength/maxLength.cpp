/*
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 超时
class Solution {
public:
	int maxLength(vector<string>& arr) {
		if (arr.size() == 1)
			return arr[0].length();
		dfs(arr, 0);
		return maxRes;
	}
private:
	//vector<string> strs;
	string cur;
	int curRes;
	int maxRes;
	unordered_set<char> set;
	void dfs(vector<string>& arr, int start) {
		if (start == arr.size())
		{
			maxRes=max(maxRes, curRes);
			return;
		}
		for (int i = start; i < arr.size(); i++)
		{
			string s = arr[i];
;			if (!contain(set, s)) { // 如果不重复添加
				//strs.emplace_back(arr[start]);
				curRes+= s.length();
				for (char c : s)
					set.insert(c);
				dfs(arr, start + 1);
				//strs.pop_back();
				curRes-=s.length();
				for (char c : s)
					set.erase(c);
			}
			else
				dfs(arr, start + 1);
		}
		
	}

	// set是否包含这个字符串中的字符
	bool contain(unordered_set<char> set, string s) {
		for (char c:s)
		{
			if (set.find(c) != set.end())
				return true;
		}
		return false;
	}
};

int main()
{
	vector<string> arr = { "cha","r","act","ers" };
	Solution sol;
	sol.maxLength(arr);
}