
#include "common.h"

// ???????????????

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		map<int, int> pos_inorder;
		for (int i=0; i<inorder.size(); ++i){
			pos_inorder[inorder[i]] = i;
		}
		return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, pos_inorder);
	}

	TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr, map<int, int>& pos_inorder){
		if (pl > pr){
			return nullptr;
		}
		auto root = new TreeNode(postorder[pr]);
		
		auto pos = pos_inorder[postorder[pr]]-il;
		cout << pl  << "   " << pr << "  "<< il << "  "<< ir << "  "<< pos << endl;
		
		root->left = dfs(inorder,postorder,il, il+pos-1, pl, pl+pos-1, pos_inorder);
		root->right = dfs(inorder,postorder,il+pos+1, ir, pl+pos, pr-1, pos_inorder);
		return root;
	}

	void test(){
		vector<int> i = {9,3,15,20,7};
		vector<int> p = {9,15,7,20,3};
		auto t = buildTree(i, p);
		p_tree(t);
	}
};
