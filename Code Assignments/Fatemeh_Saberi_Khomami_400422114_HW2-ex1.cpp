#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


void insert(Node** head, int new_data) {
    Node* new_n = new Node;
    new_n->data = new_data;
    new_n->next = NULL;
    if (*head == NULL)
    {
        *head=new_n;
    }
    else
    {
        Node* temp = *head;
        while(temp->next != NULL){
            temp=temp->next;
        }
    temp->next=new_n;
    }
}

void del(Node* head, int k) {
    if (head==NULL)
        return;

    if (k==1)
    {
      head = head->next;
      return;
    }

    Node* ptr;
    ptr = head;

    for (int i = 1; ptr != NULL && i <= k-2; i++)
        ptr = ptr->next;

    if (ptr ==NULL)
        return;

    ptr->next = ptr->next->next;
    return;



}

void remove_dup(Node* head){
    Node* ptr1 = head;
    Node* ptr2 = head;

    while (ptr1 != NULL && ptr1->next !=NULL)
    {
        while(ptr2->next != NULL)
        {
            if(ptr1->data == ptr2->next->data)
            {
                ptr2->next = ptr2->next->next;
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1 ->next;
        ptr2 = ptr1;
    }
}

void odd_and_even_ind(Node** even, Node** odd, Node* head)
{
    if(head != NULL)
    {
        insert(odd, head->data);
        if (head->next != NULL)
        {
            insert(even, head->next->data);
            odd_and_even_ind(even, odd, head->next->next);
        }
    }
}

int len(Node* head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}
void delete_mid(Node* head, int mid)
{
    if (mid == 1)
    {
        head->next = head->next->next;
        return;
    }

    delete_mid(head->next, mid-1);
}


void display(Node* head) {
   Node* ptr = head;
   while (ptr != NULL)
   {
       cout<< ptr->data <<" ";
       ptr = ptr->next;
   }
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    //del(head, 3);
    //remove_dup(head);
    //display(head);

    //Node* even=NULL;
    //Node* odd=NULL;

    //odd_and_even_ind(&even, &odd, head);

    //cout<<"The linked list is: ";
    //display(odd);
    //cout<<endl;
    //display(even);

    int mid=len(head)/2;
    delete_mid(head, mid);
    display(head);

    return 0;
}
