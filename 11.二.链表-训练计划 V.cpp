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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* A = headA;
        ListNode* B = headB;
     
        while (A != B)
        {
            if (A == NULL)
            {
                A = headB;
            }
            else
            {
                A = A->next;
            }
            if (B == NULL)
            {
                B = headA;
            }
            else
            {
                B = B->next;
            }
        }
        return A;

    }
};


int main11()
{
    // 初始化链表
    // 初始化各个节点

    ListNode* n0 = new ListNode(4);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(8);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(5);


    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;


    // 初始化链表l2: 
    // 初始化各个节点
    ListNode* m0 = new ListNode(5);
    ListNode* m1 = new ListNode(0);
    ListNode* m2 = new ListNode(1);
 
    // 构建引用指向
    m0->next = m1;
    m1->next = m2;
    m2->next = n2;


    Solution solution;
    ListNode* res = solution.getIntersectionNode(n0, m0);
    cout << res->val << endl;
    

    system("pause");
    return 0;
}