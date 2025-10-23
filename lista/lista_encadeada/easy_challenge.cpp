#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

int countNodes(Node *head);
int countNodesImproved(Node *head);

int main()
{
    Node* head = new Node{10, new Node{20, new Node{30, nullptr}}};

    cout << "Quantidade de nós na lista: " << countNodes(head) << endl;
    cout << "Quantidade de nós na lista v.2: " << countNodesImproved(head) << endl;
    return 0;
}

// Minha versão
int countNodes(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }

    if (head->next == nullptr)
    {
        return 1;
    }

    int count = 1;
    while (head->next != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Versão melhorada

int countNodesImproved(Node *head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}