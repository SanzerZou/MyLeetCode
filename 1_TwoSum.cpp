#include "mainheader.h"
#include <unordered_map>

void init(unordered_map<int, int> & h, vector<int> & v){
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		h.insert(pair<int, int>(v[i], i + 1));
	}
}
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	unordered_map<int, int> mp;
	init(mp, nums);
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (mp.count(target - nums[i]) && mp[target - nums[i]] != (i + 1)){
			if (i + 1 > mp[target - nums[i]]){
				res.push_back(mp[target - nums[i]]);
				res.push_back(i + 1);
			}
			else{
				res.push_back(i + 1);
				res.push_back(mp[target - nums[i]]);
			}
			return res;
		}
	}
}