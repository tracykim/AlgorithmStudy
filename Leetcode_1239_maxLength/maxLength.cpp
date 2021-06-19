/*
����һ���ַ������� arr���ַ��� s �ǽ� arr ĳһ�������ַ����������õ��ַ�������� s �е�ÿһ���ַ���ֻ���ֹ�һ�Σ���ô������һ�����н⡣

�뷵�����п��н� s ������ȡ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// ��ʱ
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
;			if (!contain(set, s)) { // ������ظ����
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

	// set�Ƿ��������ַ����е��ַ�
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