#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* temp = head;
        if (temp->val == val)
        {
            return head->next;
        }
        while ( temp->next != nullptr)
        {
            if (temp->next->val == val)
            {
                if (temp->next->next == NULL)
                {
                    temp->next = NULL;
                    return head;
                }
                else
                {
                    temp->next = temp->next->next;
                    return head;
                } 
            }
            temp = temp->next;
        }
        return head;
    }
};

int main7() {
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
    ListNode* res = solution.deleteNode(n0,4);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    system("pause");
    return 0;
}