#include <iostream>
using namespace std;

struct node {
    int value;
    struct node *left, *right;
};

struct node* newNode(int value)
{
    struct node *temp = new node;
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* minValueNode(struct node *root) {
    if (!root) {
        cout << "No root" << endl;
        return 0;
    }

    struct node *current = root;

    while (current->left && current->left != NULL) {
        current = current->left;
    }

    return current;
}

bool search(struct node* root, int value)
{
    while (root != NULL) {
        if (value > root->value)
            root = root->right;
        else if (value < root->value)
            root = root->left;
        else
        {
            cout << value << " found" << endl;
            return true;
        }
    }
    cout << value << " not found" << endl;
    return false;
}

struct node* insert(struct node *root, int value)
{
    if (!root) {
        return newNode(value);
    }

    if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }

    return root;
}

struct node* deleteNode(struct node* root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    
}

void inOrder(struct node *root)
{
    if (!root) {
        return;
    }

    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

void preOrder(struct node *root)
{
    if (!root) {
        return;
    }

    cout << root->value << " ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(struct node *root)
{
    if (!root) {
        return;
    }

    inOrder(root->left);
    inOrder(root->right);
    cout << root->value << " ";
}

void log(struct node* root)
{
    cout << "In order: ";
    inOrder(root);
    cout << endl;
    cout << "Pre order: ";
    preOrder(root);
    cout << endl;
    cout << "Post order: ";
    postOrder(root);
    cout << endl;
}

int main()
{
    int outOfOrder[10] = {6,3,9,8,1,2,4,5,7};
    int length = sizeof(outOfOrder) / sizeof(outOfOrder[0]);
    struct node *root = newNode(5);
    srand (time(NULL));

    for (int i = 0; i < length; ++i)
    {
        int random = rand() % 9;
        insert(root, outOfOrder[random]);
    }

    log(root);
    deleteNode(root, 4);
    log(root);

    cout << search(root, 5) << endl;
    cout << search(root, 7) << endl;
    cout << search(root, 100) << endl;
    cout << search(root, -100) << endl;

    return 0;
};
