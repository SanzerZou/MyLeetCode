#include "mainheader.h"
#include <cstdint>

uint32_t reverseBits(uint32_t n) {
	uint32_t a = 0x80000000;
	uint32_t b = 1;
	uint32_t res = 0;
	int T = 32;
	while (T--){
		if (n & b)
			res |= a;
		b = b << 1;
		a = a >> 1;
	}
	return res;
}
//int main(){
//	uint32_t tp = 0x80700000;
//	uint32_t res = reverseBits(tp);
//	return 0;
//}