#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node() {}
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *createBT(Node *root)
{
    int value;

    cout << "\nEnter the data: ";
    cin >> value;
    root = new Node(value);

    if (value == -1)
    {
        return NULL;
    }

    cout << "\nEnter the left data: ";
    root->left = createBT(root->left);

    cout << "\nEnter the right data: ";
    root->right = createBT(root->right);

    return root;
}

void inorder(Node *root)
{

    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{

    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{

    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;

    root = createBT(root);

    cout << endl
         << "Inorder: ";
    inorder(root);

    cout << endl
         << "Postorder: ";
    postorder(root);

    cout << endl
         << "Preorder: ";
    preorder(root);

    cout << endl;
    return 0;
}
