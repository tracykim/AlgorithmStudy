#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;     
	TreeNode *left;
    TreeNode *right;     
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return dfs(root) != -1;
	}

	int dfs(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = dfs(root->left);
		int right = dfs(root->right);
		if (left == -1 || right == -1)
			return -1;
		return abs(left-right)<=1 ? max(left, right) + 1 : -1;
	}
};
int main()
{
	Solution sol;
	TreeNode *n1 = new TreeNode(3);
	TreeNode *n2 = new TreeNode(9);
	TreeNode *n3 = new TreeNode(20);
	TreeNode *n4 = new TreeNode(15);
	TreeNode *n5 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;

	int ans = sol.isBalanced(n1);

}