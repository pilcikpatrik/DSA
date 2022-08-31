// Include header file
#include <stdio.h>
#include <stdlib.h>
/*
    C program for
    Count frequency of key in linked list
*/
// Linked list node
typedef struct LinkNode
{
    // Define useful field of LinkNode
    int data;
    struct LinkNode * next;
}LinkNode;

LinkNode * getLinkNode(int data)
{
    // Create dynamic memory of LinkNode
    LinkNode * ref = (LinkNode * ) malloc(sizeof(LinkNode));
    if (ref == NULL)
    {
        // Failed to create memory
        return NULL;
    }
    ref->data = data;
    ref->next = NULL;
    return ref;
}
typedef struct SingleLL
{
    // Define useful field of SingleLL
    struct LinkNode * head;
    struct LinkNode * tail;
}SingleLL;

SingleLL * getSingleLL()
{
    // Create dynamic memory of SingleLL
    SingleLL * ref = (SingleLL * ) malloc(sizeof(SingleLL));
    if (ref == NULL)
    {
        // Failed to create memory
        return NULL;
    }
    // Set initial value
    ref->head = NULL;
    ref->tail = NULL;
    return ref;
}
void insert(SingleLL * ref, int data)
{
    LinkNode * node = getLinkNode(data);
    if (ref->head == NULL)
    {
        // Add first node
        ref->head = node;
    }
    else
    {
        // Add node at the end position
        ref->tail->next = node;
    }
    // New last node
    ref->tail = node;
}
// Display linked list element
void display(SingleLL * ref)
{
    if (ref->head == NULL)
    {
        return;
    }
    LinkNode * temp = ref->head;
    // iterating linked list elements
    while (temp != NULL)
    {
        printf(" %d →", temp->data);
        // Visit to next node
        temp = temp->next;
    }
    printf(" NULL");
}
// Find frequency of a key in linked list
void findFrequency(SingleLL * ref, int key)
{
    // This is used to count key nodes
    int counter = 0;
    // Get first node of linked list
    LinkNode * node = ref->head;
    // iterate linked list node
    while (node != NULL)
    {
        if (key == node->data)
        {
            // When key node exist
            counter++;
        }
        // Visit to next node
        node = node->next;
    }
    printf("\n Node Key : %d", key);
    printf(", Frequency : %d", counter);
}
int main()
{
    SingleLL * sll = getSingleLL();
    // Add node in linked list
    //  1 → 7 → 111 → 3 → 1 → 7 → 1 → 3 → 11 → 1 → 7 → NULL
    insert(sll, 1);
    insert(sll, 7);
    insert(sll, 111);
    insert(sll, 3);
    insert(sll, 1);
    insert(sll, 7);
    insert(sll, 1);
    insert(sll, 3);
    insert(sll, 11);
    insert(sll, 1);
    insert(sll, 7);
    // Display of linked list nodes
    display(sll);
    // Test cases
    findFrequency(sll, 1);
    findFrequency(sll, 3);
    findFrequency(sll, 13);
    findFrequency(sll, 7);
}
