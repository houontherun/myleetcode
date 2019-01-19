

#include "common.h"

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		vector<int> all;
		dfs(root, 0, all);
		for (auto v:all){
			cout << v << endl;
		}
		return accumulate(all.begin(), all.end(), 0);
	}

	void dfs(TreeNode* root, int path, vector<int>& all){
		if (root== nullptr){
			return;
		} 
		path = path * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr) {
			all.push_back(path);
		}

		if (root->left){
			dfs(root->left, path, all);
		}

		if (root->right){
			dfs(root->right, path, all);
		}
	}

	void test(){
		auto t = g_tree({1,2,3});
		cout << sumNumbers(t) << endl;		
	}

};
