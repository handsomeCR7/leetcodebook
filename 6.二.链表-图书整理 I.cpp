#include <iostream>
using namespace std;
#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        vector<int>res;
        res.resize(length);
        temp = head;
        for (int i = length - 1; i >= 0; i--)
        {
            res[i] = temp->val;
            temp = temp->next;
        }

        return res;
    }
};

int main6() {
    /* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点
    ListNode* n0 = new ListNode(1);
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(5);
    ListNode* n4 = new ListNode(4);
    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Solution solution;
    vector<int>res = solution.reverseBookList(n0);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }


    system("pause");
    return 0;
}