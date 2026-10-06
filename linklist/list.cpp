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

class Linkedlist
{
public:
    Node *head;
    Node *tail;

    Linkedlist()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int d)
    {

        // Empty list
        if (head == nullptr)
        {
            Node *temp = new Node(d);

            head = temp;
            tail = temp;
        }

        // Non-empty list
        else
        {
            Node *temp = new Node(d);

            temp->next = head;
            head = temp;
        }
    }

    void insertAtTail(int d)
    {

        // Empty list
        if (head == nullptr)
        {
            Node *temp = new Node(d);

            head = temp;
            tail = temp;
        }

        // Non-empty list
        else
        {
            Node *temp = new Node(d);

            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtPos(int d, int P)
    {

        int i = 1;

        Node *temp = head;
        while (i < P)
        {
            temp = temp->next;
            i++;
        }

        Node *nxt = temp->next;

        Node *new_node = new Node(d);
        temp->next = new_node;
        new_node->next = nxt;
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

    void deletionAtHead()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;

        delete temp;
    }

    void deletionAtTail()
    {
        Node *temp = tail;
    }

    void deleteNode(int P)
    {

        int i = 1;
        Node *curr = head;

        // Delete head
        if (P == 1)
        {
            head = head->next;
            delete curr;
            return;
        }

        while (i < P)
        {
            curr = curr->next;
            i++;
        }

        Node *temp = curr->next;
        Node *nxt = temp->next;

        curr->next = nxt;

        delete temp;
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

    void reverse(){

        Node *curr = head;
        Node *nxt = head->next;
        Node *prev = nullptr;
        while (curr!=nullptr)
        {

            curr->next = prev;
            nxt->data = curr;

            prev=curr
            curr = next;
            
        }
    }
};

int main()
{

    Linkedlist list;

    list.insertAtTail(10);
    list.insertAtHead(20);
    list.insertAtHead(1);
    list.insertAtTail(100);
    list.insertAtPos(800, 3);
    list.deleteNode(3);

    list.display();
    cout << "length:" << list.len();

    return 0;
}