#include "mainheader.h"
#include <cmath>

/*
	˼·������Ŀ���ǻ�����Ŀ��������ַ����ⷨһ�������ĵ�һ����Ҫ���Ծ��ǹ������ĶԳ���
	˼���Ƿ���Ҫ���Ƿ���żλ�������⡣

	��ĿҪ�󣺲���ʹ�ö���Ŀռ�

	��ʾ�������϶����ǻ������֣�һλ���϶��ǻ������֡�
	
	���ĵ��ж���Ҫ���Ƕ�λ���ַ�����λʹ�õ����±꣬��int���͵Ķ�λ��10^n

*/
bool isPalindrome(int x) {
	//�����x��λ��
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