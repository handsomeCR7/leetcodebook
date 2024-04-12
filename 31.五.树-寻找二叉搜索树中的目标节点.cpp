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
    int res = 0;
    int num = 0;
    int findTargetNode(TreeNode* root, int cnt) {
        num = cnt;
        CR(root);
        return res;
    }
    void CR(TreeNode* root)
    {
        if (root == nullptr)return;
        CR(root->right);
        num--;
        if (num == 0)
        {
            res = root->val;
        }
        CR(root->left);
    }
};

int main31() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(5);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n6->left = n7;
    Solution s;
    int res=s.findTargetNode(n1,4);
    cout << res << endl;

    system("pause");
    return 0;
}
