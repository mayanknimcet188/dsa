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
    ListNode *deleteAllOccurrences(ListNode *head, int target)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            if (head == nullptr)
                return nullptr;
            ListNode *ptr = head;
            while (ptr != nullptr)
            {
                if (ptr->val == target)
                {
                    if (ptr == head)
                    {
                        ptr = ptr->next;
                        if (ptr != nullptr)
                            ptr->prev = nullptr;
                        delete head;
                        head = ptr;
                        continue;
                    }
                    ListNode *before = ptr->prev;
                    ListNode *after = ptr->next;
                    ListNode *toDelete = ptr;
                    ptr = ptr->next;
                    if (before != nullptr)
                        before->next = after;
                    if (after != nullptr)
                        after->prev = before;

                    delete toDelete;
                }
                else
                    ptr = ptr->next;
            }
            return head;
        }
    };
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(6);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    ListNode *newHead = sol.deleteAllOccurrences(head, 3);
    printList(newHead);
    return 0;
}