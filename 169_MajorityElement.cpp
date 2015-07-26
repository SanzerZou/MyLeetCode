#include "mainheader.h"
/*
	用一个计数器，可以增减，是则加，否则减，由于存在的元素为一半以上，所以最后记录的数肯定是major；
*/
int majorityElement(vector<int>& nums) {
	int cnt = 1;
	int major = nums[0];
	for (int i = 1; i < nums.size(); i++){
		if (cnt == 0){
			major = nums[i];
			cnt = 1;
		}
		else if (major == nums[i]){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	return major;
}