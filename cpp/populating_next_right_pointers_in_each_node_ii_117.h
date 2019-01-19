

#include "common.h"

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root){
			return;
		}

		queue<TreeLinkNode* > q;
		q.push(root);

		while(!q.empty()){
			auto q2 = move(q);
			while (!q2.empty()){
				auto t = q2.front();
				q2.pop();
				if (q2.size() > 0){
					t->next = q2.front();
				}
				if (t->left) {
					q.push(t->left);
				}
				if (t->right){
					q.push(t->right);
				}
			}
		}
	}
};
