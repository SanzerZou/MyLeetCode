#include "mainheader.h"
#include <string>

/*
	题目：zigzag型输出字符串，考察要点为字符串处理
	学习到的知识：
		1.边界条件的考虑，如numRows > s.size();numRows == 1的时候
		2.需要判断两次都出边界才能算透出循环，如第 27 句
		3.在string后面添加字符或者字符串直接使用 += 
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