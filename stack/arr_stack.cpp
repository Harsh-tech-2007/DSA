#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *s;
    int capacity;
    int top;

public:
    Stack(int c = 10)
    {
        capacity = c;
        s = new T[capacity];
        top = -1;
    }
    ~Stack()
    {
        delete[] s;
    }
     
    //push
    void push(T ele)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        s[top] = ele;
    }

    // Pop
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return T();
        }

        T ele = s[top];
        top--;

        return ele;
    }
     
    // Check empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check full
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Size
    int size()
    {
        return top + 1;
    }
     

    // Display
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << s[i] << " ";
        }

        cout << endl;
    }

    // Peek
    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return s[top];
    }

};