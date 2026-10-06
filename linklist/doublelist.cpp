#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }


    void insertAtHead(int d)
    {

        Node *temp = new Node(d);

        if (head == nullptr)
        {

            head = temp;
            tail = temp;
        }
        else
        {

            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertAtPos(int d, int P)
    {
        if(P==0){
            insertAtHead(d);
        }
        int i = 1;
        Node *curr = head;
        while (i < P)
        {
            curr = curr->next;
            i++;
        }
        Node *nxt = curr->next;
        Node *temp = new Node(d);

        curr->next = temp;
        nxt->prev = temp;
        temp->prev = curr;
        temp->next = nxt;
    }
 
    void insertAtPos(int d,int P){
           
        
    }

    void insertAtEnd(int d){

        Node *temp = new Node(d);

        if(head==nullptr){
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void deleteAtHead(){

        if (head==nullptr){
            return;
        }
        Node *temp = head;
        
        head = head->next;

        delete temp;
    }
    void display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
    

    int len()
    {
        Node *temp = head;
        int l = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            l++;
        }

        return l;
    }

};

int main()
{
    DoublyLinkedList list;
    list.insertAtHead(50);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtPos(100, 3);
    list.deleteAtHead();
    list.insertAtPos(100, 1);
    list.display();
}
