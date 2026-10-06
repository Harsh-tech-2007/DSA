#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LL_stack
{
public:
    Node *head;

    LL_stack()
    {
        head = nullptr;
    }

    void push(int d)
    {
        Node *temp = new Node(d);

        temp->next = head;
        head = temp;
    }

    int pop()
    {
        if (isempty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        Node *temp = head;
        int pop_ele = temp->data;

        head = head->next;

        delete temp;

        return pop_ele;
    }

    bool isempty()
    {
        return head == nullptr;
    }

    void display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    LL_stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.pop();

    st.display();

    return 0;
}