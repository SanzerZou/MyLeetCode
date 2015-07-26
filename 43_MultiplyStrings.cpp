#include "mainheader.h"
/*
	math:������Ŀ
	1.��string���з�ת�����������
	2.�±���Զ�ȵ��������ײ�������������⣬�����ڳ����ʱ����ʹ���±���������
	3.�����������೬��λ�����ټ�һλ��
	4.vector<int> �ĳ�ʼ�����ʽ
	5.ʹ��vector�������ֵ��Ȼ���ٽ����ת��Ϊstring
	6.���ͺ��Ĵ���
	7.��math��Ŀʱ�ǵý����ǰ�������գ��������
	8.�±�i �� j ��ʾλ����
*/
string multiply(string num1, string num2) {
	int n1 = num1.size();
	int n2 = num2.size();
	// ���ַ�����ת����������
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	// ��vector���������ʱ���ӷ��㣬���Ȳ��ᳬ�� (n1 + n2);
	vector<int> pos(n1 + n2, 0);
	// ��string���������
	string res = "";
	for (int i = 0; i < n1; i++){
		for (int j = 0; j < n2; j++){
			// ������䣺�Ƚ���ֵ�ݴ棬���������ʾת�棬��ʡ�����ռ䡣
			pos[i + j] += (num1[i] - '0')*(num2[j] - '0');
			pos[i + j + 1] += pos[i + j] / 10;
			pos[i + j] %= 10;
		}
	}
	// ����ǰ�������� ��0��
	int k = n1 + n2 - 1;
	while (pos[k] == 0 && k > 0)
		k--;
	for (; k >= 0; k--){
		res += to_string(pos[k]);
	}
	return res;
}