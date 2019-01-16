

#include "common.h"

// BFS

class Solution{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> all;
		if (!root) {
			return all;
		}
	
		vector<TreeNode*> q;
		q.push_back(root);
		while (!q.empty()){
			vector<TreeNode*> q2 = std::move(q);
			
			vector<int> path;
			while (!q2.empty()){
            	auto n = q2.front();
				q2.erase(q2.begin());
            	path.emplace_back(n->val);
            	if (n->left) {
                	q.push_back(n->left);
            	}
            	if (n->right) {
                	q.push_back(n->right);
            	}	
			}
			all.push_back(path);
		}
		return all;
	}


	void test(){
		/*TreeNode* root = new TreeNode(100);
		root->left = new TreeNode(7);
		root->right = new TreeNode(8);
		root->left->left = new TreeNode(9);
		root->left->right = new TreeNode(12);
		root->right->left = new TreeNode(92);
		root->right->right = new TreeNode(122);
		print_tree(root);
		*/

		auto root = g_tree({100,7,8,9,12,92,132});
		p_tree(root);
		auto m = levelOrder(root);
		for(auto v:m){
			for (auto vv:v){
				cout << vv << "     ";
			}
			cout << endl;
		}
	}
};
