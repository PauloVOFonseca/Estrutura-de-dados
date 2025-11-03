#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;
};

void newNode(int value, Node *&head);
void reverseList(Node *&head);
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
    reverseList(head);
    printList(head);
}

void reverseList(Node *&head)
{
    if (!head || head->next == nullptr)
        return;

    Node *cur = head;
    Node *temp = nullptr;

    while (cur != nullptr)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if (temp != nullptr)
        head = temp->prev;
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

    if (!head)
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node *cur = head;
    cout << "Lista em ordem:" << endl;
    while (cur->next != nullptr)
    {
        cout << cur->value << endl;
        cur = cur->next;
    }

    cout << cur->value << endl;

    cout << "Lista em ordem reversa:" << endl;
    while (cur != nullptr)
    {
        cout << cur->value << endl;
        cur = cur->prev;
    }
}