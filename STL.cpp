#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<utility>
#include<list>
using namespace std;

void pair_example(){
    pair<int,int> p1 = make_pair(1,2);
    pair<int,int> p2 = {3,4};
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    
    pair<int,pair<int,int>> p3 = {5,{6,7}};
    cout << p3.first << " " << p3.second.first << " " << p3.second.second << endl;    
    
    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    cout << arr[0].first << " " << arr[0].second << endl;
    cout << arr[1].first << " " << arr[1].second << endl;
    cout << arr[2].first << " " << arr[2].second << endl;

}

void vector_example(){
    vector<int> v(2,4);
    v.push_back(1); //{4,4,1}
    v.emplace_back(29); //{4,4,1,29}

    // cout << "v[0]: " << v[0] << " v[1]: " << v.at(1) << " v[2]: " <<v[2] << " v[3]: " << v[3] << endl; 
    //{4,4,1,29}
     
    vector<pair<int,int>> v1;
    v1.push_back({1,40}); //{(1,40)}
    v1.emplace_back(3,4);//{(1,40),(3,4)}

    // cout << "v1[0].first: " << v1[0].first << " v1[0].second: " << v1[0].second << endl; //{(1,40)}
    // cout << "v1[1].first: " << v1[1].first << " v1[1].second: " << v1[1].second << endl;  //{(3,4)}

    vector<int> v2(v); //{4,4,1,29}

    // cout << "v2[0]: " << v2[0] << " v2[1]: " << v2[1] << " v2[2]: " << v2[2] << " v2[3]: " << v2[3] << endl; //{4,4,1,29}

    vector<int>::iterator it = v.begin(); // points to the first element of the vector v 
    vector<int>::iterator it1 = v.end();  // points to the last element of the vector v (actually one position after the last element)


    // cout << "v.begin(): " << *it << endl;         // points to the first element of the vector v // outputs "4"
    // cout << "v.end(): " << *(--it1) << endl;     // points to the last element of the vector v  // outputs "29"
    // cout<<"v.back(): "<<v.back()<<endl;         // points to the last element of the vector v  // outputs "29"

    // cout <<"v[0]: " << *(it) << endl;                                   //outputs "4"
    // cout <<"v[1]: " << *(it+1) << endl;                                //outputs "4"
    // cout<<"v[0] address using &v[0]: " << &v[0] << endl;              //outputs the address of the first element of the vector v
    // cout<<"v[0] address using v.begin(): " << &(*v.begin()) << endl; //outputs the address of the first element of the vector v
    // cout<<"v[0] address using it: " << &(*it) << endl;              //outputs the address of the first element of the vector v
    // cout<<"v.size(): " << v.size() << endl;                        //outputs the number of elements in the vector v 
    // cout<<"v.capacity(): " << v.capacity() << endl;               //outputs the number of elements that can be stored in the vector v without reallocating memory
    // cout<<"v.max_size(): " << v.max_size() << endl;              //outputs the maximum number of elements that can be stored in the vector v 
    // cout<<"v.empty(): " << v.empty() << endl;                   //outputs whether the vector v is empty or not (0 for false, 1 for true)
    // cout<<"v.at(2): " << v.at(2) << endl;                      //outputs the element at index 2 of the vector v // outputs "1"
    // cout<<"v.clear(): "<<v.clear()<<endl;                     // clears the vector and makes it empty {}


    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;
    // for(auto it = v.begin(); it != v.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;
    
    // for(auto it : v){
    //     cout << it << " ";
    // }
    // cout << endl;

    vector<int> v3;
    v3.assign({1, 2, 3, 4, 5});


    v3.erase(v3.begin()+1); //{1, 3, 4, 5}
    v3.erase(v3.begin()+1, v3.begin()+3);  //{1, 5}
    v3.emplace(v3.begin()+1, 100); //{1, 100, 5}
    v3.insert(v3.begin()+2, 200);  //{1, 100, 200, 5}
    v3.insert(v3.begin()+3, {300,400,500});  //{1, 100, 200, 300, 400, 500, 5}
    v3.insert(v3.end(), {600,700,800});  //{1, 100, 200, 300, 400, 500, 5, 600, 700, 800}
    v3.insert(v3.begin()+2, 2, 0); //{1, 100, 0, 0, 200, 300, 400, 500, 5, 600, 700, 800} 
    v3.pop_back(); //{1, 100,0,0 200, 300, 400, 500, 5, 600, 700}
    // v3.clear(); -- // clears the vector and makes it empty {}
    // v3.resize(5);-- resizes the vector to 5 elements {1, 100, 0, 0, 200 }
    // v3.resize(14, 0);  //-- resizes the vector to 10 elements and fills the new elements with 0 -- {1, 100, 0, 0, 200, 300, 400, 500, 5, 600, 700, 0, 0, 0}
    // v3.reserve(20);  //-- reserves space for 20 elements in the vector --{1, 100, 0, 0, 200, 300, 400, 500, 5, 600, 700}
    
    //v2 --{4, 4, 1, 29}
    //v3 --{1, 100, 0, 0, 200, 300, 400, 500, 5, 600, 700}
    v3.swap(v2); //v2 --{1, 100, 0, 0, 200, 300, 400, 500, 5, 600, 700} v3 --{4, 4, 1, 29}

    
    for(auto it : v3){
        cout << it << " ";
    }
    cout << endl;


    //important functions of vector
    // v.size() -- returns the number of elements in the vector
    // v.capacity() -- returns the number of elements that can be stored in the vector without reallocating memory
    // v.max_size() -- returns the maximum number of elements that can be stored in the vector
    // v.empty() -- returns whether the vector is empty or not   
    // v.at(i) -- returns the element at index i of the vector
    // v.clear() -- clears the vector and makes it empty
    // v.resize(n) -- resizes the vector to n elements
    // v.resize(n, val) -- resizes the vector to n elements and fills the new elements with val
    // v.reserve(n) -- reserves space for n elements in the vector
    // v.swap(v2) -- swaps the contents of the vector with another vector v2
    // v.insert(pos, val) -- inserts the element val at position pos in the vector
    // v.insert(pos, n, val) -- inserts n copies of the element val at position pos in the vector
    // v.insert(pos, {val1, val2, val3}) -- inserts the elements val1, val2, val3 at position pos in the vector
    // v.erase(pos) -- erases the element at position pos in the vector
    // v.erase(pos1, pos2) -- erases the elements from position pos1 to pos2 in the vector example: v.erase(v.begin()+1, v.begin()+3) -- erases the elements at index 1 and 2 in the vector
    // v.push_back(val) -- adds the element val at the end of the vector
    // v.emplace_back(val) -- adds the element val at the end of the vector (more efficient than push_back)
    // v.pop_back() -- removes the last element of the vector
    // v.push_front(val) -- adds the element val at the beginning of the vector
    // v.emplace_front(val) -- adds the element val at the beginning of the vector (more efficient than push_front)
    // v.pop_front() -- removes the first element of the vector
    // v.assign({val1, val2, val3}) -- assigns the elements val1, val2, val3 to the vector
    // v.assign(n, val) -- assigns n copies of the element val to the vector
    // v.begin() -- returns an iterator to the first element of the vector
    // v.end() -- returns an iterator to the last element of the vector (actually one position after the last element)
    // v.back() -- returns the last element of the vector
    // v.front() -- returns the first element of the vector
    // v.data() -- returns a pointer to the underlying array of the vector
    // v.at(i) -- returns the element at index i of the vector
    // v.size() -- returns the number of elements in the vector
    // v.capacity() -- returns the number of elements that can be stored in the vector without reallocating memory
    // v.max_size() -- returns the maximum number of elements that can be stored in the vector 
    // v.empty() -- returns whether the vector is empty or not
    // v.clear() -- clears the vector and makes it empty

}

