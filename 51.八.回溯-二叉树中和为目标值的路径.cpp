#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void path(TreeNode* root, int target, int now) {
        if (root == nullptr) {
            return;
        }
        else if (now + root->val == target && root->left == nullptr && root->right == nullptr) {
            t.push_back(root->val);
            res.push_back(t);
        }
        else {
            t.push_back(root->val);
            now = now + root->val;
        }
        path(root->left, target, now);
        path(root->right, target, now);
        t.pop_back();
    }

    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        path(root, target, 0);
        return res;
    }
    vector<int>t;
    vector<vector<int>>res;
};

int main() {
    TreeNode* n0 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(8);
    TreeNode* n3 = new TreeNode(11);
    TreeNode* n4 = new TreeNode(NULL);
    TreeNode* n5 = new TreeNode(13);
    TreeNode* n6 = new TreeNode(4);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(2);
    TreeNode* n9 = new TreeNode(NULL);
    TreeNode* n10 = new TreeNode(NULL);
    TreeNode* n11 = new TreeNode(5);
    TreeNode* n12 = new TreeNode(1);
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n2->left = n5;
    n2->right = n6;
    n3->left = n7;
    n3->right = n8;
    n6->left = n11;
    n6->right = n12;
    
    Solution s;
    int target = 22;
    s.pathTarget(n0, target);
    system("pause");
    return 0;
}