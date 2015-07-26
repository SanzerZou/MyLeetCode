#include "mainheader.h"

vector<int> plusOne(vector<int>& digits) {
	int T = digits.size();
	int up = 1;
	for (int i = T - 1; i >= 0; i--){
		if (up){
			if (digits[i] + up != 10){
				digits[i]++;
				up = 0;
			}
			else{
				digits[i] = 0;
				up = 1;
			}
		}
		else
			break;
	}
	if (up){
		digits.insert(digits.begin(), 1, 1);
	}
	return digits;
}

//int main(){
//	vector<int> inv;
//	vector<int> res;
//	int ini[] = { 9, 9, 9, 9 };
//	inv.assign(ini,ini+sizeof(ini)/sizeof(int));
//	res = plusOne(inv);
//	return 0;
//}