#include <iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthLargest(TreeNode* root, int k) {
		// ÓÒ¸ù×ó£ºµÝ¼õÅÅÐò
		this->k = k;
		if (k<1)
			return -1;
		midPrint(root);		
		return ans;
	}
private:
	void midPrint(TreeNode* root)
	{
		if (root == nullptr)
			return;
		midPrint(root->right);
		if (k == 0) return;
		
		if (--k == 0)
			ans = root->val;
		midPrint(root->left);
	}
	int k;
	int ans;
};

int main()
{
	TreeNode* n1=new TreeNode(3);
	TreeNode* n2 = new TreeNode(1);
	TreeNode* n3 = new TreeNode(4);
	TreeNode* n4 = new TreeNode(2);
	n1->left = n2; n1->right = n3;
	n2->right = n4;
	
	Solution sol;
	sol.kthLargest(n1, 1);
}