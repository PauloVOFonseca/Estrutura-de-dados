#include <iostream>
using namespace std;

struct list // O melhor nome pra isso seria node
{
    int value;
    list *next;
    list(int v, list *n = nullptr) : value(v), next(n) {}
};

void addToList(int value, int *position, list *&list);
void removeElementByValue(int value, list *&list);
void removeElementByPosition(int value, list *&list);
void printList(list *head);

int main()
{
    list *head = new list(1);

    addToList(21, nullptr, head);
    addToList(37, nullptr, head);
    addToList(7, nullptr, head);
    addToList(45, nullptr, head);
    addToList(2, nullptr, head);
    addToList(52, nullptr, head);
    printList(head);

    removeElementByValue(2, head);
    printList(head);

    removeElementByPosition(1, head);
    printList(head);

    removeElementByPosition(0, head);
    printList(head);

    int position = 0;

    addToList(8299, &position, head);
    printList(head);

    position = 2;

    addToList(499, &position, head);
    printList(head);

    return 0;
}

void addToList(int value, int *position, list *&head)
{
    if (position == nullptr)
    {
        list *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = new list(value);
        return;
    }

    if (*position == 0)
    {
        list *newHead = new list(value, head);
        head = newHead;
        return;
    }

    int count = 0;
    list *cur = head;
    while (cur->next != nullptr && count != *position - 1)
    {
        cur = cur->next;
        count++;
    }

    cur->next = new list(value, cur->next);
}

void removeElementByValue(int valueToRemove, list *&head)
{
    if (head == nullptr)
        return;

    // Caso o valor seja o primeiro elemento da lista
    if (head->value == valueToRemove)
    {
        list *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    list *previous = head;
    list *current = head->next;
    while (current->next != nullptr && current->value != valueToRemove)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Esse valor não existe na lista" << endl;
        return;
    }

    previous->next = current->next;
    delete current;
}

void removeElementByPosition(int position, list *&head)
{
    if (head == nullptr)
        return;

    // Caso o valor seja o primeiro elemento da lista
    if (position == 0)
    {
        list *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    list *previous = head;
    list *current = head->next;
    int count = 1; // Começando count por 1 porque current = segundo nó
                   // Se iniciar count por 0 causaria um erro de off-by-one pois no primeiro loop
                   // count seria 1 enquanto current = terceiro nó.
                   // Poderia usar count = 0, porém já fazemos a remoção do primeiro elemento da lista
                   // No mais, o código código pode ser substituido por
                   // list* previous = nullptr;
                   // list* current = head;
                   // int count = 0;

    while (current != nullptr && count < position)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        cout << "Esse valor não existe na lista" << endl;
        return;
    }

    previous->next = current->next;
    delete current;
}

void printList(list *head)
{
    cout << "Início da lista!" << endl;

    list *pointer = head;

    while (pointer != nullptr)
    {
        cout << pointer->value << endl;
        pointer = pointer->next;
    }

    cout << "Fim da lista!" << endl;
}