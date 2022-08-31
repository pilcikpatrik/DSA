#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}

void Merge(Vector_t * vysledek, Vector_t * v1, Vector_t * v2)
{
    if (vysledek == NULL || v1 == NULL || v2 == NULL)
        return;

    for ( i = 0, j = 0; i < Vector_Lenght(v1) && j < Vector_Lenght(v2); )
    {
        if(v1.items[i] < v2.items[j])
        {
            *vysledek.next = v1.items[i];
            ++vysledek.next;
            ++i;
        }
        else
        {
            *vysledek.next = v2.items[j];
            ++vysledek.next;
            ++j;
        }
    }

    if (i == Vector_Lenght(v1))
    {
        while (j < Vector_Lenght(v2))
        {
            *vysledek.next = v2.items[j];
            ++vysledek.next;
            ++j;
        }
    }
    else
    {
        while(i < Vector_Lenght(v1))
        {
            *vysledek.next = v1.items[i];
            ++vysledek.next;
            ++i;
        }
    }
}
