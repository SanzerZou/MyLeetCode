#include "mainheader.h"
bool isQueens(vector<int> mv){
	vector<bool> flg1(2 * mv.size(), false);
	vector<bool> flg2(2 * mv.size(), false);
	for (int i = 0; i < mv.size(); i++){
		if (!flg1[i + mv[i]] && !flg2[i - mv[i] + mv.size()]){
			flg1[i + mv[i]] = true;
			flg2[i - mv[i] + mv.size()] = true;
		}
		else{
			return false;
		}
	}
	return true;
}
void nQueens(vector<vector<string>>& res, vector<int>& mv, int div){
	if (div == mv.size()){
		if (isQueens(mv)){
			vector<string> tp(mv.size(), string(mv.size(), '.'));
			for (int i = 0; i < mv.size(); i++){
				tp[i][mv[i]] = 'Q';
			}
			res.push_back(tp);
		}
	}
	for (int i = div; i < mv.size(); i++){
		swap(mv[div], mv[i]);
		nQueens(res, mv, div + 1);
		swap(mv[div], mv[i]);
	}
}
vector<vector<string> > solveNQueens(int n) {
	vector<vector<string>> res;
	vector<int> mv;
	for (int i = 0; i < n; i++){
		mv.push_back(i);
	}
	nQueens(res, mv, 0);
	return res;
}

//int main(){
//	vector<vector<string>> res = solveNQueens(9);
//	return 0;
//}