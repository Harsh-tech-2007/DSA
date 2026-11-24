#include <iostream>
#include<vector>
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

    bool isfull(){
        return top == capacity - 1;
    }

    bool isEmpty(){
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return s[top];
    }
}






