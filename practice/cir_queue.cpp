#include <iostream>
using namespace std;

template <typename T>

class cir_queue
{
private:
    T *Q;
    int capacity;
    int front;
    int rear;

public:
    cir_queue(int c=10){
        capacity = c;
        Q = new T[capacity];
        front = -1;
        rear = -1;
    };
    ~cir_queue(){
        delete[] Q;
    };
    
    void enqueue(T data)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        // First element
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }

        Q[rear] = data;
    }

};

