#include <iostream>
using namespace std;

// Exemplo de lista utilizando array padrão do C++

struct Queue
{
    int first, last, total, capacity;
    float *data;
};

void createQueue(Queue *&queue, int capacity);
void enqueue(Queue *&queue, int value);
void dequeue(Queue *&queue);
void printList(Queue *queue);

int main()
{
    Queue *queue = new Queue();
    createQueue(queue, 5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printList(queue);

    enqueue(queue, 6);
    printList(queue);

    dequeue(queue);
    printList(queue);

    enqueue(queue, 6);
    printList(queue);
    return 0;
}

void createQueue(Queue *&queue, int capacity)
{
    queue->capacity = capacity;
    queue->first = 0;
    queue->last = -1;
    queue->total = 0;
    queue->data = new float[capacity];
}

void enqueue(Queue *&queue, int value)
{
    if (queue->total == queue->capacity)
    {
        cout << "A lista está cheia!" << endl;
        return;
    }

    if (queue->last == queue->capacity - 1)
    {
        queue->last = 0;
    }
    else
    {
        queue->last++;
    }

    queue->data[queue->last] = value;
    queue->total++;
}

void dequeue(Queue *&queue)
{
    if (queue->total == 0)
    {
        cout << "A lista está vazia!" << endl;
        return;
    }

    cout << queue->data[queue->first] << " saiu da lista" << endl;
    if (queue->first == queue->capacity - 1)
    {
        queue->first = 0;
    }
    else
    {
        queue->first++;
    }
    queue->total--;
}

void printList(Queue *queue)
{
    if (queue->total == 0)
    {
        cout << "A lista está vazia!" << endl;
        return;
    }

    for (int i = queue->first; i < queue->total; i++)
    {
        cout << queue->data[i] << endl;
    }
    cout << "Fim da lista!" << endl;
}