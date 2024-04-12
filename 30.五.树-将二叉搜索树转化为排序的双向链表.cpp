#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;


    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* pre=nullptr, * head;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        paixu(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    
    void paixu(Node* root)
    {
        if (root == nullptr)return;
        paixu(root->left);
        if (pre != nullptr)
        {
            pre->right = root;
        }
        else
        {
            head = root;
        }
        root->left = pre;
        pre = root;
        paixu(root->right);
    }
};

int main30() {
    /* 初始化二叉树 */
    // 初始化节点
    Node* n1 = new Node(4);
    Node* n2 = new Node(2);
    Node* n3 = new Node(5);
    Node* n4 = new Node(1);
    Node* n5 = new Node(3);
    // 构建引用指向（即指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution s;
    s.treeToDoublyList(n1);

    system("pause");
    return 0;
}
