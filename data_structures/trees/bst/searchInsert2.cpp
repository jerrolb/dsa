#include <iostream>
using namespace std;

class BST
{
    public:

    BST(int v = 3) {
        value = v;
        left = NULL;
        right = NULL;
    };

    BST* insert(BST *root, int value)
    {
        if (!root)
        {
            return new BST(value);
        }

        if (value > root->value) {
            root->right = insert(root->right, value);
        } else {
            root->left = insert(root->left, value);
        }

        return root;
    }

    void inOrder (BST *root)
    {
        if (!root) {
            return;
        }

        inOrder(root->left);
        cout << root->value << " ";
        inOrder(root->right);
    }

    void preOrder (BST *root)
    {
        if (!root) {
            return;
        }

        cout << root->value << " ";
        inOrder(root->left);
        inOrder(root->right);
    }

    void postOrder (BST *root)
    {
        if (!root) {
            return;
        }

        inOrder(root->left);
        inOrder(root->right);
        cout << root->value << " ";
    }

    int value;
    BST* left;
    BST* right;
};

int main()
{
    srand (time(NULL));

    BST t;
    BST *root = NULL;
    root = t.insert(root, 5);

    int outOfOrder[10] = {6,3,9,8,1,2,4,5,7};
    int length = sizeof(outOfOrder) / sizeof(outOfOrder[0]);

    for (int i = 0; i < length; ++i)
    {
        int random = rand() % 9;
        t.insert(root, outOfOrder[random]);
    }

    cout << "In order: ";
    t.inOrder(root);
    cout << endl;
    cout << "Pre order: ";
    t.preOrder(root);
    cout << endl;
    cout << "Post order: ";
    t.postOrder(root);
    cout << endl;

    return 0;
};
