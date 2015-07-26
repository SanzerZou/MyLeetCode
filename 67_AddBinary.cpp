#include "mainheader.h"
#include <algorithm>
#include <cmath>
/*
	难点
	1.如何处理反相问题。 我的方式：使用reverse 其他方法：使用一个变量递减
	2.如何处理两字符串不一样长的问题 我的方法：在短字符串后面补零 其他方法：在循环中判断下标，如果小于零则加零，不再递减
*/
string addBinary(string a, string b) {
	if (a.empty() || b.empty()){
		return (a.empty()) ? b : a;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string &c = (a.size() > b.size()) ? b : a;
	c.append(abs(int(a.size() - b.size())), '0');
	int T = c.size();
	int carry = 0;
	vector<int> mv;
	for (int i = 0; i < T; i++){
		int sum = a[i] + b[i] - 2 * '0' + carry;
		mv.push_back(sum % 2);
		carry = sum / 2;
	}
	if (carry)
		mv.push_back(carry);
	string res;
	for (int i = mv.size() - 1; i >= 0; i--){
		res += to_string(mv[i]);
	}
	return res;
}

/* 超级简洁方法
string addBinary(string a, string b)
{
	string s = "";

	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while(i >= 0 || j >= 0 || c == 1)
	{
		// c 也可以用来短暂的计算，节省空间
		c += i >= 0 ? a[i --] - '0' : 0;
		c += j >= 0 ? b[j --] - '0' : 0;
		s = char(c % 2 + '0') + s;
		c /= 2;
	}

	return s;
}
*/

//int main(){
//	string a = "1";
//	string b = "1";
//	string res = addBinary(a, b);
//	return 0;
//}