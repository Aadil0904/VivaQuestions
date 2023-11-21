#include <stdio.h>
#include <stdlib.h>

struct Number 
{
  int n;
  struct Number *next;
};

typedef struct Number Node;
Node *last = NULL;

int Count()
{
  int c=0;
  if (last == NULL)
  {
    printf("Empty");
  }
  else
  {
    Node *ptr = last -> next;
    while (ptr!=last)
    {
      c++;
      ptr = ptr -> next;
    }
  }
  return c+1;
}

void AddAtBegin(int x)
{
  Node *ptr = (Node *) malloc(sizeof(Node));

  ptr -> n = x;
  ptr -> next = NULL;

  if (ptr == NULL)
  {
    printf("Memory Over");
  }

  else if (last == NULL)
  {
    last = ptr;
    ptr -> next = last;
  }
  else 
  {
    ptr -> next = last -> next;
    last -> next = ptr;
  }
}

void AddAtEnd(int x)
{
  Node *ptr = (Node *) malloc(sizeof(Node));

  ptr -> n = x;
  ptr -> next = NULL;

  if (ptr == NULL)
  {
    printf("Memory Over");
  }

  else if (last == NULL)
  {
    last = ptr;
    ptr -> next = last;
  }
  else 
  {
    ptr -> next = last -> next;
    last -> next = ptr;
    last = ptr;
  }
}

void InsertByPosition (int x, int p)
{
  int c = 0;
  c = Count();
  if (p<=1)
  {
    AddAtBegin(x);
  }
  else if (p>c)
  {
    AddAtEnd(x);
  }
  else
  {
    Node *ptr = (Node *) malloc(sizeof(Node));
    if (ptr == NULL)
    {
      printf("Memory Over");
    }
    else
    {
      ptr -> n = x;
      ptr -> next = NULL;
      Node *temp = last;
      for (int i=0;i<(p-1);i++)
      {
        temp = temp -> next;
      }
      ptr -> next = temp -> next;
      temp -> next = ptr;
    }
  }
}

void Search (int x)
{
  int c = 0;
  if (last == NULL)
  {
    printf("Empty");
  }
  else 
  {
    Node *ptr = last -> next;
    while (ptr!=last)
    {
      if (ptr -> n == x)
      {
        c=1;
        break;
      }
      else
      {
        ptr = ptr -> next;
      }
    }
  }
  if (c==1)
  {
    printf("Found %d\n",x);
  }
  else
  {
    printf("Not Found %d\n",x);
  }
}

void DeleteAtBegin()
{
  if (last == NULL)
  {
    printf("Empty");
  }
  else
  {
    Node *ptr = last -> next;
    last -> next = ptr -> next;
    free(ptr);
  }
}

void DeleteAtEnd()
{
  if (last == NULL)
  {
    printf("Empty");
  }
  else 
  {
    Node *ptr = last -> next;
    for (int i = 0; i<Count()-2; i++)
    {
      ptr = ptr -> next;
    }
    ptr -> next = NULL;
    last = ptr;
  }
}

void Display ()
{
  if (last == NULL)
  {
    printf("Empty");
  }
  else
  {
    Node *ptr = last -> next;
    while (ptr!=last)
    {
      printf("%d\n",ptr -> n);
      ptr = ptr -> next;
    }
    printf("%d\n",last -> n);
  }
}

int main()
{
  AddAtBegin(1);
  AddAtBegin(2);
  AddAtBegin(3);
  AddAtEnd(10);
  AddAtEnd(11);
  AddAtEnd(12);
  InsertByPosition(99,2);
  InsertByPosition(69,0);
  InsertByPosition(99,2);

  Display();

  Search(99);
  Search(9);
  Search(10);

  DeleteAtBegin();
  Display();
  printf("\n");

  DeleteAtBegin();
  Display();
  printf("\n");

  DeleteAtEnd();
  Display();
  printf("\n");

  DeleteAtEnd();
  

  return 0;
}