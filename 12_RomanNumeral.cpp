#include "mainheader.h"
/*
	�ַ���������int����ת��Ϊroman���֣�Ҳ�����ҹ��ɵ�
*/
string intToRoman(int num) {
	int in[4] = {0};
	string so;
	const char one[4] = {'M', 'C', 'X', 'I' };
	const char five[3] = { 'D', 'L', 'V' };
	// ����������ת��Ϊ����
	for (int i = 3,tp = num; i >= 0; i--){
		in[i] = tp % 10;
		tp /= 10;
	}
	// ����ǧλ��
	while (in[0]--)
	{
		so += one[0];
	}
	// �����λ,ʮλ����λ
	for (int i = 1; i < 4; i++){
		if (in[i] == 9){
			so += one[i];
			so += one[i - 1];
		}
		else if (in[i] >= 5){
			int j = in[i] - 5;
			so += five[i - 1];
			while (j--){
				so += one[i];
			}
		}
		else if (in[i] == 4){
			so += one[i];
			so += five[i - 1];
		}
		else{
			int j = in[i];
			while (j--){
				so += one[i];
			}
		}
	}
	return so;
}