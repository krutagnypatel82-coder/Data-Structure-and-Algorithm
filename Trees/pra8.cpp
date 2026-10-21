#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if(root == NULL){
        return createNode(data);
    }
    else if(data < root->data)
    {
        root->left = insert (root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << ", ";
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        cout << root->data << ", ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ", ";

    }
}

int main(){
    struct Node *root = NULL;
    int n, value;
    cout << "Enter number of nodes :- ";
    cin >> n;

    cout << "Enter " << n << " values :- ";
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert (root, value);
    }

    cout << "\n Inorder Traversal :- ";
    inorder(root);

    cout << "\n Preorder Traversal :- ";
    preorder(root);

    cout << "\n Postorder Traversal :- ";
    postorder(root);

    return 0;
}
