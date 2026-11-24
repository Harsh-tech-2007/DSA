#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;

    Node(int val) {
        key = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int key) {

    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* root) {
    Node* current = root;

    while (current->left)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {

    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {

        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                delete root;
                return NULL;
            }

            else {
                *root = *temp;
                delete temp;
            }
        }

        else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {

    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Before deletion: ";
    inorder(root);

    root = deleteNode(root, 20);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}