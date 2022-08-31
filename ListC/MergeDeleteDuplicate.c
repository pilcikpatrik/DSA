#include <stdio.h>
#include <stdlib.h>

// structure of a node
struct Node {
    int data;
    struct Node* next;
};

// function to get a new node
struct Node* getNode(int data)
{
    // allocate space
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // put in data
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// function to merge two sorted linked list
// in a sorted manner
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return (result);
}

/* The function removes duplicates from a sorted list */
void removeDuplicates(struct Node* head)
{
    /* Pointer to traverse the linked list */
    struct Node* current = head;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct Node* next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
        return;

    /* Traverse the list till last node */
    while (current->next != NULL) {

        /* Compare current node with next node */
        if (current->data == current->next->data) {

            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion */
        {
            current = current->next;
        }
    }
}

// function to merge two sorted linked list
// without duplicates
struct Node* sortedMergeWithoutDuplicates(struct Node* head1, struct Node* head2)
{
    // merge two linked list in sorted manner
    struct Node* head = sortedMerge(head1, head2);

    // remove duplicates from the list 'head'
    removeDuplicates(head);

    return head;
}

// function to print the linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        printf("\t %d", head->data);
        head = head->next;
    }
}

// Driver program to test above
int main()
{
    // head1: 1->1->4->5->7
    struct Node* head1 = getNode(1);
    head1->next = getNode(1);
    head1->next->next = getNode(4);
    head1->next->next->next = getNode(5);
    head1->next->next->next->next = getNode(7);

    // head2: 2->4->7->9
    struct Node* head2 = getNode(2);
    head2->next = getNode(4);
    head2->next->next = getNode(7);
    head2->next->next->next = getNode(9);

    struct Node* head3;

    head3 = sortedMergeWithoutDuplicates(head1, head2);

    printList(head3);

    return 0;
}
