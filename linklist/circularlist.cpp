#include <iostream>
using namespace std;

// Node class
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

class circularlist
{

    Node *head;
    Node *tial;

    circularlist(){
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int d){

        if (head == nullptr)
        {
            Node *temp = new Node(d);

            head = temp;
            tial = temp;
            tail->next = head;
        }
        else
        {
              Node *temp = new Node(d);
              temp->next = head;
              head = temp;
              tail->next = head;
        }
    }
};

int main(){


}