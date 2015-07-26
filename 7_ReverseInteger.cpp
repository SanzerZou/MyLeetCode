#include "mainheader.h"
#include <vector>
/*
	函数功能：将输入的int反转输出，主要考察的是特例情况的处理
	特例情况：
		1.正负号的处理
		2.益处处理，处理方法就是使用一个long long数据结构临时保存结果，超出范围则return 0；
*/

int reverse(int x) {
	bool plus = true;
	int ax; //正负号
	long long ox = 0;
	//判断正负数
	if (x >= 0)
	{
		ax = x;
		plus = true;
	}
	else{
		ax = -x;
		plus = false;
	}
	vector<int> vx;
	//将末尾加入vector
	vx.push_back(ax % 10);
	while (ax /= 10){
		vx.push_back(ax % 10);
	}
	//将vector反向输出
	vector<int>::reverse_iterator it = vx.rbegin();
	for (long long sc = 1; it < vx.rend(); it++){
		ox += (long long)((*it) * sc);
		sc *= 10;
	}
	//判断先将ox转化为正负
	ox = (plus == true) ? ox : (-ox);
	//是否超出 int 的边界，如果超出则为零
	if (ox > INT_MAX || ox < INT_MIN){
		return 0;
	}
	else{
		return (int)ox;
	}
}
/*************
	测试用例
*************/
//int main(){
//	int x = 1000000003;
//	int res = reverse(x);
//	return 0;
//}