void list_example(){

    list<int> l;
    l.push_back(1); //{1}
    l.push_front(2); //{2, 1}
    l.emplace_back(3); //{2, 1, 3}
    l.emplace_front(4); //{4, 2, 1, 3}

    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;

    l.pop_back(); //{4, 2, 1}
    l.pop_front(); //{2, 1}

    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;

    l.remove(2); //{1}

    for(auto it : l){
        cout << it << " ";
    }
    cout << endl;

    //important functions of list
    // l.push_back(val) -- adds the element val at the end of the list
    // l.push_front(val) -- adds the element val at the beginning of the list
    // l.emplace_back(val) -- adds the element val at the end of the list (more efficient than push_back)
    // l.emplace_front(val) -- adds the element val at the beginning of the list (more efficient than push_front)
    // l.pop_back() -- removes the last element of the list
    // l.pop_front() -- removes the first element of the list
    // l.remove(val) -- removes all occurrences of the element val from the list
    // l.clear() -- clears the list and makes it empty
    // l.size() -- returns the number of elements in the list
    // l.empty() -- returns whether the list is empty or not
    // l.begin() -- returns an iterator to the first element of the list
    // l.end() -- returns an iterator to the last element of the list (actually one position after the last element)
    // l.front() -- returns the first element of the list 
    // l.back() -- returns the last element of the list
    // l.sort() -- sorts the elements of the list in ascending order 
    // l.reverse() -- reverses the order of the elements in the list
    // l.merge(l2) -- merges the elements of the list l2 into the list l (both lists must be sorted)
    // l.unique() -- removes all consecutive duplicate elements from the list
    // l.splice(pos, l2) -- transfers all elements from the list l2 to the list l at position pos example: l.splice(l.begin(), l2) -- transfers all elements from the list l2 to the list l at the beginning of the list l
    // l.splice(pos, l2, it) -- transfers the element pointed to by the iterator it from the list l2 to the list l at position pos example: l.splice(l.begin(), l2, l2.begin()) -- transfers the first element of the list l2 to the list l at the beginning of the list l
    // l.splice(pos, l2, it1, it2) -- transfers the elements in the range [it1, it2) from the list l2 to the list l at position pos example: l.splice(l.begin(), l2, l2.begin(), l2.end()) -- transfers all elements from the list l2 to the list l at the beginning of the list l
    // l.insert(pos, val) -- inserts the element val at position pos in the list
    // l.insert(pos, n, val) -- inserts n copies of the element val at position pos in the list
    // l.insert(pos, {val1, val2, val3}) -- inserts the elements val1, val2, val3 at position pos in the list
    // l.erase(pos) -- erases the element at position pos in the list
    // l.erase(pos1, pos2) -- erases the elements from position pos1 to pos2 in the list example: l.erase(l.begin(), l.end()) -- erases all elements from the list
    // l.assign({val1, val2, val3}) -- assigns the elements val1, val2, val3 to the list
    // l.assign(n, val) -- assigns n copies of the element val to the list
    // l.resize(n) -- resizes the list to n elements
    // l.resize(n, val) -- resizes the list to n elements and fills the new elements with val
    // l.swap(l2) -- swaps the contents of the list with another list l2
    // l.remove_if(pred) -- removes all elements from the list that satisfy the predicate pred
    // l.unique(pred) -- removes all consecutive duplicate elements from the list that satisfy the predicate pred
    // l.sort(pred) -- sorts the elements of the list in ascending order according to the predicate pred
    // l.merge(l2, pred) -- merges the elements of the list l2 into the list l according to the predicate pred (both lists must be sorted according to the predicate pred)
    // pred - a predicate is a function that takes an element of the list as input and returns a boolean value (true or false) indicating whether the element satisfies a certain condition. For example, a predicate can be used to sort the elements of the list in descending order, or to remove all even numbers from the list.
    // l.splice(pos, l2, it, pred) -- transfers the elements in the range [it, it2) from the list l2 to the list l at position pos according to the predicate pred
    // l.splice(pos, l2, it1, it2, pred) -- transfers the elements in the range [it1, it2) from the list l2 to the list l at position pos according to the predicate pred
    // l.merge(l2, pred) -- merges the elements of the list l2 into the list l according to the predicate pred (both lists must be sorted according to the predicate pred)
}

