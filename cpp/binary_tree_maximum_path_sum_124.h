

#include "common.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_num = INT_MIN;
		dfs(root, max_num);
		return max_num;
    }

	int dfs(TreeNode* root, int& max_num){
		if (!root){
			return 0;
		}
		auto l = max(0, dfs(root->left, max_num));
		auto r = max(0, dfs(root->right, max_num));
		auto m = max(root->val, root->val + l + r);
		max_num = max(m, max_num);
		return m;
	}
};
