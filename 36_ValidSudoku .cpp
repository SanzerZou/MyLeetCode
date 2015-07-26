#include "mainheader.h"
/*
	因为有三个规则：行，列，子块。都只存在唯一的‘0’~‘9’，本质是查找问题。
	所以可以用数组表表示，因为有变量行，列，子块，以及存放的数字四个变量，所以可以用三个数组以及下标来存放是否已经出现过这个数字。
	思考是否能使用hash表
*/
bool isValidSudoku(vector<vector<char>>& board) {
	bool row[9][9] = { false };
	bool rank[9][9] = { false };
	bool sub[9][9] = { false };
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (board[i][j] == '.')
				continue;
			else{
				int num = board[i][j] - '0' - 1;
				int k = 3 * (i / 3) + j / 3;
				if (row[i][num] || rank[j][num] || sub[k][num])
					return false;
				else{
					row[i][num] = true;
					rank[j][num] = true;
					sub[k][num] = true;
				}
			}
		}
	}
	return true;
}