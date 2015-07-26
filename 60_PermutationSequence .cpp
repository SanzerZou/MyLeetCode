#include "mainheader.h"
#include <algorithm>
/*
	第一种解法：dfs backtracking法，直到查到第k个数为止，这种方法可以作为练习backtracking的方法，但是
	复杂度较高，需要计算出k个数之前的所有组合，而这些都是不需要的
*/

//void dfs(vector<bool> flg,vector<int>& nums,
//	int index,int &count,bool &bk,const int n,const int k){
//	if (index == n){
//		count++;
//		if (count == k){
//			bk = true;
//			return;
//		}
//	}
//	else{
//		for (int i = 0; i < n; i++){
//			if (flg[i] == false){
//				flg[i] = true;
//				nums[index] = i + 1;
//				dfs(flg, nums, index + 1, count, bk, n, k);
//				if (bk) return;
//				flg[i] = false;
//			}
//		}
//	}
//}
/*
	方法二：将组合理解为进制，某一位以下有多少种排列组合，则前一位是多少。
*/
int factorial(int n, vector<int> &mv,int index){
	if (n == 0){
		return 1;
	}
	else{
		return mv[index] = n*factorial(n - 1, mv, index + 1);
	}
}
string getPermutation(int n, int k) {
	vector<char> tp(n,0); //存放当前排第几的字符，记得每次循环删除一个
	vector<char> nums(n, 0); //存放输出结果的vector
	vector<int> fac(n - 1, 0); //存放阶乘除数
	string res;
	// 字符串初始化，‘1’~‘9’
	for (int i = 0; i < n; i++){
		tp[i] = (char)(i + '1');
	}
	// 求阶乘数
	factorial(n - 1, fac, 0);
	k--; // 注意减去一，因为计数不是从零开始的
	// 每次添加一位
	for (int i = 0; i < n - 1; i++){
		int index = k / fac[i];
		nums[i] = tp[index];
		tp.erase(tp.begin() + index);
		k -= index * fac[i];
	}
	nums[n - 1] = tp[0];
	for (int i = 0; i < n; i++){
		res += nums[i];
	}
	return res;
}

//int main(){
//	string res = getPermutation(1, 1);
//	return 0;
//}