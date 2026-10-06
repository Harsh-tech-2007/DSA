#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int d) {
        Node *temp = new Node(d);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertAtEnd(int d) {
        Node *temp = new Node(d);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insertAtPos(int d, int P) {
        if (P < 0 || P > len()) {
            cout << "Please enter a valid index" << endl;
            return;
        }

        if (P == 0) {
            insertAtHead(d);
            return;
        }

        if (P == len()) {
            insertAtEnd(d);
            return;
        }

        Node *curr = head;
        // Traverse to the node just before the insertion point
        for (int i = 0; i < P - 1; i++) {
            curr = curr->next;
        }
        
        Node *temp = new Node(d);

        temp->next = curr->next;
        temp->prev = curr;
        curr->next->prev = temp;
        curr->next = temp;
    }

    void deleteAtHead() {
        if (head == nullptr) {
            return;
        }
        
        Node *temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;

        } else {
            // If the list is now empty, tail should also be null
            tail = nullptr; 
        }

        delete temp;
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } 
        else {
            // If the list is now empty, head should also be null
            head = nullptr; 
        }

        delete temp;
    }

    void deleteAtPos(int P) {
        if (P < 0 || P >= len()) {
            cout << "Please enter a valid index" << endl;
            return;
        }

        if (P == 0) {
            deleteAtHead();
            return;
        }

        if (P == len() - 1) {
            deleteAtEnd();
            return;
        }

        Node *curr = head;
        // Traverse exactly to the node to be deleted
        for (int i = 0; i < P; i++) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
     
    void reverse(){

    }

    Node *search(int x) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    int len() {
        Node *temp = head;
        int l = 0;
        while (temp != nullptr) {
            temp = temp->next;
            l++;
        }
        return l;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtHead(50);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    
    // List is currently: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
    list.insertAtPos(100, 3); // Inserts 100 at index 3
    list.deleteAtHead();      // Removes 10
    list.insertAtPos(100, 1); // Inserts 100 at index 1
    
    list.display();
    return 0;
}