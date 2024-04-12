#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* L = head;
        while (L != NULL)
        {
            Node* cur = new Node(L->val);
            cur->next = L->next;
            L->next = cur;
            L = L->next->next;
        }
        L = head;
        while (L != NULL)
        {
            if (L->random == NULL)
            {
                L->next->random = NULL;
            }
            else
            {
                L->next->random = L->random->next;
            }
            
            L = L->next->next;
        }
        L = head;
        Node* res = head->next;
        Node* res1 = res;
        while (res->next != NULL)
        {
            L->next = res->next;
            L = L->next;
            res->next = L->next;
            res = res->next;

        }
        L->next = NULL;
        return res1;
    }
};

int main12()
{
    /* 初始化链表l1: 1 -> 3 -> 2 -> 5 -> 4 */
    // 初始化各个节点

    Node* n0 = new Node(7);
    Node* n1 = new Node(13);
    Node* n2 = new Node(11);
    Node* n3 = new Node(10);
    Node* n4 = new Node(1);

    // 构建引用指向
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // 构建random指向
    n0->random = NULL;
    n1->random = n0;
    n2->random = n4;
    n3->random = n2;
    n4->random = n0;

    Solution solution;
    Node* res = solution.copyRandomList(n0);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }

    system("pause");
    return 0;
}