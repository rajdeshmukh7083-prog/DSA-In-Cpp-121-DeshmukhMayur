#include <iostream>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
};

int height(Node* n)
{
    return n == NULL ? 0 : n->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int balance(Node* n)
{
    return n == NULL ? 0 :
           height(n->left) - height(n->right);
}

Node* createNode(int value)
{
    Node* n = new Node();
    n->data = value;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// Display tree with balance factors
void display(Node* root, int space = 0)
{
    if (root == NULL)
        return;

    space += 6;

    display(root->right, space);

    cout << endl;

    for (int i = 6; i < space; i++)
        cout << " ";

    cout << root->data
         << " (BF=" << balance(root) << ")";

    display(root->left, space);
}

// Left rotation
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

// Right rotation
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

// Insert into AVL tree
Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int bf = balance(root);

    // Left-Right (LR) rotation
    if (bf > 1 && value > root->left->data)
    {
        cout << "\nLR imbalance detected at node "
             << root->data << endl;

        cout << "\nStep 1: Left rotation at node "
             << root->left->data << endl;

        root->left = leftRotate(root->left);

        cout << "\nTree after left rotation:\n";
        display(root);
        cout << endl;

        cout << "\nStep 2: Right rotation at node "
             << root->data << endl;

        root = rightRotate(root);

        cout << "\nTree after right rotation:\n";
        display(root);
        cout << endl;
    }

    // Left-Left (LL) rotation
    else if (bf > 1 && value < root->left->data)
        root = rightRotate(root);

    // Right-Right (RR) rotation
    else if (bf < -1 && value > root->right->data)
        root = leftRotate(root);

    // Right-Left (RL) rotation
    else if (bf < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node* root = NULL;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nFinal Balanced AVL Tree:\n";
    display(root);

    cout << "\n\nInorder Traversal: ";
    inorder(root);

    cout << endl;

    return 0;
}
