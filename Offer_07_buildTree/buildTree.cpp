#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0 || inorder.size() == 0)
			return nullptr;
		TreeNode* root;
		for (int i = 0; i < inorder.size(); i++)
		{
			mp[inorder[i]] = i;
		}
		return recur(preorder, 0, 0, inorder.size() - 1);
	}

private:
	unordered_map<int, int> mp;
	/**
	 * 前序遍历、中序遍历、前序遍历根节点下标、中序遍历左边界、中序遍历右边界
	 */
	TreeNode* recur(vector<int>& preorder, int pre_root, int in_left, int in_right) {
		if (in_left > in_right)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[pre_root]);
		int in_root = mp[preorder[pre_root]]; // 中序遍历根节点下标
		root->left = recur(preorder, pre_root + 1, in_left, in_root-1);
		root->right = recur(preorder, pre_root + in_root - in_left + 1, in_root + 1, in_right);
		return root;
	}

};
int main()
{

}