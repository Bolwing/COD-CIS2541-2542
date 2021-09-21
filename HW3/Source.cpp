
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


//CREATE
struct node
{
    int data;
    struct node* next;
};

//FLIP

void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
//PUSH A NODE 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// PRINTS LINKED LIST
void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// MAIN FUNCTION
int main()
{
    struct node* head = NULL;
    
    int first;
    int second;
    int third;
    int fourth;
    
    cout <<  "Input the first integer for the linked list" << endl;
    cin >> first;
    cout << "Input the second integer for the linked list" << endl;
    cin >> second;
    cout << "Input the third integer for the linked list" << endl;
    cin >> third;
    cout << "input the fourth integer for the linked list" << endl;
    cin >> fourth;

    push(&head, first);
    push(&head, second);
    push(&head, third);
    push(&head, fourth);
    cout << "Reversed Linked List" << endl;
    printList(head);
    cout << endl;
    reverse(&head);
    cout << "Original Linked List" << endl;
    printList(head);
}

