#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> res;
		if (root == nullptr) {
			return res;
		} else {
			q.push(root);
			while (! q.empty()) {
				TreeNode* tn = q.front();
				res.push_back(tn->val);
				if (tn->left != nullptr) q.push(tn->left);
				if (tn->right != nullptr) q.push(tn->right);
				q.pop();
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}
