#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1){
			return nums.size();
		}

		int cur = 0;
		for (int i = 1; i < nums.size(); ++i){
			if (nums[cur] != nums[i]){
				nums[++cur] = nums[i];
			}
		}
        return cur + 1;
    }
};
