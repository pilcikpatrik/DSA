#include <stdio.h>
#include <stdlib.h>

typedef struct List_node_s {
    Data_t data;
    struct List_node_s *prev;
    struct List_node_s *next;
}List_Node_t;

typedef struct {
    List_Node_t *first;
    List_Node_t *last;
    List_Node_t *active;
}List_t;

int main()
{
    return 0;
}

void List_Init (List_t *const list)
{
    if (list != NULL)
    {
        list->last = NULL;
        list->first = NULL;
        list->active = NULL;
    }
}

void List_Insert_First (List_t *const list, Data_t data)
{
    if (list != NULL)
    {
        List_Node_Ptr_t novyNode = myMalloc(sizeof (*novyNode));

        if (novyNode == NULL)
        {
            return;
        }

        novyNode.data = data;
        novyNode.prev = NULL;
        novyNode.next = list->first;

        list->first = novyNode;
        if(list->last == NULL)
        {
            list->last = list->first;
        }
    }
}

void List_Delete_First (List_t *const list)
{
    if (list != NULL)
    {
        if(list->first == NULL)
        {
            return;
        }
        else if (list->first == list->active)
        {
            list->active = NULL;
        }

        if (list->first->next ==NULL)
        {
            myFree(list->first);
            list->first = NULL;
            list->last = NULL;
            return;
        }

        List_Node_Ptr_t OldFirst = list.first;

        list->first = OldFirst.next;
        list->first->prev = NULL;

        myFree(OldFirst);
    }
}
