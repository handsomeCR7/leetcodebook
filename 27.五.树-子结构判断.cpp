#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 遍历A的各个节点
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
        {
            return false;
        }
        if(isSameNode(A, B))
        {
            return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    // 对各个节点，判断是不是以此节点的子树
    bool isSameNode(TreeNode* A, TreeNode* B) {
        if (B == NULL)
        {
            return true;
        }
        else if (A == NULL || A->val != B->val)
        {
            return false;
        }
        return isSameNode(A->left, B->left) && isSameNode(A->right, B->right);
    }
};

int main27() {
    /* 初始化二叉树A */
    // 初始化节点
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(8);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    /* 初始化二叉树B */
    // 初始化节点
    TreeNode* m1 = new TreeNode(6);
    TreeNode* m2 = new TreeNode(1);
    // 构建引用指向（即指针）
    m1->left = m2;

    Solution s;
    bool k=s.isSubStructure(n3, m1);
    cout << k << endl;
    system("pause");
    return 0;
}