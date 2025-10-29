#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;
};

void newNode(int value, Node *&head);
void printList(Node *head);

int main()
{
    Node *head = nullptr;
    newNode(0, head);
    newNode(1, head);
    newNode(2, head);
    newNode(3, head);
    newNode(4, head);
    newNode(5, head);
    printList(head);
}

void newNode(int value, Node *&head)
{
    if (!head)
    {
        head = new Node{value, nullptr, nullptr};
        return;
    }

    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }

    cur->next = new Node{value, cur, nullptr};
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
