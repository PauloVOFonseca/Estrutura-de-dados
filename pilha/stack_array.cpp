#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int capacity;
    float *data;
};

void initializeStack(Stack *&stack, int capacity);
void push(Stack *&stack, int value);
void pop(Stack *&stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
void printStack(Stack *stack);
void clearStack(Stack *&stack);

int main()
{
    Stack *stack = new Stack();
    initializeStack(stack, 5);

    printStack(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printStack(stack);

    pop(stack);
    printStack(stack);
    pop(stack);
    printStack(stack);
    pop(stack);
    printStack(stack);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    clearStack(stack);
    printStack(stack);
    return 0;
}

void initializeStack(Stack *&stack, int capacity)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = new float[capacity];
}

void push(Stack *&stack, int value)
{
    if (isFull(stack))
    {
        cout << "Essa pilha está cheia!" << endl;
        return;
    };
    stack->top++;
    stack->data[stack->top] = value;
}

void pop(Stack *&stack)
{
    if (isEmpty(stack))
    {
        cout << "Essa pilha está vazia!" << endl;
        return;
    }

    cout << "Desempilhado:" << stack->data[stack->top] << endl;
    stack->top--;
}

bool isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void clearStack(Stack *&stack)
{
    stack->top = -1;
}

void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Essa pilha está vazia!" << endl;
        return;
    }

    cout << "Começo da pilha (LIFO):" << endl;
    for (int i = stack->top; i >= 0; i--)
    {
        cout << stack->data[i] << endl;
    }

    cout << "Final da pilha (LIFO)" << endl;
}