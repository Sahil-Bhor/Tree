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

void search_node(Node *root, int target, string path)
{

    if (root != NULL)
    {
        if (target < root->data)
        {
            path += "->L";
            return search_node(root->left, target, path);
        }
        if (target > root->data)
        {
            path += "->R";
            return search_node(root->right, target, path);
        }
        if (target == root->data)
        {
            cout << "\nPath of " << target << " : " << path;
            return;
        }
    }
    else
    {
        cout << target << " is not present !";
    }
}

Node *max(Node *root)
{
    Node *prev = root;
    if (root != NULL)
    {
        while (root->right != NULL)
        {
            prev = root;
            root = root->right;
        }
    }
    return prev;
}
int min(Node *root)
{
    if (root != NULL)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
    return -1;
}

void deletion(Node *&root, int target)
{
    Node *temp = root;
    Node *prev = NULL;

    if (temp == NULL)
    {
        return;
    }

    while (target != temp->data)
    {
        if (target < temp->data)
        {
            prev = temp;
            temp = temp->left;
        }

        if (target > temp->data)
        {
            prev = temp;
            temp = temp->right;
        }
    }
    // 0 child
    if (temp->left == NULL && temp->right == NULL)
    {
        if (prev->left == temp)
        {
            prev->left = NULL;
        }
        if (prev->right == temp)
        {
            prev->right = NULL;
        }
        free(temp);
    }

    // 1 child
    else if ((temp->left != NULL) && (temp->right == NULL))
    {
        prev->left = temp->left;
        free(temp);
    }
    else if ((temp->left == NULL) && (temp->right != NULL))
    {
        prev->right = temp->right;
        free(temp);
    }

    // 2 child
    else
    {
        Node *beforMax = max(temp->left);
        cout << temp->data;

        temp->data = beforMax->data;
        temp->left = beforMax->left;
        free(beforMax);
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

    // searching
    cout << "\nEnter an element you want to search: ";
    cin >> target;
    search_node(root, target, path);

    // min & max
    cout << "\nMax num in subtree of root " << root->left->data << " : " << max(root->left)->right->data;
    cout << "\nMin num in subtree of root " << root->left->data << " : " << min(root->left);

    // deletion
    cout << "\nEnter an element you want to delete: ";
    cin >> del;
    deletion(root, del);
    cout << "\nIn-order: ";
    inorder(root);

    /* if u want to check that the node is deleted or UNCOMMENT the below
    line and try to search the preceeding elements of deleted node and path */

    // cout << "\nEnter an element you want to search: ";
    // cin >> target;
    // search_node(root, target, path);

    cout << endl;
    return 0;
}

/*
Sample input:
25 20 10 22 5 12 1 8 15 36 30 28 26 29 40 38 48 45 50 -1
*/