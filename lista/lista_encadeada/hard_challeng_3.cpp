#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *mergeSortedLists(Node *head1, Node *head2);
void printList(Node *head);

int main()
{
    Node *head1 = new Node{1, new Node{2, new Node{5, new Node{7, nullptr}}}};
    Node *head2 = new Node{3, new Node{4, new Node{6, nullptr}}};

    Node *head = mergeSortedLists(head1, head2);
    printList(head);

    return 0;
}

Node *mergeSortedLists(Node *head1, Node *head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    Node *mergedList = nullptr;

    if (head1->value < head2->value)
    {
        mergedList = head1;
        head1 = head1->next;
    }
    else
    {
        mergedList = head2;
        head2 = head2->next;
    }

    Node *tail = mergedList;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->value < head2->value)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }

    if (head1)
    {
        tail->next = head1;
    }
    else
    {
        tail->next = head2;
    }

    return mergedList;
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