void Deque_example(){

    deque<int> d;
    d.push_back(1); //{1}
    d.push_front(2); //{2, 1}
    d.emplace_back(3); //{2, 1, 3}
    d.emplace_front(4); //{4, 2, 1, 3}

    for(auto it : d){
        cout << it << " ";
    }
    cout << endl;

    d.pop_back(); //{4, 2, 1}
    d.pop_front(); //{2, 1}

    for(auto it : d){
        cout << it << " ";
    }
    cout << endl;

    d.erase(d.begin()+1); //{2}

    for(auto it : d){
        cout << it << " ";
    }
    cout << endl;
    
    //important functions of deque
    //same as vector but with push_front, pop_front, emplace_front, and erase(pos) functions 
    // unlike vector, deque allows for fast insertion and deletion at both the front and back of the container.
    // deque is implemented as a dynamic array of arrays, which allows for efficient random access to elements,but can be slower than vector for certain operations such as inserting or deleting elements in the middle of the container.


}

void Stack_example(){

    stack<int> s;
    s.push(1); //{1}
    s.push(2); //{1, 2}
    s.emplace(3); //{1, 2, 3}

    cout << "Top element: " << s.top() << endl; //outputs "3"
    cout << "Size of stack: " << s.size() << endl; //outputs "3"

    s.pop(); //{1, 2}

    cout << "Top element after pop: " << s.top() << endl; //outputs "2"

    cout << "Size of stack: " << s.size() << endl; //outputs "2"

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; //outputs "No"
    
   
    // stack is a container adapter that gives the programmer the functionality of a stack - specifically,
    // a LIFO (last-in, first-out) data structure. The class is implemented as a template class, so that 
    //it can be used to create stacks of any type. The underlying container may be any of the standard 
    //container classes or some other specifically designed container class. The default underlying container
    // class is deque, but vector and list are also commonly used.
     
    //important functions of stack
    // s.push(val) -- adds the element val at the top of the stack
    // s.emplace(val) -- adds the element val at the top of the stack (more efficient than push)
    // s.pop() -- removes the top element of the stack
    // s.top() -- returns the top element of the stack
    // s.size() -- returns the number of elements in the stack
    // s.empty() -- returns whether the stack is empty or not 
    // s.swap(s2) -- swaps the contents of the stack with another stack s2
    // s.last() -- returns the last element of the stack (same as top())
    // s.first() -- returns the first element of the stack (not applicable for stack, but can be used with underlying container)
    // s.clear() -- clears the stack and makes it empty
    // s.assign({val1, val2, val3}) -- assigns the elements val1, val2, val3 to the stack
    // s.assign(n, val) -- assigns n copies of the element val to the stack

}

