#include "mainheader.h"
#include <cmath>

/*
	思路：此题目还是回文题目。与回文字符串解法一样，回文的一个重要特性就是关于中心对称性
	思考是否需要考虑分奇偶位考虑问题。

	题目要求：不能使用额外的空间

	提示：负数肯定不是回文数字，一位数肯定是回文数字。
	
	回文的判定重要的是定位，字符串定位使用的是下标，而int类型的定位及10^n

*/
bool isPalindrome(int x) {
	//先求出x的位数
	int bt = 0;
	if (x < 0)
	{
		return false;
	}
	int tx = x;
	while (tx /= 10){
		bt++;
	}
	//
	int i = 0, j = bt, lh, rh;
	lh = x / (int)pow(10,i) % 10;
	rh = x / (int)pow(10,j) % 10;
	while (lh == rh){
		if (i >= j)
		{
			return true;
		}
		i++;
		j--;
		lh = x / (int)pow(10,i) % 10;
		rh = x / (int)pow(10,j) % 10;
	}
	return false;
}