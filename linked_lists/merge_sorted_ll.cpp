#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;

        ListNode *c1 = list1;
        ListNode *c2 = list2;
        ListNode *newHead = nullptr;
        ListNode *newCurr = nullptr;
        if (list1->val <= list2->val)
        {
            newHead = list1;
            c1 = c1->next;
        }
        else
        {
            newHead = list2;
            c2 = c2->next;
        }
        newCurr = newHead;

        while (c1 != nullptr && c2 != nullptr)
        {
            if (c1->val <= c2->val)
            {
                newCurr->next = c1;
                c1 = c1->next;
            }
            else
            {
                newCurr->next = c2;
                c2 = c2->next;
            }
            newCurr = newCurr->next;
        }
        if (c1 == nullptr)
            newCurr->next = c2;
        if (c2 == nullptr)
            newCurr->next = c1;

        return newHead;
    }
};

int main()
{
    Solution sol;
    // list1
    ListNode *list1 = nullptr;
    // list2
    ListNode *list2 = nullptr;

    ListNode *newHead = sol.mergeTwoLists(list1, list2);
    printList(newHead);
    return 0;
}