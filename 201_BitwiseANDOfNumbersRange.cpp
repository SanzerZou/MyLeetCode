#include "mainheader.h"
/*
	ע������ ��^��
*/
int rangeBitwiseAnd(int m, int n) {
	int cnt = 0;
	while (m ^ n){
		cnt++;
		m = m >> 1;
		n = n >> 1;
	}
	// ��Ҫ�ƶ���λ��ֱ����λ����
	return m << cnt;
}
//int main(){
//	int res = rangeBitwiseAnd(5, 7);
//	return 0;
//}