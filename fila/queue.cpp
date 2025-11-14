#include <iostream>
using namespace std;

// Exemplo de fila utilizando linkedlist padrão do C++
struct Node
{
    int value;
    Node *next;
};

struct Queue
{
    Node *front; // same as first
    Node *rear;  // same as last
    int total;
};

void enqueue(Queue *&queue, int value);
void dequeue(Queue *&queue);
void printQueue(Queue *queue);

int main()
{
    Queue *queue = new Queue{nullptr, nullptr, 0};
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}

void enqueue(Queue *&queue, int value)
{
    if (queue->front == nullptr)
    {
        queue->front = new Node{value, nullptr};
        queue->rear = queue->front;
        queue->total = 1;
        return;
    }

    queue->rear->next = new Node{value, nullptr};
    queue->rear = queue->rear->next;
    queue->total++;
}

void dequeue(Queue *&queue)
{
    if (queue->front == nullptr)
    {
        return;
    }

    if (queue->front->next == nullptr)
    {
        queue->front = nullptr;
        queue->rear = nullptr;
        return;
    }

    Node *temp = queue->front;
    queue->front = queue->front->next;
    delete temp;
    queue->total--;
}

void printQueue(Queue *queue)
{
    if (queue->front == nullptr)
    {
        cout << "Lista zerada" << endl;
        return;
    }

    Node *cur = queue->front;
    cout << "Começo da lista!" << endl;
    while (cur != nullptr)
    {
        cout << cur->value << endl;
        cur = cur->next;
    }

    cout << "final da lista!" << endl;
}