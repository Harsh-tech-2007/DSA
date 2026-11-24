#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
}; // <-- Added semicolon

template<typename T> // <-- Added template declaration for ll_stack
class ll_stack
{
private:
    Node<T>* head; // <-- Declared head pointer

public:
    ll_stack()
    {
        head = nullptr;
    }

    ~ll_stack() // <-- Destructor to prevent memory leaks
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T val)
    {
        Node<T>* temp = new Node<T>(val);
        temp->next = head;
        head = temp;
    }

    T pop()
    {
        if (isEmpty()) // <-- Fixed capitalization
        {
            cout << "Stack Underflow\n";
            return T(); // <-- Safe default return for any type T
        }

        Node<T>* temp = head;
        T pop_ele = temp->data;

        head = head->next;
        delete temp;

        return pop_ele;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    T peek()
    {
        if (isEmpty()) // <-- Fixed capitalization
        {
            cout << "Stack Underflow\n";
            return T();
        }
        return head->data;
    }

    void display()
    {
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}; // <-- Added semicolon

int main()
{
    ll_stack<int> st; // <-- Matched class name and added <int>

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();

    st.display(); // Output: 30 -> 20 -> 10 -> NULL



    return 0;


    
}