#include "mainheader.h"
/*
	我的方法：用意个变量记住上一次的方向，即不能重复上一次的方向，这种方法只记录了上一的方向，而没有记录所有的路径，所以导致错误，应该是
	走一路就记录一步。

	别人的方法：
		1.使用return bool，使用 ‘||’运算符表示其中一个条件满足时，即四个方向有一个方向满足条件即可。
		2.记录走过的路径，使用 ‘*’ 特殊字符替代。
*/
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int dp){
	if (dp == word.size())
		return true;
	// 边界条件，是否越界，学会使用逻辑关系式
	if (i < 0 || i == board.size() || j == board[0].size() || j < 0)
		return false;
	// 没有越界才能取值；不等于直接返回
	else if (board[i][j] != word[dp])
		return false;
	// 记录已经访问过的点
	board[i][j] = '*';
	// dfs遍历周围四个点
	bool exist = dfs(board, word, i - 1, j, dp + 1) || dfs(board, word, i + 1, j, dp + 1)
		|| dfs(board, word, i, j - 1, dp + 1) || dfs(board, word, i, j + 1, dp + 1);
	// 恢复原值
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