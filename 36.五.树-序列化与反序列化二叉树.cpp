#include <iostream>
using namespace std;
#include <queue>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)   return {};
        queue<TreeNode*>q;
        q.push(root);
        string res;
        TreeNode* CR = nullptr;
        // 先遍历一次，找到最后一个节点的位置
        int cishu = 1;
        while (!q.empty())
        {
            if (q.front()->left != nullptr)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr)
            {
                q.push(q.front()->right);
            }
            CR = q.front();
            q.pop();
            cishu++;
        }
        q.push(root);
        while (q.front() != CR&&cishu>=0)
        {
            // 如果检测到该节点的值是7777，则说明该节点是空，将该节点存入res，但不再设其孩子节点
            if (q.front()->val == 7777) { res += "null,"; q.pop(); continue; }
            else
            {
                // 如果第一次出现该节点的孩子节点是空的，则先将该节点存入res，再将新建一个标志节点来填补该空孩子节点的位置
                res += to_string(q.front()->val); res += ","; cishu--;
                if (q.front()->left == nullptr) { q.front()->left = new TreeNode(7777); }
                if (q.front()->right == nullptr) { q.front()->right = new TreeNode(7777); }
            }
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
        }
        // 单独处理最后那个节点
        res += to_string(q.front()->val);
        return res;
    }
   

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())    return nullptr;
        vector<int>CR;
        int i = 0;
        int num = 0;
        int cheng = 1;
        // 将stri型转化为int型
        while (data[i] != '\0') {
            num = 0;
            cheng = 1;
            if (data[i] == 'n')
            {
                CR.push_back(7777);
                i = i + 5;
                if (i >= data.size())break;
                else continue;
            }
            while (data[i] != ',' && data[i] != '\0')
            {
                if (data[i] == '-')
                {
                    cheng = -1;
                }
                else if (data[i] - '0' >= 0 && data[i] <= '9')
                {
                    num = num * 10 + cheng * (data[i] - '0');
                }
                i++;
            }
            CR.push_back(num);
            if (data[i] == '\0') { break; }
            i++;
        }

        // 构造树
        queue<TreeNode*>qq; // 作为根
        i = 0;
        while (i < CR.size())
        {
            qq.emplace(new TreeNode(CR[i])); 
            i++;
        }
        queue<TreeNode*>qqq = qq;   // 复制qq，作为孩子
        TreeNode* res = qqq.front();
        qqq.pop();

        while (!qqq.empty())
        {
            // 判断qq头元素是不是7777，是不是为空
            // 如果为空，pop掉该元素，不设置操作孩子节点
            // 如果不为空则根据孩子节点是否为空设置孩子节点
            if (qq.front()->val == 7777)
            {
                qq.pop();
                continue;
            }

            // 如果孩子是7777，则说明是空节点，则设置该孩子节点，直接pop掉
            // 否则该孩子不空，需要根据根节点，设置相应的左右孩子节点
            // 设置左孩子节点
            if (qqq.front()->val != 7777)
            {
                qq.front()->left = qqq.front();
            }
            qqq.pop();
            if (qqq.empty())
            {
                break;
            }

            // 设置右孩子节点
            if (qqq.front()->val != 7777)
            {
                qq.front()->right = qqq.front();
            }
            qqq.pop();

            // pop掉该根节点，换下一个根节点
            qq.pop();
        }
        

        /*int xunhuan = (p.size() - 2) / 2;
        queue<TreeNode*>qq;
        qq.push(res);
        for (int i = 0; i <= xunhuan; i++)
        {
            if (2*i+1 < CR.size() && CR[2 * i + 1] != 7777)
            {
                res->left = new TreeNode(CR[2 * i + 1]);
            }
            if (2 * i + 2 < CR.size() && CR[2 * i + 2] != 7777)
            {
                res->right = new TreeNode(CR[2 * i + 2]);
            }
            
            if (qq.front()->left != nullptr)
            {
                qq.push(qq.front()->left);
            }
            if (qq.front()->right != nullptr)
            {
                qq.push(qq.front()->right);
            }
            qq.pop();
            res = qq.front();
            
        }*/
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main36() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode* n0 = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    //TreeNode* n2 = new TreeNode(3);
    ///*TreeNode* n3 = new TreeNode(6);
    //TreeNode* n4 = new TreeNode(2);*/
    //TreeNode* n5 = new TreeNode(2);
    //TreeNode* n6 = new TreeNode(4);
    //TreeNode* n7 = new TreeNode(3);
    //TreeNode* n8 = new TreeNode(1);
    // 构建引用指向（即指针）
    n0->left = n1;
    //n0->right = n2;
    ///*n1->left = n3;
    //n1->right = n4;*/
    //n2->left = n5;
    //n2->right = n6;
    //n5->left = n7;
    //n5->right = n8;

    Codec codec;
    codec.deserialize(codec.serialize(n0));


    system("pause");
    return 0;
}