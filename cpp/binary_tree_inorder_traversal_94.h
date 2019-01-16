


#include "common.h"


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		if (root == nullptr){i
			return {};
		}       
		vector<int> path;
		dfs(root, path);
		return path;
    }

	void dfs(TreeNode* root, vector<int>& path){
		if (root == nullptr){
			return;
		}
		path.emplace_back(root->val);
		dfs(root->left, path);
		dfs(root->right, path);
	}


	void test(){
	}
};
