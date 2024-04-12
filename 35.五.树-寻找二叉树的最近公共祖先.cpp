#include <iostream>
using namespace std;
#include <string>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 先序遍历
        // 如果该节点命中一个，则可能的根在此节点及其上方，因此直接return此节点，不用再往下遍历了：
        // 1.如果该节点的子树中能命中另一个，则还是return该节点，因此不用往下遍历
        // 2.如果该节点的子树不含另一个，return该节点，往回遍历右子树找下一个目标，找到就return该节点
        // 3.判断返回某一节点时，该节点的返回值是不是有东西，如果都有东西那就是该节点，只要其中有一个为空，那就不是
        // 最终要迭代返回到初始根节点，因此当判断出最近根时需要保存进行返回，可以使返回值left或right中其中一个不为空的进行返回
        if (root == nullptr || root == p || root == q)   return root;// 因为root空时返回的是空，也是root，因此可以合在一起写
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
        {
            left = root;
            return left;
        }
        if (left != nullptr)return left;
        if (right != nullptr)return right;
        return nullptr;
    }
};

int main35() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(5);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(6);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(0);
    TreeNode* n7 = new TreeNode(8);
    TreeNode* n8 = new TreeNode(7);
    TreeNode* n9 = new TreeNode(4);
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
    TreeNode* res = s.lowestCommonAncestor(n1, n2, n9);

    system("pause");
    return 0;
}