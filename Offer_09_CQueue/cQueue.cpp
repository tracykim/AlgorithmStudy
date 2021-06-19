#include <stack>
using namespace std;
class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {		
		stk1.emplace(value);		
	}

	int deleteHead() {		
		if (stk2.empty()) { // 第二个栈为空
			while (!stk1.empty())
			{
				stk2.emplace(stk1.top());
				stk1.pop();
			}
		}
		if (stk2.empty())
			return -1;
		else {
			int x = stk2.top();
			stk2.pop();
			return x;
		}
		
	}
private:
	stack<int> stk1;
	stack<int> stk2;
};

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/
int main()
{

}