#include <iostream>
using namespace std;

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

        front = -1;
        rear = -1;
    }

    ~My_Queue()
    {
        delete[] Q;
    }

    void enqueue(T data){
      
        if((rear == capacity-1 && front==0) || rear==(front-1)%(size-1)){
            cout << "Queue is full" << endl;
            return;
        }
        else if(front==-1){
            front = rear = 0;
            Q[rear] = data;
        }
        else if(rear==size-1 && front!=0){
            rear = 0;
            Q[rear] = data;
        }
        else{
            rear++;
            Q[rear] = data;
        }
    }

}
