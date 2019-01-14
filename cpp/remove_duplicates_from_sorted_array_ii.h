
#include "common.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size()<=2){
			return nums.size();
		}
		int pre = 0, cur = 1, count = 0;
		while (cur < nums.size()){
			if (nums[pre] == nums[cur] && count == 1){
				++cur;
			}
			else {
				if(nums[pre] == nums[cur]){
					count += 1;
				}
				else {
					count = 0;
				}
				nums[++pre] = nums[cur++];
			}
		}
		return pre+1;
	}

	void test() {
		vector<int> a ({1,1,1,2,2,3});
		auto l = removeDuplicates(a);
		for (auto i = 0; i < l; ++i){
			cout << a[i] << endl;
		}
	}

};

