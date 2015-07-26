#include "mainheader.h"
#include <algorithm>
#include <cmath>
/*
	�ѵ�
	1.��δ��������⡣ �ҵķ�ʽ��ʹ��reverse ����������ʹ��һ�������ݼ�
	2.��δ������ַ�����һ���������� �ҵķ������ڶ��ַ������油�� ������������ѭ�����ж��±꣬���С��������㣬���ٵݼ�
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

/* ������෽��
string addBinary(string a, string b)
{
	string s = "";

	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while(i >= 0 || j >= 0 || c == 1)
	{
		// c Ҳ�����������ݵļ��㣬��ʡ�ռ�
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