#include <iostream>
using namespace std;

template <typename T>
class My_Queue
{
private:

    class Node
    {
    public:
        T data;
        Node *next;

        Node(T value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node *front;
    Node *rear;

public:

    // Constructor
    My_Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor
    ~My_Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Add element
    void enqueue(T data)
    {
        Node *temp = new Node(data);

        // Queue is empty
        if (front == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    // Remove element
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }

        Node *temp = front;

        T data = temp->data;

        front = front->next;

        // Queue becomes empty
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        return data;
    }

    // Get front element
    T getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }

        return front->data;
    }

    // Get rear element
    T getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }

        return rear->data;
    }

    // Display queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *curr = front;

        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};


int main()
{
    My_Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    cout << "Deleted: " << q.dequeue() << endl;
    cout << "Deleted: " << q.dequeue() << endl;

    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    return 0;
}