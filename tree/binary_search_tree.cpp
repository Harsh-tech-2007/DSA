#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {

    if(root == nullptr) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else if(val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

bool search(Node* root, int key) {

    if(root == nullptr) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void BFS(Node* root){

    queue<Node *> q;
    q.push(root);

    while (q.size()>0)
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << endl;

        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
    }

}

Node* findMin(Node* root) {

    if(root == nullptr)
        return nullptr;

    while(root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* findMax(Node* root) {

    if(root == nullptr)
        return nullptr;

    while(root->right != nullptr) {
        root = root->right;
    }

    return root;
}

Node* deleteNode(Node* root, int key) {

    if(root == nullptr) {
        return nullptr;
    }

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    else {

        // Case 1: No left child
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int main(){

    vector<int> arr = {6, 3, 11, 5, 7, 18, 12, 2, 11};

    Node *root = nullptr;
    for (int val : arr)
    {
        root = insert(root, val);
    }

    cout << "inorder"<<endl;
    inorder(root);
    cout << "BFS" << endl;
    BFS(root);
}