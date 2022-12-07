#include <iostream>
using namespace std;

 struct Node {
    int data;
    Node *next, *prev;
};

void insert(Node** head, int data) {
    Node* new_node = new Node;
    new_node->data = data;
    if (*head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else {
        Node* last = (*head)->prev;
        new_node->next = *head;
        new_node->prev = last;
        last->next = (*head)->prev = new_node;
    }
    *head = new_node;
}

void converttodl(Node* head){
    head->prev->next=NULL;
    head->prev=NULL;

}

void converttodcl(Node* head){
    Node* ptr = head;
   while (ptr->next != NULL)
   {
       ptr = ptr->next;
   }
   head->prev = ptr;
   ptr->next = head;

}

// split the list in 2

Node *breaklist(Node *head){
    Node *p = head;
    Node *q = head;
    while (p->next!=NULL && p->next->next!=NULL)
    {
        p = p->next->next;
        q = q->next;
    }
    Node *temp = q->next;
    q->next = NULL;
    return temp;
}

// merge 2 LL
Node *merge(Node *first, Node *second)
{
    if (first ==  NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node *merge_sort(Node *head)
{
    if (head == NULL || head->next==NULL)
        return head;
    Node *second = breaklist(head);


    head = merge_sort(head);
    second = merge_sort(second);


    return merge(head,second);
}


void display(Node* head) {
   Node* ptr = head;
   Node* first = head;
   cout<< ptr->data <<" ";
   ptr = ptr->next;
   while (ptr != first)
   {
       cout<< ptr->data <<" ";
       ptr = ptr->next;
   }
}


// Driver program
int main(void)
{
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 30);
    insert(&head, 10);
    converttodl(head);
    head = merge_sort(head);
    converttodcl(head);
    cout << "After sorting\n";
    display(head);
    return 0;
}
