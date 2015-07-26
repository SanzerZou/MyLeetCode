#include "mainheader.h"
#include <vector>
int mN;
int mK;
vector<vector<int>> res;
void pushVector(vector<int> v, int k){
	if (k == mK - 1){
		for (size_t i = v[k-1] + 1; i <= mN; i++)
		{
			v[k] = i;
			res.push_back(v);
		}
	}
	else if (k == 0){
		for (size_t i = v[k]; i <= mN-mK+1; i++)
		{
			v[k] = i;
			pushVector(v, k + 1);
		}
	}
	else{
		for (int i = v[k-1] + 1; i <= mN - mK + 1 + k; i++){
			v[k] = i;
			pushVector(v, k + 1);
		}
	}
}

vector<vector<int> > combine(int n, int k) {
	vector<int> nums;
	mN = n;
	mK = k;
	//初始化向量	
	for (int i = 0; i < k; i++){
		nums.push_back(i + 1);
	}
	pushVector(nums, 0);
	return res;
}

/*
	测试代码
*/

//int main()
//{
//	vector<vector<int>> vout;
//	vout = combine(8,4);
//	return 0;
//}