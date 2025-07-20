#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next != NULL)
            cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *removeDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *ptr = head;
        ListNode *skip = head;
        while (ptr != nullptr)
        {
            skip = ptr->next;
            while (skip != nullptr && skip->val == ptr->val)
            {
                if (skip->val == ptr->val)
                {
                    ListNode *temp = skip;
                    skip = skip->next;
                    delete temp;
                }
            }
            ptr->next = skip;
            if (skip != nullptr)
                skip->prev = ptr;
            ptr = skip;
        }
        return head;
    };
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(7);
    ListNode *node5 = new ListNode(9);
    ListNode *node6 = new ListNode(11);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;

    ListNode *newHead = sol.removeDuplicates(head);
    printList(newHead);
    return 0;
}