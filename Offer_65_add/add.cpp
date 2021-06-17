class Solution {
public:
	int add(int a, int b) {
		while (b != 0) { // 当进位为 0 时跳出
			//C++中负数不支持左移位
			int c = (unsigned int)(a & b) << 1;  // c = 进位 
			a ^= b; // a = 非进位和
			b = c; // b = 进位
		}
		return a;
	}
};
int main()
{
	Solution sol;
	sol.add(5, 17);
}
