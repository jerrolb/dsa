#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

class stack
{
    int *arr;
    int top;
    int capacity;

public:
    stack(int size = SIZE); // constructor
    ~stack(); // destructor

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize stack
stack::stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

// Destructor to free memory allocated to the stack
stack::~stack()
{
    delete arr;
}

void stack::push(int x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

int stack::pop()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

int stack::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

int stack::size()
{
    return top + 1;
}

bool stack::isEmpty()
{
    return top == -1;
    // return size() == 0;
}

bool stack::isFull()
{
    return top == capacity - 1;
    // return size() == capacity;
}

int main()
{
    stack pt(3);
    pt.push(1);
    pt.push(2);
    pt.pop();
    pt.pop();
    pt.push(3);
    cout << "Top element is: " << pt.peek() << endl;
    cout << "Stack size is " << pt.size() << endl;
    pt.pop();

    if (pt.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";

    return 0;
}

// Inserting 1
// Inserting 2
// Removing 2
// Removing 1
// Inserting 3
// Top element is: 3
// Stack size is 1
// Removing 3
// Stack Is Empty
