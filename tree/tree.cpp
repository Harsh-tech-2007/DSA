#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

static int idx = -1;

Node* bulidtree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){
        return nullptr;
    }

    Node *root = new Node(preorder[idx]); 
    root->left = bulidtree(preorder);
    root->right = bulidtree(preorder);

    return root; 
}

//preorder travrsal
void preorder_printtree(Node *root){
    if(root==nullptr){
        return;
    }

    cout << root->data << endl;
    printtree(root->left);
    printtree(root->right);
}

//inorder traversal
void inorder_printtree(Node *root){
    if(root==nullptr){
        return;
    }
    inorder_printtree(root->left);
    cout << root->data << endl;
    inorder_printtree(root->right);
}

//postorder
void postorder_printtree(Node *root){
    if(root==nullptr){
        return;
    }
    postorder_printtree(root->left);
    postorder_printtree(root->right);
    cout << root->data << endl;
}

//level order traversal
void level_order(Node *root){
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

int main(){
    vector<int> preoder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = bulidtree(preoder);

    preorder_printtree(root);

    return 0;

}
