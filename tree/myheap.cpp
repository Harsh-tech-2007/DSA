#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    heap(){
        size = -1;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while (index>0)
        {
            int parent = (index - 1) / 2;

            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);
            }
        }
    }
};
