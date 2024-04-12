#include <iostream>
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
    bool checkSymmetricTree(TreeNode* root) {
        /*if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return 1;
        }
        if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr))
        {
            return false;
        }
        if (root->left!=nullptr && root->right != nullptr && root->left->val == root->right->val)
        {
            return liangkeshu(root->left, root->right);
        }
        return 0;*/

        return root == nullptr || liangkeshu(root->left, root->right);
    }
    bool liangkeshu(TreeNode* A, TreeNode* B)
    {
        if (A == nullptr && B == nullptr) {
            return 1;
        }
        if (A != nullptr && B != nullptr && A->val == B->val)
        {
            return liangkeshu(A->left, B->right) && liangkeshu(A->right, B->left);
        }
        return 0;
    }
};

int main29() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(7);
    TreeNode* n3 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(8);
    TreeNode* n5 = new TreeNode(9);
    TreeNode* n6 = new TreeNode(9);
    TreeNode* n7 = new TreeNode();
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution s;
    bool k = s.checkSymmetricTree(n1);
    cout << k << endl;

    system("pause");
    return 0;
}