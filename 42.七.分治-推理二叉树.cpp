#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

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
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        // 建立inorder各个元素对应索引的hashmap
        unordered_map<int, int>inorderhashmap = setinorderhashmap(inorder);
        
        // 从根节点开始构建
        TreeNode* root = dfs(preorder, inorderhashmap, 0, 0, preorder.size() - 1);
        return root;
    }
private:
    // 建立inorder各个元素对应索引的hashmap
    unordered_map<int, int> setinorderhashmap(vector<int>& inorder) {
        unordered_map<int, int>inorderhashmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderhashmap[inorder[i]] = i;
        }
        return inorderhashmap;
    }

    // 构建以某节点为根的树
    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& inorderhashmap, int i, int left, int right) {
        // preorder用来确定当前要构造的根节点i，和左右子树的第一个元素
        // inorder用来确定当前根节点左右子树的区间left，right

        if (left > right)
        {
            return nullptr;
        }

        // 查询当前节点在inorderhashmap中的值，即该节点对应在inorder中的索引
        int m = inorderhashmap[preorder[i]];

        // 实例化当前根节点
        TreeNode* root = new TreeNode(preorder[i]);

        // 执行完dfs，回溯时进行root->left赋值操作，即完成边的构建
        root->left = dfs(preorder, inorderhashmap, i + 1, left, m - 1);
        root->right = dfs(preorder, inorderhashmap, i + 1 + (m - left), m + 1, right);

        // 当前根节点下的子树构建完成，将此根节点返回，供上层的根节点继续构建边
        return root;
    }
};

int main42() {
    vector<int>preorder = { 3, 9, 20, 15, 7 };
    vector<int>inorder = { 9, 3, 15, 20, 7 };
    Solution s;
    TreeNode* res = s.deduceTree(preorder, inorder);

    system("pause");
    return 0;
}