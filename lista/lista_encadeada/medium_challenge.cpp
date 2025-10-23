#include <iostream>
using namespace std;

// 1. If the list is empty, do nothing.
// 2. If the value is in the first node, remove the head and update it.
// 3. If the value appears somewhere else, remove only the first occurrence.
// 4. If the value doesn’t exist, do nothing.
// 5. Make sure to properly delete the removed node to avoid memory leaks.

struct Node
{
    int value;
    Node *next;
};

void removeByValue(Node *&head, int target);
void removeByValueImproved(Node *&head, int target);
void printList(Node *head);

int main()
{
    Node *head = new Node{10, new Node{20, new Node{30, new Node{40, new Node{50, new Node{40, nullptr}}}}}};

    removeByValue(head, 40);
    printList(head);

    return 0;
}

void removeByValue(Node *&head, int target)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->value == target)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    Node *previous = head;
    Node *cur = head->next;

    while (cur != nullptr && cur->value != target)
    {
        previous = cur;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        return;
    }

    previous->next = cur->next;
    delete cur;
    delete previous;
}

void removeByValueImproved(Node *&head, int target)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->value == target)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return; // impede continuar a rodar o código, o valor já foi removido
    }

    Node *previous = head;
    Node *cur = head->next;

    while (cur != nullptr && cur->value != target)
    {
        previous = cur;
        cur = cur->next;
    }

    if (cur == nullptr)
        return;

    previous->next = cur->next;
    delete cur;
    // cur precisa ser deletado, pois faz referência apenas ao nó que já não faz mais parte da lista
    // previous não pode ser deletado, pois estaria deletando um ponteiro que pertece a lista, podendo causar crash caso acessado novamente
}

void printList(Node *head)
{
    cout << "Início da lista!" << endl;

    Node *pointer = head;

    while (pointer != nullptr)
    {
        cout << pointer->value << endl;
        pointer = pointer->next;
    }

    cout << "Fim da lista!" << endl;
}