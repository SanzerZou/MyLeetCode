#include "mainheader.h"
/*
	������㣬�Ӻ���ǰ����Ͳ��Ḳ�ǵ�ǰ���ֵ
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