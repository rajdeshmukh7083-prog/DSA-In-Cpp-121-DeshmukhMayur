#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n)
{
    if (n == NULL)
        return 0;

    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node* createNode(int value)
{
    Node* node = new Node();

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int getBalance(Node* n)
{
    if (n == NULL)
        return 0;

    return height(n->left) - height(n->right);
}

// Right Rotation
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

// Left Rotation
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

// Insert element into AVL Tree
Node* insert(Node* node, int value)
{
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // Left-Right (LR) Rotation
    if (balance > 1 &&
        value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Left-Left (LL) Rotation
    if (balance > 1 &&
        value < node->left->data)
    {
        return rightRotate(node);
    }

    // Right-Right (RR) Rotation
    if (balance < -1 &&
        value > node->right->data)
    {
        return leftRotate(node);
    }

    // Right-Left (RL) Rotation
    if (balance < -1 &&
        value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Display tree using inorder traversal
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

    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);

    cout << "Balanced AVL Tree (Inorder): ";
    inorder(root);

    cout << "\nRoot Node: " << root->data;

    return 0;
}
