#include "mainheader.h"

int climbStairs(int n) {
	int one = 1;
	int two = 2;
	int res;
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	for (int i = 2; i < n; i++){
		res = one + two;
		one = two;
		two = res;
	}
	return res;
}