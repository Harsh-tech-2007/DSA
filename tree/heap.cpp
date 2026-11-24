#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Restore Max Heap property downward
    void heapifyDown(int i) {

        int n = heap.size();
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && heap[left] > heap[largest]) {
            largest = left;
        }

        if(right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Restore Max Heap property upward
    void heapifyUp(int i) {

        while(i > 0) {

            int parent = (i - 1) / 2;

            if(heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else {
                break;
            }
        }
    }

public:

    // INSERTION
    void insert(int val) {

        heap.push_back(val);

        int i = heap.size() - 1;

        heapifyUp(i);
    }

    // DELETE ROOT (MAXIMUM ELEMENT)
    void deleteRoot() {

        if(heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Deleted element: " << heap[0] << endl;

        heap[0] = heap.back();

        heap.pop_back();

        if(!heap.empty()) {
            heapifyDown(0);
        }
    }

    // SEARCH
    bool search(int key) {

        for(int i = 0; i < heap.size(); i++) {

            if(heap[i] == key) {
                return true;
            }
        }

        return false;
    }

    // GET MAXIMUM
    int getMax() {

        if(heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }

        return heap[0];
    }

    // DISPLAY ARRAY
    void display() {

        if(heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Heap: ";

        for(int x : heap) {
            cout << x << " ";
        }

        cout << endl;
    }

    // BUILD HEAP FROM AN ARRAY
    void buildHeap(vector<int> arr) {

        heap = arr;

        for(int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // HEAP SORT (ascending order)
    void heapSort() {

        vector<int> temp = heap;

        for(int i = temp.size() / 2 - 1; i >= 0; i--) {

            int n = temp.size();

            // Local heapify for sorting
            auto down = [&](auto&& self, int index, int size) -> void {

                int largest = index;
                int left = 2 * index + 1;
                int right = 2 * index + 2;

                if(left < size && temp[left] > temp[largest])
                    largest = left;

                if(right < size && temp[right] > temp[largest])
                    largest = right;

                if(largest != index) {
                    swap(temp[index], temp[largest]);
                    self(self, largest, size);
                }
            };

            down(down, i, n);
        }

        for(int i = temp.size() - 1; i > 0; i--) {

            swap(temp[0], temp[i]);

            auto down = [&](auto&& self, int index, int size) -> void {

                int largest = index;
                int left = 2 * index + 1;
                int right = 2 * index + 2;

                if(left < size && temp[left] > temp[largest])
                    largest = left;

                if(right < size && temp[right] > temp[largest])
                    largest = right;

                if(largest != index) {
                    swap(temp[index], temp[largest]);
                    self(self, largest, size);
                }
            };

            down(down, 0, i);
        }

        cout << "Sorted Array: ";

        for(int x : temp) {
            cout << x << " ";
        }

        cout << endl;
    }
};

int main() {

    MaxHeap h;

    int choice, val;

    do {

        cout << "\n----- MAX HEAP MENU -----\n";

        cout << "1. Insert\n";
        cout << "2. Delete Root\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Get Maximum\n";
        cout << "6. Build Heap from Array\n";
        cout << "7. Heap Sort\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter value: ";
                cin >> val;
                h.insert(val);
                break;

            case 2:
                h.deleteRoot();
                break;

            case 3:
                h.display();
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> val;

                if(h.search(val))
                    cout << "Element found!\n";
                else
                    cout << "Element not found!\n";

                break;

            case 5:
                cout << "Maximum element: " << h.getMax() << endl;
                break;

            case 6: {
                int n, x;
                vector<int> arr;

                cout << "Enter number of elements: ";
                cin >> n;

                cout << "Enter elements: ";

                for(int i = 0; i < n; i++) {
                    cin >> x;
                    arr.push_back(x);
                }

                h.buildHeap(arr);

                cout << "Heap created successfully!\n";
                break;
            }

            case 7:
                h.heapSort();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}
