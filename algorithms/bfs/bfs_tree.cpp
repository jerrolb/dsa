#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left, *right;
};

void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return lheight + 1;
        else return rheight + 1;
    }
}

// int height(node* node) {
//     int lcount = 0;
//     int rcount = 0;
//     node* l;
//     node* r;
//     while (node->left) {
//         ++lcount;
//         l = node->left;
//     }
//     while (node->right) {
//         ++rcount;
//         r = node->right;
//     }
// }

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}

void bfs(node* root) {
    queue<node*> q;
    node* f;

    q.push(root);

    while (!q.empty()) {
        f = q.front();
        q.pop();

        cout << f->data << endl;

        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
}

void dfs(node* root) {
    stack<node*> s;
    node* t;

    s.push(root);

    while (!s.empty()) {
        t = s.top();
        s.pop();

        cout << t->data << endl;
        if (t->right) s.push(t->right);
        if (t->left) s.push(t->left);
    }
}

void pre(node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << endl;
    pre(root->left);
    pre(root->right);
}

void in(node* root) {
    if (root == NULL) {
        return;
    }

    in(root->left);
    cout << root->data << endl;
    in(root->right);
}

void reverse_in(node* root) {
    if (root == NULL) {
        return;
    }

    reverse_in(root->right);
    cout << root->data << endl;
    reverse_in(root->left);
}

void post(node* root) {
    if (root == NULL) {
        return;
    }

    post(root->left);
    post(root->right);
    cout << root->data << endl;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    // printLevelOrder(root);
    // dfs(root);
    // pre(root);
    in(root);
    reverse_in(root);
    // post(root);

    return 0;
}
