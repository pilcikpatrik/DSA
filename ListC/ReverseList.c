#include <stdio.h>
#include <stdlib.h>


int main()
{

}

void List_Reverse(list *const list)
{
    if(list == NULL || list.first == NULL)
        return;
    list_ptr node previous = NULL;
    list_ptr node = list.first;
    list_ptr nodeNext = node.next;
    node.next = nodePrevious;

    while(nodeNext != NULL)
    {
        nodePrevious = node;
        node = nodeNext;
        nodeNet = node.next;
        node.next = NodePrevious;
    }
    list.first = node
}
