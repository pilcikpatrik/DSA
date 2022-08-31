#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *nextpt;
} *headpt;

void insertion_At_begin (int data)      // insertion function used for node to put in beginning of circular linked list
{
  struct node *new_node, *cur_Node;
  if (headpt == NULL)
    {
      printf ("The List is empty");
    }
  else
    {
      new_node = (struct node *) malloc (sizeof (struct node));
      new_node->data = data;
      new_node->nextpt = headpt;
      cur_Node = headpt;
      while (cur_Node->nextpt != headpt)
    {
      cur_Node = cur_Node->nextpt;
    }
      cur_Node->nextpt = new_node;
      headpt = new_node;
    }
}

void delete_begin_node ()		//function for deleting first node in the linked list
{
  struct node *n, *save;
  n = headpt;
  while (n->nextpt != headpt)
    {
      n = n->nextpt;
    }
  save = headpt;
  headpt = headpt->nextpt;
  printf ("The deletion at beginning is -> %d", save->data);
  n->nextpt = headpt;
  free (save);
}

void list (int n)       // list creation function of circular linked list
{
  int l, data;
  struct node *prevpt, *new_node;

  if (n >= 1)
    {
      headpt = (struct node *) malloc (sizeof (struct node));
      printf ("Enter data for node 1 : ");
      scanf ("%d", &data);
      headpt->data = data;
      headpt->nextpt = NULL;
      prevpt = headpt;
      for (l = 2; l <= n;l++)
      {
        new_node = (struct node *) malloc (sizeof (struct node));
        printf ("Enter data for node %d : ", l);
        scanf ("%d", &data);
        new_node->data = data;
    new_node->nextpt = NULL;
    prevpt->nextpt = new_node;
        prevpt = new_node;
    }
      prevpt->nextpt = headpt;
    }
}

void print (int m)          // print function of circular linked list
{
  struct node *extra;
  int n = 1;

  if (headpt == NULL)
    {
      printf ("The List is empty");
    }
  else
    {
      extra = headpt;
      if (m == 1)
    {
      printf ("The circular linked list is :\n");
    }
      else
    {
      printf ("After insertion the list is :\n");
    }
      do
    {
      printf ("The data at node %d -> %d\n", n, extra->data);
      extra = extra->nextpt;
      n++;
    }
      while (extra != headpt);
    }
}

int main ()
{
  int n,value, x;
  printf ("Enter the size of nodes: \n");
  scanf ("%d", &n);
  list (n);
  print (x);
  printf (" \nEnter the data to be inserted : ");
  scanf ("%d", &value);
  insertion_At_begin (value);
  print (x);
  return 0;
}
