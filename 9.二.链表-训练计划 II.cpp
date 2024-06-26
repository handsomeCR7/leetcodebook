﻿#include <iostream>
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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* cur = head;
        ListNode* pre_cnt = head;
        int temp = 1;
        while (cur != NULL)
        {
            if (temp > cnt)
            {
                pre_cnt = pre_cnt->next;
                
            }
            cur = cur->next;
            temp++;
        }
        return pre_cnt;
    }
};


int main9()
{
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
    ListNode* res = solution.trainingPlan(n0,5);
    cout << res->val << endl;
 

    system("pause");
    return 0;
}