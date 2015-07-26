#include "mainheader.h"
#include <map>
/*
	主要的思想：
		1.使用map映射char到int，使其可以比较来判断是否是逆序
		2.使用map映射char到int，使其代表一定的值
*/
int romanToInt(string s) {
	const char code[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	// 使字母可以比较
	map<char, int> mpA;
	for (int i = 0; i < 7; i++){
		mpA[code[i]] = i + 1;
	}
	// 将字母映射到数值
	map<char, int> mpValue;
	mpValue[code[0]] = 1;
	mpValue[code[1]] = 5;
	mpValue[code[2]] = 10;
	mpValue[code[3]] = 50;
	mpValue[code[4]] = 100;
	mpValue[code[5]] = 500;
	mpValue[code[6]] = 1000;
	// 处理字符串
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