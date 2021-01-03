#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout<<"the given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

bool search(Node* head, int data)
{
    Node* curr = head;

    while (curr && curr->data)
    {
        if (curr->data == data)
            return true;

        curr = curr->next;
    }

    return false;
}

void deleteByValue(Node* head, int data)
{
    Node* curr = head;
    Node* prev;

    if (head->data == data)
    {
        head->data = head->next->data;
        head->next = head->next->next;
    }
    else
    {
        while (curr && curr->data)
        {
            if (curr->data == data)
            {
                if (curr->next == NULL)
                {
                    prev->next = NULL;
                }
                else
                {
                    curr->data = curr->next->data;
                    curr->next = curr->next->next;
                }
                
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    cout<<"Created Linked list is: "; // 1 7 8 6 4
    printList(head);

    cout << search(head, 1) << endl;
    cout << search(head, 7) << endl;
    cout << search(head, 8) << endl;
    cout << search(head, 6) << endl;
    cout << search(head, 4) << endl;
    cout << search(head, 100) << endl;

    deleteByValue(head, 1);
    deleteByValue(head, 10);
    deleteByValue(head, 7);
    deleteByValue(head, 6);
    deleteByValue(head, 4);
    printList(head);

    return 0;
}