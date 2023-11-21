#include <stdio.h>
#include <stdlib.h>

struct Number
{
  int p;
  int n;
  struct Number *next;
};

typedef struct Number Node;

Node *head = NULL;

int Position(int p)
{
  int c = 0;
  if (head == NULL)
  {
    printf("Empty\n");
  }
  else
  {
    Node *ptr = head;
    while (ptr != NULL && ptr->p < p)
    {
      c++;
      ptr = ptr->next;
    }
  }
  return c;
}

void Insert(int x, int y)
{
  int p = Position(x);
  Node *ptr = (Node *)malloc(sizeof(Node));
  if (ptr == NULL)
  {
    printf("Memory Over\n");
  }
  else
  {
    ptr->p = x;
    ptr->n = y;
    ptr->next = NULL;

    if (p == 0)
    {
      ptr->next = head;
      head = ptr;
    }
    else
    {
      Node *temp = head;
      for (int i = 0; i < (p - 1); i++)
      {
        temp = temp->next;
      }
      ptr->next = temp->next;
      temp->next = ptr;
    }
  }
}

void Delete()
{
  if (head == NULL)
  {
    printf("Empty");
  }
  else
  {
    head = head -> next;
  }
}

void Display ()
{
  if (head == NULL)
  {
    printf("Empty");
  }
  else
  {
    Node *ptr = head;
    while (ptr!=NULL)
    {
      printf("%d,%d\n",ptr -> p,ptr -> n);
      ptr = ptr -> next;
    }
  }
}

int main()
{

  Insert(0,90);
  Insert(1,25);
  Insert(2,36);

  Display();
  printf("\n");

  Delete();
  Display();
  printf("\n");

  Delete();
  Display();
  printf("\n");

  Delete();
  Display();
  printf("\n");

  return 0;
}