void Queue_example(){

    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1, 2}
    q.emplace(3); //{1, 2, 3}

    cout << "Front element: " << q.front() << endl; //outputs "1"
    cout << "Back element: " << q.back() << endl; //outputs "3"

    q.pop(); //{2, 3}

    cout << "Front element after pop: " << q.front() << endl; //outputs "2"
    cout << "Back element after pop: " << q.back() << endl; //outputs "3"

    cout << "Size of queue: " << q.size() << endl; //outputs "2"

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; //outputs "No"
    
   
    // queue is a container adapter that gives the programmer the functionality of a queue - specifically,
    // a FIFO (first-in, first-out) data structure. The class is implemented as a template class, so that 
    //it can be used to create queues of any type. The underlying container may be any of the standard 
    //container classes or some other specifically designed container class. The default underlying container
    // class is deque, but list is also commonly used.
}

void PriorityQueue_example(){

    priority_queue<int> pq;
    pq.push(1); //{1}
    pq.push(2); //{2, 1}
    pq.emplace(3); //{3, 2, 1}
    pq.emplace(0); //{3, 2, 1, 0}

    
    cout << "Top element: " << pq.top() << endl; //outputs "3"

    pq.pop(); //{2, 1, 0}

    cout << "Top element after pop: " << pq.top() << endl; //outputs "2"

    cout << "Size of priority queue: " << pq.size() << endl; //outputs "2"
    
    cout << "Is priority queue empty? " << (pq.empty() ? "Yes" : "No") << endl; //outputs "No"

    // priority_queue is a container adapter that gives the programmer the functionality of a priority queue - specifically,
    // a data structure that allows for efficient retrieval of the largest (or smallest) element.
    // The class is implemented as a template class, so that it can be used to create priority queues of any type.
    // The underlying container may be any of the standard container classes or some other specifically designed container class.
    // The default underlying container class is vector, but deque and list are also commonly used.
    
    //important functions of priority_queue
    // pq.push(val) -- adds the element val to the priority queue
    // pq.emplace(val) -- adds the element val to the priority queue (more efficient than push)
    // pq.pop() -- removes the largest element from the priority queue
    // pq.top() -- returns the largest element from the priority queue
    // pq.size() -- returns the number of elements in the priority queue
    // pq.empty() -- returns whether the priority queue is empty or not
    // pq.swap(pq2) -- swaps the contents of the priority queue with another priority queue pq2


}

