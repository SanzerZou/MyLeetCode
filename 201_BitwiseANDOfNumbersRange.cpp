#include "mainheader.h"
/*
	注意异或符 ‘^’
*/
int rangeBitwiseAnd(int m, int n) {
	int cnt = 0;
	while (m ^ n){
		cnt++;
		m = m >> 1;
		n = n >> 1;
	}
	// 需要移多少位，直接移位就行
	return m << cnt;
}
//int main(){
//	int res = rangeBitwiseAnd(5, 7);
//	return 0;
//}