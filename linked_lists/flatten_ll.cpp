#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->child != NULL)
            cout << " -> ";
        head = head->child;
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
            c1 = c1->child;
        }
        else
        {
            newHead = list2;
            c2 = c2->child;
        }
        newCurr = newHead;

        while (c1 != nullptr && c2 != nullptr)
        {
            if (c1->val <= c2->val)
            {
                newCurr->child = c1;
                c1 = c1->child;
            }
            else
            {
                newCurr->child = c2;
                c2 = c2->child;
            }
            newCurr = newCurr->child;
        }
        if (c1 == nullptr)
            newCurr->child = c2;
        if (c2 == nullptr)
            newCurr->child = c1;

        return newHead;
    }
    ListNode *flattenLinkedListIterative(ListNode *&head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ptr1 = head;
        ListNode *ptr2 = nullptr;
        ListNode *newHead = nullptr;
        while (ptr1->next != nullptr)
        {
            ptr2 = ptr1->next;
            ListNode *nextLink = ptr2->next;
            ptr2->next = nullptr;
            ptr1->next = nullptr;
            head = mergeTwoLists(ptr1, ptr2);
            head->next = nextLink;
            ptr1 = head;
        }
        return head;
    }
    ListNode *flattenLinkedListRecursive(ListNode *&head)
    {
        // Base Case
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *subHead = flattenLinkedListRecursive(head->next);
        head = mergeTwoLists(head, subHead);
        return head;
    }
};

ListNode *buildMultilevelList(const vector<vector<int>> &levels)
{
    if (levels.empty())
        return nullptr;

    // Keep the first node of each level to wire up child pointers
    vector<ListNode *> levelHeads;

    for (const auto &level : levels)
    {
        if (level.empty())
        {
            levelHeads.push_back(nullptr);
            continue;
        }

        ListNode *head = new ListNode(level[0]);
        ListNode *curr = head;
        for (int i = 1; i < level.size(); ++i)
        {
            curr->child = new ListNode(level[i]);
            curr = curr->child;
        }

        levelHeads.push_back(head);
    }

    // Now wire the child pointers between levels
    for (size_t i = 1; i < levelHeads.size(); ++i)
    {
        if (levelHeads[i - 1])
        {
            levelHeads[i - 1]->child = levelHeads[i];
        }
    }

    return levelHeads[0]; // This is the top-level head
}

int main()
{
    Solution sol;

    ListNode *head = nullptr;

    ListNode *newHead = sol.flattenLinkedListRecursive(head);
    printList(newHead);
    return 0;
}