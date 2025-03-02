#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) 
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void LevelOrder(node* root)
{
    queue<node*> q ; 
    q.push(root);

    while(!q.empty())
    {
        node* curr = q.front() ;
        q.pop();
        cout << curr -> data << " " ;
        if(curr -> left != NULL)
        {
            q.push(curr -> left);
        }

        if(curr -> right != NULL)
        {
            q.push(curr -> right);
        }
    }
    cout << endl ;
}

int main() {
    node* root = NULL;

    cout << "Enter data to build the tree (-1 for NULL): ";
    root = buildTree(root);

    LevelOrder(root);
}