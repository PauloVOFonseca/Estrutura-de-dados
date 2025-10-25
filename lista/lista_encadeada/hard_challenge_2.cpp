#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

void detectAndRemoveCycle(Node *head);
void printList(Node *head);

int main()
{
    Node *head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};
    head->next->next->next->next = head->next;

    detectAndRemoveCycle(head);
    printList(head);

    return 0;
}

void detectAndRemoveCycle(Node *head)
{
    if (!head)
        return;

    Node *slow = head;
    Node *fast = head;

    // Step 1: Detect cycle
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // cycle detected
        {
            // Step 2: Find start of the cycle
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            Node *start = slow; // start of the cycle

            // Step 3: Remove the cycle
            Node *aux = start;
            while (aux->next != start)
                aux = aux->next;

            aux->next = nullptr; // break the cycle
            return;
        }
    }
}

void printList(Node *head)
{
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->value << endl;
        cur = cur->next;
    }
}
