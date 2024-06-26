﻿#include <iostream>
using namespace std;
#include <vector>
#include <queue>


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
    vector<int> decorateRecord(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            res.push_back(q.front()->val);
            if (q.front()->left != NULL)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        return res;
    }
};
