#include "mainheader.h"
#include <vector>
/*
	�������ܣ��������int��ת�������Ҫ���������������Ĵ���
	���������
		1.�����ŵĴ���
		2.�洦��������������ʹ��һ��long long���ݽṹ��ʱ��������������Χ��return 0��
*/

int reverse(int x) {
	bool plus = true;
	int ax; //������
	long long ox = 0;
	//�ж�������
	if (x >= 0)
	{
		ax = x;
		plus = true;
	}
	else{
		ax = -x;
		plus = false;
	}
	vector<int> vx;
	//��ĩβ����vector
	vx.push_back(ax % 10);
	while (ax /= 10){
		vx.push_back(ax % 10);
	}
	//��vector�������
	vector<int>::reverse_iterator it = vx.rbegin();
	for (long long sc = 1; it < vx.rend(); it++){
		ox += (long long)((*it) * sc);
		sc *= 10;
	}
	//�ж��Ƚ�oxת��Ϊ����
	ox = (plus == true) ? ox : (-ox);
	//�Ƿ񳬳� int �ı߽磬���������Ϊ��
	if (ox > INT_MAX || ox < INT_MIN){
		return 0;
	}
	else{
		return (int)ox;
	}
}
/*************
	��������
*************/
//int main(){
//	int x = 1000000003;
//	int res = reverse(x);
//	return 0;
//}