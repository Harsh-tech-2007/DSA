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
    preorder_printtree(root->left);
    preorder_printtree(root->right);
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
    }}

//TC=o(n),SC=o(h)    
int size_of_binaryTree(Node *root){
    if(root==nullptr){
        return 0;
    }
    return (1 + size_of_binaryTree(root->left) + size_of_binaryTree(root->right));
}

void size_of_binaryTree_1(Node *root,int &c){
   if(root==nullptr){
        return;
    }

    c++;
    size_of_binaryTree_1(root->left,c);
    size_of_binaryTree_1(root->right,c);

}
void sum_of_binaryTree(Node *root,int &sum){
   if(root==nullptr){
        return;
    }

    sum=sum+(root->data);
    sum_of_binaryTree(root->left,sum);
    sum_of_binaryTree(root->right,sum);

}

void Number_of_leaf_nodes(Node *root,int &c){
   if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr )
    {
        c++;
    }

    Number_of_leaf_nodes(root->left,c);
    Number_of_leaf_nodes(root->right,c);

}


int main(){
    vector<int> preoder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = bulidtree(preoder);

    int sum = 0;
    preorder_printtree(root);
    // size_of_binaryTree_1(root,c);
    // sum_of_binaryTree(root,sum);
    Number_of_leaf_nodes(root, sum);
    cout << "sum :" << sum;
    // cout << "size :" << size_of_binaryTree(root) << endl;

    return 0;

}
