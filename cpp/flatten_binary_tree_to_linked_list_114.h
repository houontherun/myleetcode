
#include "common.h"

class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root){
			return;
		}
		if (root->left){
			flatten(root->left);
		}
		if (root->right){
			flatten(root->right);
		}
		auto right = root->right;
		root->right = root->left;
		root->left = nullptr;
		//cout << root->left << endl;
		auto tmp = root;
		while(tmp->right){
			tmp = tmp->right;
		}
		tmp->right = right;
	}

	void test(){
		auto r = g_tree({1,2,5,3,4,0,6});
		p_tree(r);
		flatten(r);
		p_tree(r);
	}
};


