#include "mainheader.h"
/*
	math:经典题目
	1.将string进行反转，将会简洁许多
	2.下标永远比迭代器容易操作而且易于理解，所以在除输出时尽量使用下标来操作。
	3.两个数相乘最多超过位数和再加一位数
	4.vector<int> 的初始化表达式
	5.使用vector来存放数值，然后再将结果转化为string
	6.欣赏核心代码
	7.做math题目时记得将结果前面的零清空，不输出。
	8.下标i 和 j 表示位数。
*/
string multiply(string num1, string num2) {
	int n1 = num1.size();
	int n2 = num2.size();
	// 将字符串反转更加容易算
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	// 用vector存放数计算时更加方便，长度不会超过 (n1 + n2);
	vector<int> pos(n1 + n2, 0);
	// 用string存放输出结果
	string res = "";
	for (int i = 0; i < n1; i++){
		for (int j = 0; j < n2; j++){
			// 核心语句：先将数值暂存，后面两句表示转存，节省变量空间。
			pos[i + j] += (num1[i] - '0')*(num2[j] - '0');
			pos[i + j + 1] += pos[i + j] / 10;
			pos[i + j] %= 10;
		}
	}
	// 消除前面连续的 ‘0’
	int k = n1 + n2 - 1;
	while (pos[k] == 0 && k > 0)
		k--;
	for (; k >= 0; k--){
		res += to_string(pos[k]);
	}
	return res;
}