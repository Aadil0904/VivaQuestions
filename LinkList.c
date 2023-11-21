#include <stdio.h>
#include <stdlib.h>

struct Number
{
  int n;
  struct Number *next;
};

typedef struct Number Node;

Node *head = NULL;

int Count()
{
  int c=0;
  if (head == NULL)
  {
    printf("Empty");
  }
  else
  {
    Node *ptr = head;
    while (ptr!=NULL)
    {
      c++;
      ptr = ptr -> next;
    }
  }
  return c;
}

void AddAtBegin (int x)
{
  Node *ptr = (Node *) malloc(sizeof(Node));
  if (ptr == NULL)
  {
    printf("Memory Over");
  }
  else
  {
    ptr -> n = x;
    ptr -> next = head;
    head = ptr;
  }
}

void AddAtEnd (int x)
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
    if (head == NULL)
    {
      head = ptr;
    }
    else 
    {
      Node *temp = head;
      while ((temp->next)!=NULL)
      {
        temp = temp -> next;
      }
      temp -> next = ptr;
    }
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
      Node *temp = head;
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
  if (head == NULL)
  {
    printf("Empty");
  }
  else 
  {
    Node *ptr = head;
    while (ptr!=NULL)
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
  if (head == NULL)
  {
    printf("Empty");
  }
  else
  {
    head = head -> next;
  }
}

void DeleteAtEnd()
{
  if (head == NULL)
  {
    printf("Empty");
  }
  else if (head -> next == NULL)
  {
    free(head);
  }
  else 
  {
    Node *ptr = head;
    for (int i = 0; i<Count()-2; i++)
    {
      ptr = ptr -> next;
    }
    ptr -> next = NULL;
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
      printf("%d\n",ptr -> n);
      ptr = ptr -> next;
    }
  }
}

void DisplayRev (Node *ptr)
{
  if (head == NULL)
  {
    printf("Empty");
  }
  else
  {
    if (ptr == NULL)
    {
      return;
    }
    DisplayRev(ptr->next);
    printf("%d\n", ptr->n);
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