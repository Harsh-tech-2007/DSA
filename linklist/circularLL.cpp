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
    Node *tail;

public:
    circularlist()
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

            // Circular connection
            tail->next = head;
        }
        else
        {
            temp->next = head;
            head = temp;

            tail->next = head;
        }
    }

    void insertAtEnd(int d)
    {
        Node *temp = new Node(d);

        if (head == nullptr)
        {
            head = temp;
            tail = temp;

            tail->next = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;

            tail->next = head;
        }
    }

    void insertAtPos(int d, int P)
    {
        if (P < 0 || P > len())
        {
            cout << "Invalid position\n";
            return;
        }

        // Position 0 = insert at head
        if (P == 0)
        {
            insertAtHead(d);
            return;
        }

        // Position at end
        if (P == len())
        {
            insertAtEnd(d);
            return;
        }

        Node *curr = head;

        for (int i = 0; i < P - 1; i++)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);

        temp->next = curr->next;
        curr->next = temp;
    }

    void deleteAtHead()
    {
        if (head == nullptr)
        {
            return;
        }

        // Only one node
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *temp = head;

        head = head->next;
        tail->next = head;

        delete temp;
    }

    void deleteAtTail()
    {
        if (head == nullptr)
        {
            return;
        }

        // Only one node
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *curr = head;

        // Find node before tail
        while (curr->next != tail)
        {
            curr = curr->next;
        }

        curr->next = head;

        delete tail;

        tail = curr;
    }
    
    void deleteAtPos(int P)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }

    if (P < 0 || P >= len())
    {
        cout << "Invalid position\n";
        return;
    }

    // Delete head
    if (P == 0)
    {
        deleteAtHead();
        return;
    }

    // Delete tail
    if (P == len() - 1)
    {
        deleteAtTail();
        return;
    }

    Node *curr = head;

    // Reach node before the position
    for (int i = 0; i < P - 1; i++)
    {
        curr = curr->next;
    }

    Node *temp = curr->next;

    curr->next = temp->next;

    delete temp;
}
    
    // Search a value
    void search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *curr = head;
        int pos = 0;

        do
        {
            if (curr->data == key)
            {
                cout << "Element found at position: " << pos << endl;
                return;
            }

            curr = curr->next;
            pos++;

        } while (curr != head);

        cout << "Element not found\n";
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *curr = head;

        do
        {
            cout << curr->data << " ";
            curr = curr->next;

        } while (curr != head);

        cout << endl;
    }

    int len()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node *curr = head;

        do
        {
            count++;
            curr = curr->next;
        } while (curr != head);

        return count;
    }
};

int main()
{
    circularlist l;

    l.insertAtHead(20);
    l.insertAtHead(10);
    l.insertAtEnd(30);
    l.insertAtEnd(40);

    l.print();

    l.insertAtPos(25, 2);

    l.print();

    l.deleteAtHead();

    l.print();

    l.deleteAtTail();

    l.print();

    return 0;
}