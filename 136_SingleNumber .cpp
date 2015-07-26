#include "mainheader.h"
#include <unordered_map>
/*
	我的思考：
		1.使用排序，然后计算个数。复杂度为 O(Nlog(N));
		2.因为是查找，所以使用unordered_map，存在则改变一次状态。使用iterator来遍历，it->first:表示第一个元素，it->second:表示第二个元素
		3.unordered_map的iterator不能使用“<” , 而只能使用 “!=”
	总之，我的方法计算复杂度有点高。
*/
int singleNumber(vector<int>& nums) {
	int T = nums.size();
	unordered_map<int,bool> mp;
	for (int i = 0; i < T; i++){
		if (mp.count(nums[i])){
			mp.insert({ nums[i], false });
		}
		else{
			mp[nums[i]] = !mp[nums[i]];
		}
	}
	unordered_map<int, bool>::iterator it = mp.begin();
	for (; it != mp.end(); it++){
		if (!(it->second))
			return it->first;
	}
}
/*
	￥超级巧妙方法：
		使用XOR方法，原理((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5
		本身 XOR 本身 = 0；
		0 XOR 本身 = 本身；
		FF XOR 本身 = ！本身；
*/
int singleNumber2(int A[], int n) {
	int result = 0;
	for (int i = 0; i<n; i++)
	{
		result ^= A[i];
	}
	return result;
}

//int main(){
//	vector<int> inv(1, 1);
//	int res = singleNumber(inv);
//	return 0;
//}