#include <bits/stdc++.h>
using namespace std;

class node 
{
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
node* buildTree(node* root) 
{
    int data;
    cin >> data;

    if (data == -1) 
    {
        return NULL;
    }

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}
vector<int> PostOrder(node* root, vector<int>& result) 
{
    if (root != NULL) 
    {
        PostOrder(root->left, result);
        PostOrder(root->right, result);
        result.push_back(root->data);
    }
    return result;
}
vector<int> InOrder(node* root, vector<int>& result) {
    if (root != NULL) {
        InOrder(root->left, result);
        result.push_back(root->data);
        InOrder(root->right, result);
    }
    return result;
}
void LevelOrder(node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}
void printingTraversal(node* root , vector<int>& post, vector<int>& in)
{
    cout << "Printing PostOrder: ";
    for (int i : post) 
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Printing InOrder: ";
    for (int i : in) 
    {
        cout << i << " ";
    }
    cout << endl;
}

node* ReConstructTree(vector<int>& post, vector<int>& in, int start, int end, int& postidx) {
    if (start > end) {
        return NULL;
    }

    node* root = new node(post[postidx]);
    postidx--;

    int index = -1;
    for (int i = start; i <= end; i++) {
        if (in[i] == root->data) {
            index = i;
            break;
        }
    }

    root->right = ReConstructTree(post, in, index + 1, end, postidx);
    root->left = ReConstructTree(post, in, start, index - 1, postidx);

    return root;
}
void CreatingTree(node* root)
{
    cout << endl << "Example data is : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 " << endl ;
    cout << "Enter data to build the tree (-1 for NULL): ";
    root = buildTree(root);

    vector<int> postOrder;
    vector<int> inOrder;

    PostOrder(root, postOrder);
    InOrder(root, inOrder);

    cout << "Printing PostOrder and InOrder traversal " << endl ;

    printingTraversal(root , postOrder , inOrder);

    int postidx = postOrder.size() -1 ;

    node* newRoot = ReConstructTree(postOrder, inOrder, 0, inOrder.size() - 1, postidx);

    cout << endl << "After Reconstruction, the tree's LevelOrder Traversal is: ";
    LevelOrder(newRoot);

   
}

int main() {
    node* root = NULL;

    CreatingTree(root);
    return 0;
}
