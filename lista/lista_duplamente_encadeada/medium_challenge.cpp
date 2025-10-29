#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;
};

void newNode(int value, Node *&head);
void insertAtPosition(Node *&head, int value, int position);
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

    insertAtPosition(head, 6, 0);
    insertAtPosition(head, 7, 3);
    insertAtPosition(head, 8, 10);
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

void insertAtPosition(Node *&head, int value, int position)
{
    if (!head)
    {
        head = new Node{value, nullptr, nullptr};
        return;
    }

    if (position == 0)
    {
        Node *temp = head;
        temp = new Node{value, nullptr, temp};
        head = temp;
        head->next->prev = head;
        return;
    }

    Node *cur = head;
    int count = 0;
    while (cur->next != nullptr && count < position - 1)
    {
        cur = cur->next;
        count++;
    }
    cur->next = new Node{value, cur, cur->next};
    
    if (cur->next->next)
        cur->next->next->prev = cur->next;
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