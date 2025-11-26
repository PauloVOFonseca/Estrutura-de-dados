#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

struct Stack
{
    int total;
    Node *top;
};

Stack initializeStack();
void push(Stack &stack, int value);
void pop(Stack &stack);
void printStack(Stack &stack);
bool isEmpty(Stack &stack);

int main()
{
    Stack stack = initializeStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printStack(stack);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    printStack(stack);
    return 0;
}

Stack initializeStack()
{
    return Stack{0, nullptr};
}

void push(Stack &stack, int value)
{
    stack.total++;
    stack.top = new Node{value, stack.top};
}

void pop(Stack &stack)
{
    if (isEmpty(stack)) return;

    stack.total--;
    Node *oldTop = stack.top;
    stack.top = stack.top->next;
    delete oldTop;
}

void printStack(const Stack &stack)
{
    Node *cur = stack.top;
    for (int i = 0; i < stack.total; i++)
    {
        cout << cur->value << endl;
        cur = cur->next;
    }
}

bool isEmpty(Stack &stack) {
    return stack.top == nullptr;
}