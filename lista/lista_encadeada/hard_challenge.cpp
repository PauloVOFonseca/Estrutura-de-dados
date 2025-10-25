#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

void reverseList(Node *&head);
void printList(Node *head);

int main()
{
    Node *head = new Node{10, new Node{20, new Node{30, new Node{40, nullptr}}}};

    reverseList(head);
    printList(head);

    return 0;
}

void reverseList(Node *&head)
{
    Node *prev = nullptr;
    Node *cur = head;
    Node *next = nullptr;
    
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

void printList(Node *head)
{
    Node *cur = head;
    while (cur != nullptr) {
        cout << cur->value << endl;
        cur = cur->next;
    }
}
