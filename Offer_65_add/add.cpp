class Solution {
public:
	int add(int a, int b) {
		while (b != 0) { // ����λΪ 0 ʱ����
			//C++�и�����֧������λ
			int c = (unsigned int)(a & b) << 1;  // c = ��λ 
			a ^= b; // a = �ǽ�λ��
			b = c; // b = ��λ
		}
		return a;
	}
};
int main()
{
	Solution sol;
	sol.add(5, 17);
}
