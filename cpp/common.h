#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* g_tree(vector<int> t){
	if (t.empty()){
		return nullptr;
	}
	
	int i = 0;
	TreeNode* root = new TreeNode(t[i]);

	vector<TreeNode*> q;
	q.push_back(root);
	
	int ll = t.size();

	while(!q.empty()){
		auto q2 = std::move(q);
		while(!q2.empty()){
			auto n = q2[0];
			q2.erase(q2.begin());
			if (!n){
				break;
			}
			auto l = 2*i +1;
			n->left = l < ll ? new TreeNode(t[l]) : nullptr; 
			q.push_back(n->left);
			auto r = 2*i +2;
			n->right = r < ll ? new TreeNode(t[r]) : nullptr; 
			q.push_back(n->right);
			++i;
		}
	}
	return root;
}


void print_tree(TreeNode* root){
       if (!root){
			cout << "null" << endl;
	   } 

		vector<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()){
            vector<TreeNode*> q2 = std::move(q);

            while (!q2.empty()){
                auto n = q2.front();
                q2.erase(q2.begin());
				if (n){
					cout << n->val << "   ";
					q.push_back(n->left);
					q.push_back(n->right);
				}
				else {
					cout << "null" << "   ";
				}
                
            }
            cout <<endl;
        }
}

void p_tree(TreeNode* root){
	print_tree(root);
}

void p_double_vector(vector<vector<int>> v){
	for(auto i:v){
		for(auto ii:i){
			cout << ii << "    ";
		}
		cout << endl;
	}
}
