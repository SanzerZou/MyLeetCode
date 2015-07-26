#include "mainheader.h"
/*
	字符串处理，将int整数转化为roman数字，也就是找规律的
*/
string intToRoman(int num) {
	int in[4] = {0};
	string so;
	const char one[4] = {'M', 'C', 'X', 'I' };
	const char five[3] = { 'D', 'L', 'V' };
	// 将输入数字转化为数组
	for (int i = 3,tp = num; i >= 0; i--){
		in[i] = tp % 10;
		tp /= 10;
	}
	// 处理千位数
	while (in[0]--)
	{
		so += one[0];
	}
	// 处理百位,十位，个位
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