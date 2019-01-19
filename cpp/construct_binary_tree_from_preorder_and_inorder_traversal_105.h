
#include "common.h"

class Solution{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		map<int, int> pos_to_inorder;
		for (int i = 0 ; i < inorder.size(); ++i){
			pos_to_inorder[inorder[i]] =i;
		}
		int n = preorder.size();
		return dfs(preorder, inorder, 0, n-1, 0, n-1, pos_to_inorder);
	}

	TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir, map<int, int>& pos){
		if (pl > pr){
			return nullptr;
		}

		auto root = new TreeNode(preorder[pl]);
		int pos_inoder = pos[preorder[pl]] - il;
		cout << pl  << "   " << pr << "  "<< il << "  "<< ir << "  "<< pos_inoder << endl;		
		root->left = dfs(preorder, inorder, pl+1, pl+pos_inoder, il, il+pos_inoder-1, pos);
		root->right = dfs(preorder, inorder, pl+pos_inoder+1, pr, il+pos_inoder+1, ir, pos);
		return root;
	}
	
	/*
    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i ++ )
            pos[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* dfs(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return NULL;
        int k = pos[pre[pl]] - il;
        TreeNode* root = new TreeNode(pre[pl]);
        root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
        root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
	*/
	void test(){
		vector<int> p= {3,9,20,15,7};
		vector<int> i = {9,3,15,20,7};
		auto t = buildTree(p, i);
		p_tree(t);
	}

};
