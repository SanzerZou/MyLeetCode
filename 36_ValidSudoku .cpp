#include "mainheader.h"
/*
	��Ϊ�����������У��У��ӿ顣��ֻ����Ψһ�ġ�0��~��9���������ǲ������⡣
	���Կ�����������ʾ����Ϊ�б����У��У��ӿ飬�Լ���ŵ������ĸ����������Կ��������������Լ��±�������Ƿ��Ѿ����ֹ�������֡�
	˼���Ƿ���ʹ��hash��
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