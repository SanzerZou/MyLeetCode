#include "mainheader.h"
#include <map>
/*
	��Ҫ��˼�룺
		1.ʹ��mapӳ��char��int��ʹ����ԱȽ����ж��Ƿ�������
		2.ʹ��mapӳ��char��int��ʹ�����һ����ֵ
*/
int romanToInt(string s) {
	const char code[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	// ʹ��ĸ���ԱȽ�
	map<char, int> mpA;
	for (int i = 0; i < 7; i++){
		mpA[code[i]] = i + 1;
	}
	// ����ĸӳ�䵽��ֵ
	map<char, int> mpValue;
	mpValue[code[0]] = 1;
	mpValue[code[1]] = 5;
	mpValue[code[2]] = 10;
	mpValue[code[3]] = 50;
	mpValue[code[4]] = 100;
	mpValue[code[5]] = 500;
	mpValue[code[6]] = 1000;
	// �����ַ���
	int n = s.size();
	int io = 0;
	for (int i = 0; i < n;){
		if (i == n - 1){
			io += mpValue[s[i]];
			i++;
		}
		else{
			if (mpA[s[i]] < mpA[s[i + 1]]){
				io += mpValue[s[i + 1]] - mpValue[s[i]];
				i++;
				i++;
			}
			else{
				io += mpValue[s[i]];
				i++;
			}
		}
	}
	return io;
}