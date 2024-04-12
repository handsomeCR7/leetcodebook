#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root->val > p->val && root->val > q->val)
//        {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if(root->val < p->val && root->val < q->val)
//        {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        return root;
//    }
//};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                break;
            }
        }
        return root;
    }
};

int main34() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(8);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(7);
    TreeNode* n7 = new TreeNode(9);
    TreeNode* n8 = new TreeNode(3);
    TreeNode* n9 = new TreeNode(5);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->left = n8;
    n5->right = n9;

    Solution s;
    TreeNode* res = s.lowestCommonAncestor(n1, n2, n5);

    system("pause");
    return 0;
}