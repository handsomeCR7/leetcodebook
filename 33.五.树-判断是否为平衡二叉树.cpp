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
    bool res = 1;

    bool isBalanced(TreeNode* root) {
        high(root);
        return res;
    }

    int high(TreeNode* root) {

        int left = 0;
        int right = 0;
        if (root == nullptr)
        {
            return 0;
        }

        left = high(root->left);
        right = high(root->right);

        if (left - right > 1 || right - left > 1)
        {
            res = 0;
        }
        return max(left, right) + 1;
    }
};
int main33() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);


    TreeNode* n6 = new TreeNode(15);
    TreeNode* n7 = new TreeNode(7);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    

    n3->left = n6;
    n3->right = n7;

    Solution s;
    bool res = s.isBalanced(n1);
    cout << res << endl;

    system("pause");
    return 0;
}