#include "mainheader.h"

int trailingZeroes(int n) {
	int cnt = 0;
	while (n){
		n /= 5;
		cnt += n;
	}
	return cnt;
}
//int main(){
//	int res = trailingZeroes(100);
//	return 0;
//}