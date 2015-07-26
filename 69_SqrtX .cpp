#include "mainheader.h"

int mySqrt(int x) {
	if (x == 1 || x == 0){
		return x;
	}
	int left = 1;
	int right = x;
	int mid;
	while (left <= right){
		mid = (right + left) / 2;
		// ���ַ������������ˣ������Ͳ���������������
		if (mid > x/mid){
			right = mid - 1;
		}
		else{
			// ֻ������ mid*mid<= x <(mid+1)*(mid+1)���ͷ���
			if ((mid + 1) > x / (mid + 1))
				return mid;
			left = mid + 1;
		}
	}
}

//int main(){
//	int res = mySqrt(4);
//	return 0;
//}