#include "mainheader.h"
/*
	�ҵķ����������������ס��һ�εķ��򣬼������ظ���һ�εķ������ַ���ֻ��¼����һ�ķ��򣬶�û�м�¼���е�·�������Ե��´���Ӧ����
	��һ·�ͼ�¼һ����

	���˵ķ�����
		1.ʹ��return bool��ʹ�� ��||���������ʾ����һ����������ʱ�����ĸ�������һ�����������������ɡ�
		2.��¼�߹���·����ʹ�� ��*�� �����ַ������
*/
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int dp){
	if (dp == word.size())
		return true;
	// �߽��������Ƿ�Խ�磬ѧ��ʹ���߼���ϵʽ
	if (i < 0 || i == board.size() || j == board[0].size() || j < 0)
		return false;
	// û��Խ�����ȡֵ��������ֱ�ӷ���
	else if (board[i][j] != word[dp])
		return false;
	// ��¼�Ѿ����ʹ��ĵ�
	board[i][j] = '*';
	// dfs������Χ�ĸ���
	bool exist = dfs(board, word, i - 1, j, dp + 1) || dfs(board, word, i + 1, j, dp + 1)
		|| dfs(board, word, i, j - 1, dp + 1) || dfs(board, word, i, j + 1, dp + 1);
	// �ָ�ԭֵ
	board[i][j] = word[dp];
	return exist;
}
bool exist(vector<vector<char>>& board, string word) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (board[i][j] == word[0])
				if( dfs(board, word, i, j, 0)) return true;
		}
	}
	return false;
}

//int main(){
//	vector<vector<char>> inv = { { 'a' } };
//	bool res = exist(inv, "ab");
//	return 0;
//}