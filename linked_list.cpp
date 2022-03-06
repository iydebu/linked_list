#include <iostream>
#include <limits>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(){};
    Node(int data)
    {
        this->data = data;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void insertAfter(Node *pre_node, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = pre_node->next;
    pre_node->next = new_node;
}
void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}
void deleteNode(Node **head_ref, int key)
{
    Node *temp = *head_ref;
    Node *pre_node = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            pre_node = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        pre_node->next = temp->next;
        delete temp;
    }
}
void push_r(Node *&head_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head_ref;
    head_ref = new_node;
}
void printList_r(Node *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        printList_r(node->next);
    }
    else
    {
        cout << endl;
    }
}
void deleteNode_r(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Elements is not present in the list!" << endl;
        return;
    }
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    deleteNode_r(head->next, val);
}
void deleteNode_index(Node **head_ref, int index)
{
    if (*head_ref == NULL)
        return;
    Node *temp = *head_ref;
    if (index == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void deleteList_all(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
    cout << "List Deleted !" << endl;
}
int countList(Node *head_ref)
{
    if (head_ref != NULL)
    {
        return 1 + countList(head_ref->next);
    }
    else
        return 0;
}
int searchNode(Node *head_ref, int ele)
{
    static int count = 1;
    if (head_ref != NULL)
    {
        if (head_ref->data == ele)
            return count;
        else
            count++;
        searchNode(head_ref->next, ele);
    }
    else
        return -1;
}
Node *nth(Node **head_ref, int index)
{
    Node *temp = *head_ref;
    if (index == 0)
        return *head_ref;

    for (int i = 0; temp != NULL && i < index; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        throw INT_MIN;
    }
    return temp;
}
void reverseList(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next = NULL;
    Node *prv = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prv;
        prv = current;
        current = next;
    }
    *head_ref = prv;
}
Node *reverseList_r(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest = reverseList_r(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
int main()
{
    Node *head = NULL;
    push_r(head, 3);
    push_r(head, 2);
    push_r(head, 1);
    printList_r(head);
    head = reverseList_r(head);
    printList_r(head);
}