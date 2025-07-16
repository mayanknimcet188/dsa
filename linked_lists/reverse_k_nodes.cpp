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
    ListNode *reverseKNodes(ListNode *start, ListNode *&end, int k)
    {
        // Base Case
        if (k == 0)
        {
            end = start->next;
            return start;
        }
        // recursive call
        ListNode *newHead = reverseKNodes(start->next, end, k - 1);
        // Process the curr start
        start->next->next = start;
        start->next = end;
        return newHead;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        int length = 0;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            curr = curr->next;
            length++;
        }
        ListNode *start = head;
        ListNode *last = nullptr;
        int remaining = length;
        while (remaining >= k)
        {
            ListNode *end = nullptr;
            ListNode *reversedKHead = reverseKNodes(start, end, k - 1);
            if (last == nullptr)
            {
                head = reversedKHead;
            }
            else
            {
                last->next = reversedKHead;
            }
            remaining -= k;
            last = start;
            start = end;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode *node6 = new ListNode(7);
    ListNode *node5 = new ListNode(4, node6);
    ListNode *node4 = new ListNode(3, node5);
    ListNode *node3 = new ListNode(2, node4);
    ListNode *node2 = new ListNode(1, node3);
    ListNode *head = new ListNode(6, node2);
    ListNode *start = head->next;

    ListNode *reversedHead = sol.reverseKGroup(head, 3);
    printList(reversedHead);
    return 0;
}