void Set_example(){

    set<int> s;
    s.insert(1); //{1}
    s.insert(2); //{1, 2}
    s.emplace(3); //{1, 2, 3}
    s.emplace(0); //{0, 1, 2, 3}

    // set is a container that stores unique elements in shorted order. 

    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    s.erase(2); //{0, 1, 3}

    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    cout << "Size of set: " << s.size() << endl; //outputs "3"
    
    cout << "Is set empty? " << (s.empty() ? "Yes" : "No") << endl; //outputs "No"

    // set is a container that stores unique elements in a specific order. The class is implemented as a template class,
    // so that it can be used to create sets of any type. The underlying container may be any of the standard container classes
    // or some other specifically designed container class. The default underlying container class is a balanced binary search tree.
    
    //important functions of set
    // s.insert(val) -- adds the element val to the set
    // s.emplace(val) -- adds the element val to the set (more efficient than insert)
    // s.erase(val) -- removes the element val from the set
    // s.size() -- returns the number of elements in the set
    // s.empty() -- returns whether the set is empty or not
    // s.swap(s2) -- swaps the contents of the set with another set s2
    // s.find(val) -- returns an iterator to the element val in the set, or s.end() if the element is not found
    // s.count(val) -- returns the number of occurrences of the element val in the set (0 or 1)

}
   
void Multiset_example(){

    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(2); //{1, 2}
    ms.insert(2); //{1, 2, 2}
    ms.emplace(3); //{1, 2, 2, 3}
    ms.emplace(0); //{0, 1, 2, 2, 3}
   
    // multiset allows for duplicate elements, so the element 2 is inserted twice

    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;

    ms.erase(2); //{0, 1, 3}

    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;

    cout << "Size of multiset: " << ms.size() << endl; //outputs "3"
    
    cout << "Is multiset empty? " << (ms.empty() ? "Yes" : "No") << endl; //outputs "No"

    // multiset is a container that stores elements in a specific order and allows for duplicate elements. The class is implemented as a template class,
    // so that it can be used to create multisets of any type. The underlying container may be any of the standard container classes
    // or some other specifically designed container class. The default underlying container class is a balanced binary search tree.
    
    //important functions of multiset
    // same as set but allows for duplicate elements
}

void UnorderedSet_example(){

    unordered_set<int> us;
    us.insert(1); //{1}
    us.insert(2); //{1, 2}
    us.emplace(3); //{1, 2, 3}
    us.emplace(0); //{0, 1, 2, 3}

    // unordered_set is a container that stores unique elements in no particular order. The class is implemented as a template class,
    // so that it can be used to create unordered sets of any type. The underlying container may be any of the standard container classes
    // or some other specifically designed container class. The default underlying container class is a hash table.
    
    for(auto it : us){
        cout << it << " ";
    }
    cout << endl;

    us.erase(2); //{0, 1, 3}

    for(auto it : us){
        cout << it << " ";
    }
    cout << endl;

    cout << "Size of unordered set: " << us.size() << endl; //outputs "3"
    
    cout << "Is unordered set empty? " << (us.empty() ? "Yes" : "No") << endl; //outputs "No"

    //important functions of unordered_set
    // same as set but does not maintain any order of elements
}

void Map_example(){

    map<int, string> m;
    m[1] = "one"; //{(1, "one")}
    m[2] = "two"; //{(1, "one"), (2, "two")}
    m.emplace(3, "three"); //{(1, "one"), (2, "two"), (3, "three")}
    m.insert({0, "zero"}); //{(0, "zero"), (1, "one"), (2, "two"), (3, "three")}

    for(auto it : m){
        cout << it.first << ": " << it.second << endl;
    }

    m.erase(2); //{(0, "zero"), (1, "one"), (3, "three")}

    for(auto it : m){
        cout << it.first << ": " << it.second << endl; // outputs "0: zero", "1: one", "3: three" 
    }
    
    cout<<m[1]<<endl; //outputs "one" because the key 1 is present in the map, so it returns the value associated with the key 1 which is "one"
    cout<<m[3]<<endl; //outputs "three" because the key 3 is present in the map, so it returns the value associated with the key 3 which is "three"


    cout << "Size of map: " << m.size() << endl; //outputs "3"
    
    cout << "Is map empty? " << (m.empty() ? "Yes" : "No") << endl; //outputs "No"

    cout << m.count(1) << endl;  //outputs "1" because the key 1 is present in the map, so it returns the number of occurrences of the key 1 which is 1

     
    if(m.find(1) != m.end()){
        cout << "Key 1 is present in the map" << endl; //outputs "Key 1 is present in the map" because the key 1 is present in the map
        cout << "Value associated with key 1: " << m.find(1)->second << endl;
    }else{    

        cout << "Key 1 is not present in the map" << endl; //outputs "Key 1 is not present in the map" because the key 1 is not present in the map
    }

    // map is a container that stores elements in a specific order and allows for unique keys. The class is implemented as a template class,
    // so that it can be used to create maps of any type. The underlying container may be any of the standard container classes
    // or some other specifically designed container class. The default underlying container class is a balanced binary search tree.
    
    //important functions of map
    // same as set but allows for key-value pairs
}

