#include "mainheader.h"
#include <unordered_set>
bool isHappy(int n) {
	int happy = n;
	vector<int> mv;
	unordered_set<int> ms;
	while (happy != 1)
	{
		if (ms.count(happy))
			return false;
		else
			ms.insert(happy);
				
		int tp = happy;
		happy = 0;
		while (tp){
			mv.push_back(tp % 10);
			tp /= 10;
		}
		for (auto x : mv){
			happy += x * x;
		}
		mv.clear();
	}
	return true;
}
//int main(){
//	bool res = isHappy(15);
//	return 0;
//}