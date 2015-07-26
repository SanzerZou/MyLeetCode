#include "mainheader.h"
#include <cstdint>
int hammingWeight(uint32_t n) {
	int T = 32;
	int cnt = 0;
	while (T--){
		if (n & 1)
			cnt++;
		n = n >> 1;
	}
	return cnt;
}
//int main(){
//	uint32_t u = 8;
//	int res = hammingWeight(u);
//	return 0;
//}