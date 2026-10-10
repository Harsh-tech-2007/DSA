#include <iostream>
using namespace std;


// enqueue(),dequeue(),peek() / front(),isEmpty(),isFull(),size()

template <typename T>
class My_Queue
{
private:
    T *Q;
    int capacity;
    int front;
    int rear;

public:

    My_Queue(int c = 10)
    {
        capacity = c;
        Q = new T[capacity];

        front = 0;
        rear = 0;
    }

    ~My_Queue()
    {
        delete[] Q;
    }

    void enqueue(T data)
    {
        if (rear == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }

        Q[rear] = data;
        rear++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }

        T ans = Q[front];

        front++;

        if (front == rear)         // Important part
        {
            front = 0;
            rear = 0;
        }

        return ans;
    }

    T Front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return T();
        }

        return Q[front];
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i < rear; i++)
        {
            cout << Q[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    My_Queue<int> Q;

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);

    Q.display();

    cout << "Front: " << Q.Front() << endl;

    cout << "Dequeued: " << Q.dequeue() << endl;

    Q.display();
}