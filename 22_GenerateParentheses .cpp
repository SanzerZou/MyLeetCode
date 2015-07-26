#include "mainheader.h"
/*
	dfs:深度优先经典算法，回溯法的再一次运用。算法就是一次一次的优化。
	我的算法：
		先用回溯法求出所有可能，然后再判断每一种可能是否是满足要求的括号对
	优化算法:
		找出括号对的规律，并不需要遍历所有可能，求出来的字符串都是满足需求的括号对，没有的判断的过程。
	回溯法：
		记得多使用几个参数，然后使用‘&’来进行传递。形参也是可以变得，学会使用这个参数。
*/
void dfsGen(vector<string> &res,string out, int lh, int rh, int sum){
	if (!lh){
		string temp(rh, ')');
		res.push_back(out + temp);
		return;
	}
	dfsGen(res, out + '(', lh - 1, rh, sum + 1);
	if (sum > 0)
		dfsGen(res, out + ')', lh, rh - 1, sum - 1);
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	dfsGen(res,"", n, n, 0);
	return res;
}
/*
	测试代码：
*/
//int main(){
//	vector<string> tp = generateParenthesis(3);
//	return 0;
//}