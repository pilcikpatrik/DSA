#include <stdio.h>
#include <stdlib.h>

int main()
{

}

void IntersectList (List_t * seznam1, List_t * seznam2)
{
    if (seznam1 == NULL || seznam2 == NULL || seznam1.first == NULL || seznam2.first == NULL)
    {
        return;
    }

    list_ptr s1_prev = NULL;
    list_ptr s1_node = seznam1.first;
    list_ptr s2_node;

    while(s1_node != NULL)
    {
        bool prvekNalezen = false;
        s2_node = seznam2.first;

        while (s2_node != NULL)
        {
            if(Data_Cmp(&s1_node.data, &s2_node.data) == 0)
            {
                prvekNalezen = true;
            }

            s2_node = s2_node.next;
        }

        if(!prvekNalezen)
        {
            list_ptr nodeNext = s1_node.next;

            if (s1_prev == NULL)
            {
                seznam1.first = nodeNext;
            }
            else if (s1_prev != NULL)
            {
                s1_prev.next = nodeNext;
            }

            myFree(s1_node);
            s1_node = nodeNext;
        }

        s1_prev = s1_node;
        s1_node = s1_node.next
    }
}
