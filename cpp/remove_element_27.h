
#include "common.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int cur = 0;
	   for (int i=0; i< nums.size(); ++i){
			if (val != nums[i]){
				nums[cur++] = nums[i];
			}
	   }
	   return cur;
    }
};
