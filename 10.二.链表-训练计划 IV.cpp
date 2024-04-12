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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
        {
            return {};
        }
        else if (l1 == NULL) 
        {
            return l2;
        }
        else if (l2 == NULL) 
        {
            return l1;
        }
        ListNode* head = l1;
        ListNode* L1 = l1;
        ListNode* L2 = l2;
        if (l1->val > l2->val)
        {
            head = l2;
            L1 = l2;
            L2 = l1;
        }
        ListNode* temp = L1;
        ListNode* temp2 = L2;
        while (L1 != NULL || L2->next != NULL)
        {
            if (L1->val > L2->val)
            {
                temp->next = L2;
                L2 = L2->next;
                while (L2 != NULL && L1->val > L2->val)
                {
                    temp2 = L2;
                    L2 = L2->next;
                }
                temp2->next = L1;
                if (L2 == NULL)
                {
                    return head;
                }
                temp2 = L2;
            }
            temp = L1;
            L1 = L1->next;
            
            if (L1 == NULL)
            {
                temp->next = L2;
                return head;
            }
        }
        return head;


    }
};

int main10()
{
    /* 初始化链表l1: 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点

    ListNode* n0 = new ListNode(-10);
    ListNode* n1 = new ListNode(-10);
    ListNode* n2 = new ListNode(-9); 
    ListNode* n3 = new ListNode(-4); 
    ListNode* n4 = new ListNode(1); 
    ListNode* n5 = new ListNode(6); 
    ListNode* n6 = new ListNode(6);
    
    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    

    /* 初始化链表l2: 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点
    ListNode* m0 = new ListNode(-7);
    
    
    
    // 构建引用指向
    
    
    
    Solution solution;
    ListNode* res = solution.trainningPlan(n0, m0);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    system("pause");
    return 0;
}