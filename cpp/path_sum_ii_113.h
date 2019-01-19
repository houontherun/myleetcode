

#include "common.h"
#include <numeric>


class Solution {
public:

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> all;

		dfs(root, sum, {}, 0, all);
		return all;

	}

	void dfs(TreeNode* root, int sum, vector<int> path, int left,  vector<vector<int>>& all){
		if (root== nullptr || (root->left == nullptr && root->right == nullptr)){
			if (accumulate(path.begin(), path.end(), 0) == sum){
				all.push_back(path);
			}
			return;
		}
		

		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr){
			if (accumulate(path.begin(), path.end(), 0) == sum){
				all.push_back(path);
			}
			return;
		}
		

		dfs(root->left, sum, path, 0, all);
		dfs(root->right, sum, path, 0, all);
	}

	void test(){
		auto t = g_tree({5,4,8,11,0,13,4,7,2,0,0,5,1});
	}
};
