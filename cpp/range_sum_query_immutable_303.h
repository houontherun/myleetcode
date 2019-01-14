
#include "common.h"

class NumArray {
public:
	vector<int> dp;

    NumArray(vector<int> nums) {
		int s = 0;
		for (auto v:nums){
			s += v;
			dp.push_back(s);
		}
    }
    
    int sumRange(int i, int j) {
		if (i < j){
			return dp[j] - dp[i];
		}
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
