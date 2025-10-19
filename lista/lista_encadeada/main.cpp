#include <iostream>
using namespace std;

struct list
{
    int value;
    list *next;
    list(int v, list *n = nullptr) : value(v), next(n) {}
};

void addToList(int value, list *list);
void removeElementByValue(int value, list *&list);
void removeElementByPosition(int value, list *&list);
void printList(list *head);

int main()
{
    list *head = new list(1);

    addToList(21, head);
    addToList(37, head);
    addToList(7, head);
    addToList(45, head);
    addToList(2, head);
    addToList(52, head);

    printList(head);

    removeElementByValue(2, head);

    printList(head);

    removeElementByPosition(1, head);
    printList(head);
    removeElementByPosition(0, head);

    printList(head);

    return 0;
}

void addToList(int value, list *current)
{
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = new list(value);
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