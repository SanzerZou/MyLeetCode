#include "mainheader.h"
/*
	经典：
	特别注意：求组和数的相乘而不是相加
	本题同样可以使用递归法，对于树来说根结点非常重要
*/
int numTrees(int n) {
	vector<int> res(n + 1, 0);
	res[0] = 1;
	res[1] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= i; j++){
			res[i] += res[j - 1] * res[i - j];
		}
	}
	return res[n];
}