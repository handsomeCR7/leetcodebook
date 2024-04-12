#include <iostream>
using namespace std;

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
    ListNode* trainningPlan(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* temp;
        while (cur != NULL)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }
};


int main8() {
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
    ListNode* res = solution.trainningPlan(n0);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    system("pause");
    return 0;
}