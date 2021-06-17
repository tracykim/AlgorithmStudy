#include <list>
using namespace std;
class Solution {
public:
	// ���� ��ʱ
	int lastRemaining(int n, int m) {
		Node* root = new Node(0), *a, *pre, *after;
		Node* p = root;
		for (int i = 1; i < n; i++)
		{
			a = new Node(i);
			p->next = a;
			p = a;
		}
		pre = p; // ǰ���ڵ���ָ��β���
		p->next = root; // �γɻ�
		p = root;

		// ��ʼɾ��
		int count;
		while (p->next != p) { // p�������һ���ڵ�
			count = m-1;
			while (count--) {
				pre = p;
				p = p->next;
			}
			after = p->next;
			delete p;
			p = nullptr;
			pre->next = after;
			p = after;
		}
		return p->val;
	}

	// ʹ��std::list ��ʱ
	int LastRemaining_Solution1(unsigned int n, unsigned int m)
	{
		if (n < 1 || m < 1)
			return -1;

		unsigned int i = 0;

		list<int> numbers;
		for (i = 0; i < n; ++i)
			numbers.push_back(i);

		list<int>::iterator current = numbers.begin();
		while (numbers.size() > 1)
		{
			for (int i = 1; i < m; ++i)
			{
				current++;
				if (current == numbers.end())
					current = numbers.begin();
			}

			list<int>::iterator next = ++current;
			if (next == numbers.end())
				next = numbers.begin();

			--current;
			numbers.erase(current);
			current = next;
		}

		return *(current);
	}
private:
	struct Node {
		int val;
		Node* next;
		Node(int x) {
			val = x;
		}
	};
};

int main()
{
	Solution sol;
	sol.lastRemaining(5, 3);
}