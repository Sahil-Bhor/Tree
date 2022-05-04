#include <iostream>
#include <string>
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

void insert_bst(Node *&root, int data)
{

    if (root == NULL)
    {
        Node *new_node = new Node(data);
        root = new_node;
    }
    if (data < root->data)
    {
        if (root->left == NULL)
        {
            Node *new_node = new Node(data);
            root->left = new_node;
        }
        else
        {
            insert_bst(root->left, data);
        }
    }
    if (data > root->data)
    {
        if (root->right == NULL)
        {
            Node *new_node = new Node(data);
            root->right = new_node;
        }
        else
        {
            insert_bst(root->right, data);
        }
    }
}

void set_data(Node *&root)
{
    int no, ele;

    cout << "Enter the elements: ";
    while (true)
    {
        cin >> no;
        if (no != -1)
        {
            insert_bst(root, no);
        }
        else
        {
            return;
        }
    }
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
    string path = "N";
    int target, del;

    // creating bst
    set_data(root);

    // traversals
    cout << "\nIn-order: ";
    inorder(root);
    cout << "\nPre-order: ";
    preorder(root);
    cout << "\nPost-order: ";
    postorder(root);

    cout << endl;
    return 0;
}

/*
Sample input:
25 20 10 22 5 12 1 8 15 36 30 28 40 38 48 45 50 -1
*/
