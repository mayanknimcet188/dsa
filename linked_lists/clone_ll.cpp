#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *r)
    {
        val = data1;
        next = next1;
        random = r;
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

void printSpecialLinkedList(ListNode *head)
{
    if (!head)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    ListNode *current = head;
    std::unordered_map<ListNode *, int> nodeToVal; // To store node addresses and their values for random pointer display

    // First pass: Populate the map with node addresses and values
    // This helps in displaying the value of the random pointed-to node
    // without needing to traverse the list again or dealing with cycles
    ListNode *temp = head;
    while (temp)
    {
        nodeToVal[temp] = temp->val;
        temp = temp->next;
    }

    std::cout << "List Nodes:" << std::endl;
    int index = 0;
    while (current)
    {
        std::cout << "Node " << index++ << ": ";
        std::cout << "Val = " << current->val;

        if (current->random)
        {
            // If the random pointer points to a valid node, display its value
            std::cout << ", Random points to Val = " << nodeToVal[current->random];
        }
        else
        {
            std::cout << ", Random points to NULL";
        }

        std::cout << std::endl;
        current = current->next;
    }
}

ListNode *constructSpecialLinkedList(const std::vector<std::vector<int>> &input)
{
    if (input.empty())
    {
        return nullptr;
    }

    std::vector<ListNode *> nodes;
    std::unordered_map<ListNode *, int> nodeToIndex; // To map original nodes to their indices

    // Step 1: Create all nodes and store them in a vector
    // Also, map original nodes to their indices for easier random pointer assignment
    for (int i = 0; i < input.size(); ++i)
    {
        ListNode *newNode = new ListNode(input[i][0]);
        nodes.push_back(newNode);
    }

    // Step 2: Set 'next' and 'random' pointers
    for (int i = 0; i < input.size(); ++i)
    {
        // Set 'next' pointer
        if (i + 1 < input.size())
        {
            nodes[i]->next = nodes[i + 1];
        }

        // Set 'random' pointer
        int random_index = input[i][1];
        if (random_index != -1)
        {
            nodes[i]->random = nodes[random_index];
        }
    }

    return nodes[0]; // Return the head of the constructed list
}

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *ptr = head;
        while (ptr != nullptr)
        {
            ListNode *newNode = new ListNode(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = ptr->next->next;
        }
        ptr = head;
        while (ptr != nullptr && ptr->next != nullptr)
        {
            if (ptr->random != nullptr)
                ptr->next->random = ptr->random->next;
            else
                ptr->next->random = nullptr;
            ptr = ptr->next->next;
        }
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head->next;
        ptr = head;
        ListNode *clonePtr = dummyNode->next;
        while (ptr != nullptr)
        {
            ptr->next = clonePtr->next;
            if (clonePtr->next != nullptr)
                clonePtr->next = clonePtr->next->next;
            else
                clonePtr->next = nullptr;
            ptr = ptr->next;
            clonePtr = clonePtr->next;
        }
        return dummyNode->next;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> input = {
        {10, 3},
        {20, 0},
        {30, -1},
        {40, 2},
        {50, 1},
        {60, -1}};
    ListNode *head = constructSpecialLinkedList(input);

    ListNode *newHead = sol.copyRandomList(head);
    printSpecialLinkedList(newHead);
    return 0;
}