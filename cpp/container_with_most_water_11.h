// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// 
// Note: You may not slant the container and n is at least 2.
//

#include "common.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
      int i = 0;
      int j = height.size();
      int s = min(height[i], height[j])*(j-i);
      while(i < j){
        if (height[i]<height[j]) {
            ++i;
        }
        else {
          --j;
        }
        s = max(s, min(height[i], height[j])*(j-i));
      }
      return s;
    };

    void test(){
      //vector<int> a({1,8,6,2,5,4,8,3,7});
      vector<int> a({1,2});
      cout << maxArea(a) << endl;
    }
};
