/**
 * ����0-1��������
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int NN = 6;
const int CC = 12;
int main() {

	int N = 6;
	int C = 12;

	int v[NN + 1] = { 0,8,10,6,3,7,2 };
	int w[CC + 1] = { 0,4,6,2,2,5,1 };


	int val[NN + 1][CC + 1];//��ֵ���� 

	//��Ե�0����Ʒ�����۱�����С�Ƕ��٣�����ȡ�õ�����ֵ��Ϊ0 
	for (int j = 0; j < C + 1; j++) val[0][j] = 0;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= C; j++) {
			//�����ǰ��������jС�ڵ�ǰ��Ʒi����������װi��Ʒ 
			if (j < w[i]) val[i][j] = val[i - 1][j];

			//�����ǰ�����������ڵ��ڵ�ǰ��Ʒi����������ѡ��װ����װ���нϴ��ֵ 
			else val[i][j] = max(val[i - 1][j - w[i]] + v[i], val[i - 1][j]);
		}
	}
	cout << val[N][C] << endl;


	//�Ӹߵ��ͣ�����ж��Ƿ�װ���˱�����
	//�жϷ����������ǰһ���Ƚϣ�����ֵ��ȣ�˵������Ʒδװ����� 
	int b[NN + 1];
	for (int i = N; i >= 1; i--) {
		if (val[i][C] == val[i - 1][C]) b[i] = 0;
		else {
			b[i] = 1;
			cout << i << ' ';
			C = C - w[i];
		}
	}

	return 0;
}