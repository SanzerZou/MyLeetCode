#include "mainheader.h"
/*
	逆序计算，从后往前计算就不会覆盖掉前面的值
*/
vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i <= rowIndex; i++){
		for (int j = i; j > 0; j--){
			res[j] += res[j - 1];
		}
	}
	return res;
}
//int main(){
//	vector<int> res = getRow(4);
//	return 0;
//}