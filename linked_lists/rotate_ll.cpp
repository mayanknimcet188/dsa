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
    pair<ListNode *, int> lengthLL(ListNode *head)
    {
        if (head == nullptr)
        {
            return make_pair(nullptr, 0);
        }
        int length = 1;
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
            length++;
        }
        return make_pair(tail, length);
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        pair<ListNode *, int> result = lengthLL(head);
        ListNode *tail = result.first;
        int length = result.second;
        // Effective k
        k = k % length;
        if (k == 0)
            return head;
        int counter = length - k - 1;
        ListNode *pivotPoint = head;
        while (counter--)
        {
            pivotPoint = pivotPoint->next;
        }
        // Pointer Manipulation
        ListNode *newHead = pivotPoint->next;
        pivotPoint->next = nullptr;
        tail->next = head;
        head = newHead;
        return newHead;
    }
};

int main()
{
    Solution sol;
    ListNode *node5 = new ListNode(5);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *head = new ListNode(1, node2);

    ListNode *newHead = sol.rotateRight(head, 7);
    printList(newHead);
    return 0;
}