/**
 * 经典0-1背包问题
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


	int val[NN + 1][CC + 1];//价值矩阵 

	//针对第0个物品，无论背包大小是多少，所能取得的最大价值均为0 
	for (int j = 0; j < C + 1; j++) val[0][j] = 0;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= C; j++) {
			//如果当前背包容量j小于当前物品i的重量，则不装i物品 
			if (j < w[i]) val[i][j] = val[i - 1][j];

			//如果当前背包容量大于等于当前物品i的重量，则选择装它或不装它中较大的值 
			else val[i][j] = max(val[i - 1][j - w[i]] + v[i], val[i - 1][j]);
		}
	}
	cout << val[N][C] << endl;


	//从高到低，逐个判断是否装在了背包中
	//判断方法：逐个与前一个比较，若价值相等，说明该物品未装入包中 
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