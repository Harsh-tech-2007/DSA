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

    // 1. Insert at beginning
    void insertAtHead(int d)
    {
        Node *newNode = new Node(d);

        // Empty list
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // 2. Insert at ith position
    void insertAtPos(int d, int P)
    {
        // Invalid position
        if (P < 1 || P > len() + 1)
        {
            cout << "Invalid position\n";
            return;
        }

        // Position 1 = insert at head
        if (P == 1)
        {
            insertAtHead(d);
            return;
        }

        // Position at end
        if (P == len() + 1)
        {
            insertAtTail(d);
            return;
        }

        Node *curr = head;

        // Reach node at position P-1
        for (int i = 1; i < P - 1; i++)
        {
            curr = curr->next;
        }

        Node *newNode = new Node(d);

        newNode->next = curr->next;
        curr->next = newNode;
    }

    // 3. Insert at end
    void insertAtTail(int d)
    {
        Node *newNode = new Node(d);

        // Empty list
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 4. Remove from beginning
    void deletionAtHead()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        head = head->next;

        // List became empty
        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete temp;
    }

    // 5. Remove from ith position
    void deleteNode(int P)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        if (P < 1 || P > len())
        {
            cout << "Invalid position\n";
            return;
        }

        // Delete head
        if (P == 1)
        {
            deletionAtHead();
            return;
        }

        Node *curr = head;

        // Reach P-1 node
        for (int i = 1; i < P - 1; i++)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;

        curr->next = temp->next;

        // Deleted last node
        if (temp == tail)
        {
            tail = curr;
        }

        delete temp;
    }

    void deleteNodeFromEnd(int P)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        int n = len();

        if (P < 1 || P > n)
        {
            cout << "Invalid position\n";
            return;
        }

        // If deleting the head
        if (P == n)
        {
            deletionAtHead();
            return;
        }

        int idx = n - P;

        Node *curr = head;

        // Move to node before the node we want to delete
        for (int i = 0; i < idx - 1; i++)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;

        curr->next = temp->next;

        delete temp;
    }
    // 6. Remove from end
    void deletionAtTail()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
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

        // Reach second-last node
        while (curr->next != tail)
        {
            curr = curr->next;
        }

        delete tail;

        tail = curr;
        tail->next = nullptr;
    }

    // 7. Search for element
    // Returns pointer to the node
    Node *search(int x)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return temp;
            }

            temp = temp->next;
        }

        return nullptr;
    }

    // 8. Reverse linked list
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;

        // Old head becomes new tail
        tail = head;

        while (curr != nullptr)
        {
            Node *nxt = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        head = prev;
    }

    // 9. Create ordered linked list
    // Ascending order
    void insertOrdered(int d)
    {
        Node *newNode = new Node(d);

        // Empty list
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        // Insert before head
        if (d <= head->data)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *curr = head;

        // Find correct position
        while (curr->next != nullptr &&
               curr->next->data < d)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        // Inserted at end
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }

    // 10. Merge two linked lists
    // Creates a new list containing both lists
    static Linkedlist merge(Linkedlist &list1, Linkedlist &list2)
    {
        Linkedlist result;

        Node *temp = list1.head;

        while (temp != nullptr)
        {
            result.insertAtTail(temp->data);
            temp = temp->next;
        }

        temp = list2.head;

        while (temp != nullptr)
        {
            result.insertAtTail(temp->data);
            temp = temp->next;
        }

        return result;
    }

    // Length
    int len()
    {
        int l = 0;

        Node *temp = head;

        while (temp != nullptr)
        {
            l++;
            temp = temp->next;
        }

        return l;
    }

    // Display
    void display()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }


    //leetcode 203
    void removeElements(int val)
    {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {

            if (curr->data == val)
            {

                if (curr == head)
                {
                    Node *temp = curr;
                    curr = curr->next;

                    head = curr;
                    delete temp;
                }

                else
                {
                    Node *temp = curr;
                    prev->next = curr->next;

                    curr = prev->next;
                    delete temp;
                }
            }

                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    };

    // ================= MAIN =================

    int main()
    {
        Linkedlist list;

        // Insert at head
        list.insertAtTail(10);
        list.insertAtTail(10);
        list.insertAtTail(10);
        list.insertAtTail(10);
        list.insertAtTail(10);
        list.insertAtTail(10);
        list.insertAtTail(70);
        list.display();
        list.removeElements(10);
        list.display();

        return 0;
    }