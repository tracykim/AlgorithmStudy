#include <queue>
using namespace std;
class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		return deq.empty() ? -1 : deq.front();
	}

	void push_back(int value) {
		que.push(value);
		while (!deq.empty() && deq.back()<=value)
		{
			deq.pop_back();
		}
		deq.push_back(value);
	}

	int pop_front() {
		if (que.empty()) return -1;
		int front = que.front();
		que.pop();
		if (front == deq.front())
			deq.pop_front();
		return front;
	}
private:
	queue<int> que;
	deque<int> deq;
};

/**
* Your MaxQueue object will be instantiated and called as such:
* MaxQueue* obj = new MaxQueue();
* int param_1 = obj->max_value();
* obj->push_back(value);
* int param_3 = obj->pop_front();
*/
int main()
{

}