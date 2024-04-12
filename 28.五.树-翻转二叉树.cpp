#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode* n = new TreeNode(root->val);
        bianli(root,n);
        return n;
    }
    void bianli(TreeNode* root, TreeNode* n) {
        if (root->left != NULL)
        {
            TreeNode* n1 = new TreeNode(root->left->val);
            n->right = n1;
            bianli(root->left, n->right);
        }
        if (root->right != NULL)
        {
            TreeNode* n1 = new TreeNode(root->right->val);
            n->left = n1;
            bianli(root->right, n->left);
        }
    }
};

int main28() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(7);
    TreeNode* n3 = new TreeNode(9);
    TreeNode* n4 = new TreeNode(8);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(2);
    TreeNode* n7 = new TreeNode(4);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution s;
    s.mirrorTree(n1);

    system("pause");
    return 0;
}