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

class LL_Queue
{
private:
    Node *head;
    Node *tail;

public:
    LL_Queue(){
       head = nullptr;
       tail = nullptr;
    }

    void enqueue(int d){
        Node *temp = new Node(d);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }

        tail->next = temp;
        tail = temp;
    }

    int dequeue(){
        
        if(tail==nullptr){
            return -1;
        }
        Node *temp = head;
        int ans = temp->data;
        head = head->next;

        delete temp;

        return ans;
    }

    void display(){

        Node *temp = head;

        while (temp!=nullptr)
        {
            cout << temp->data<<"-";
            temp = temp->next;
        }

        cout << "NULL";
        cout << endl;
    }
};

int main(){

    LL_Queue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.display();
    Q.dequeue();
    Q.display();

    return 0;
}
