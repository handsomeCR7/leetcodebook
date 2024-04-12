#include <iostream>
using namespace std;
#include <vector>
#include <deque>


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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        vector<int> res1;
        vector<vector<int>>res;
        deque<TreeNode*>q;
        q.push_back(root);
        int pre_num = 1;
        int cur_num = 0;
        int sign = 0;
        while (!q.empty())
        {
            if (sign == 0)
            {
                res1.push_back(q.back()->val);
                if (q.back()->left != NULL)
                {
                    q.push_front(q.back()->left);
                    cur_num++;
                }
                if (q.back()->right != NULL)
                {
                    q.push_front(q.back()->right);
                    cur_num++;
                }
                q.pop_back();
            }
            else if (sign == 1)
            {
                res1.push_back(q.front()->val);
                if (q.front()->right != NULL)
                {
                    q.push_back(q.front()->right);
                    cur_num++;
                }
                if (q.front()->left != NULL)
                {
                    q.push_back(q.front()->left);
                    cur_num++;
                }
                q.pop_front();
            }
            
            pre_num--;
            if (pre_num == 0)
            {
                res.push_back(res1);
                res1.clear();
                pre_num = cur_num;
                cur_num = 0;
                if (sign == 0)
                {
                    sign = 1;
                }
                else if (sign == 1)
                {
                    sign = 0;
                }
            }
        }
        return res;
    }
};

int main26() {
    /* 初始化二叉树 */
// 初始化节点
    TreeNode* n1 = new TreeNode(8);
    TreeNode* n2 = new TreeNode(17);
    TreeNode* n3 = new TreeNode(21);
    TreeNode* n4 = new TreeNode(18);
    TreeNode* n5 = new TreeNode(6);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->right = n5;

    Solution s;
    s.decorateRecord(n1);



    system("pause");
    return 0;
}