void UnorderedMap_example(){

    unordered_map<int, string> um;
    um[1] = "one"; //{(1, "one")}
    um[2] = "two"; //{(1, "one"), (2, "two")}
    um.emplace(3, "three"); //{(1, "one"), (2, "two"), (3, "three")}
    um.emplace(0, "zero"); //{(0, "zero"), (1, "one"), (2, "two"), (3, "three")}

    for(auto it : um){
        cout << it.first << ": " << it.second << endl;
    }

    um.erase(2); //{(0, "zero"), (1, "one"), (3, "three")}

    for(auto it : um){
        cout << it.first << ": " << it.second << endl;
    }

    cout << "Size of unordered map: " << um.size() << endl; //outputs "3"
    
    cout << "Is unordered map empty? " << (um.empty() ? "Yes" : "No") << endl; //outputs "No"

    // unordered_map is a container that stores elements in no particular order and allows for unique keys. The class is implemented as a template class,
    // so that it can be used to create unordered maps of any type. The underlying container may be any of the standard container classes
    // or some other specifically designed container class. The default underlying container class is a hash table.
    
    //important functions of unordered_map
    // same as map but does not maintain any order of elements
}

void MultiMap_example(){

    multimap<int, string> mm;

    // mm[1]= "one"; //{(1, "one")} //multimap does not support the [] operator because it allows for duplicate keys, so it cannot guarantee that the key is unique.

    mm.insert({1, "one"}); //{(1, "one")}
    mm.insert({2, "two"}); //{(1, "one"), (2, "two")}
    mm.insert({2, "deux"}); //{(1, "one"), (2, "two"), (2, "deux")}
    mm.emplace(3, "three"); //{(1, "one"), (2, "two"), (2, "deux"), (3, "three")}

    for(auto it : mm){
        cout << it.first << ": " << it.second << endl;
    }
    
     mm.erase(mm.find(2)); // deletes the first element with key 2 -- {(1, "one"), (2, "deux"), (3, "three")}
     mm.erase(2); // deletes all elements with key 2 -- {(1, "one"), (3, "three")} 
    


    for(auto it : mm){
        cout << it.first << ": " << it.second << endl;
    }

    cout << "Size of multimap: " << mm.size() << endl; //outputs "2"
    
    cout << "Is multimap empty? " << (mm.empty() ? "Yes" : "No") << endl; //outputs "No"

    // multimap is a container that stores elements in a specific order and allows for duplicate keys. The class is implemented as a template class,
    // so that it can be used to create multimaps of any type. The underlying container may be any of the standard container classes
    // or some other specifically designed container class. The default underlying container class is a balanced binary search tree.
    
    //important functions of multimap
    // same as map but allows for duplicate keys
}

void algorithm_example(){
 
    vector<int> v = {7,5,3,2,1,4,6};

    // sort the vector in ascending order
    sort(v.begin(), v.end()); //{1, 2, 3, 4, 5, 6, 7}

    // reverse the vector
    sort(v.begin(), v.end(), greater<int>()); //{7, 6, 5, 4, 3, 2, 1}
    reverse(v.begin(), v.end());  //{7, 6, 5, 4, 3, 2, 1}


}
bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
void comparator_example() {
    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    sort(v.begin(), v.end(), comparator);

    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }
}

    int main() {

    // pair_example();

    // vector_example();

    // list_example();

    // Deque_example();

    // Stack_example();

    // Queue_example();

    // PriorityQueue_example();

    // Set_example();

    // Multiset_example();

    // UnorderedSet_example();

    // Map_example();

    // UnorderedMap_example();
    // MultiMap_example();
     
    comparator_example();

    return 0;

}