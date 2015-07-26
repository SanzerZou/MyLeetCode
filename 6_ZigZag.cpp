#include "mainheader.h"
#include <string>

/*
	��Ŀ��zigzag������ַ���������Ҫ��Ϊ�ַ�������
	ѧϰ����֪ʶ��
		1.�߽������Ŀ��ǣ���numRows > s.size();numRows == 1��ʱ��
		2.��Ҫ�ж����ζ����߽������͸��ѭ������� 27 ��
		3.��string��������ַ������ַ���ֱ��ʹ�� += 
*/

string convert(string s, int numRows) {
	string r;
	int T = s.size();
	if (numRows >= T || numRows == 1){
		return s;
	}
	else{
		for (int i = 0; i < numRows; i++){
			if (i == 0 || i == numRows - 1){
				for (int j = i; j < T; j += 2 * (numRows - 1)){
					r += s[j];
				}
			}
			else{
				for (int j = i; j < T; j += 2 * i){
					r += s[j];
					j += (numRows - 1 - i) * 2;
					if (j < T){
						r += s[j];
					}
				}
			}
		}
		return r;
	}
}