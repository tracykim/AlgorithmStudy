#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		if (head == nullptr)
			return res;
		print(head);
		return res;
	}
private:
	vector<int> res;
	void print(ListNode* head) {
		if (head->next != nullptr) {
			print(head->next);
		}
		res.push_back(head->val);
	}
};
int main()
{

}