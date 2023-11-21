#include <stdio.h>
#include <stdlib.h>

struct Number 
{
  struct Number *prev;
  int n;
  struct Number *next;
};

typedef struct Number Node;
Node *head = NULL;
Node *tail = NULL;

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

void AddAtBegin(int x)
{
  Node *ptr = (Node *) malloc(sizeof(Node));
  if (ptr == NULL)
  {
    printf("Memory Over");
  }
  else
  {
    ptr -> prev = NULL;
    ptr -> n = x;
    ptr -> next = NULL;
    if (head == NULL)
    {
      head = tail = ptr;
    }
    else
    {
      ptr -> next = head;
      head -> prev = ptr;
      head = ptr;
    }
  }
}

void AddAtEnd(int x)
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
      head = tail = ptr;
    }
    else
    {
      ptr -> prev = tail;
      tail -> next = ptr;
      tail = ptr;
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
      ptr -> prev = NULL;
      ptr -> n = x;
      ptr -> next = NULL;
      Node *temp = head;
      for (int i=0; i<(p-1); i++)
      {
        temp = temp -> next;
      }
      ptr -> prev = temp;
      ptr -> next = temp -> next;
      temp -> next -> prev = ptr;
      temp -> next = ptr;
    }
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
  else if (head == tail)
  {
    free(head);
    head = tail = NULL;
  }
  else
  {
    tail = tail -> prev;
    tail->next = NULL;
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
    Node *ptr1 = head;
    Node *ptr2 = tail;
    while (ptr1!=NULL && ptr2!=NULL)
    {
      if (ptr1 -> n == x ||ptr2 -> n == x)
      {
        c=1;
        break;
      }
      else
      {
        if (ptr1->next != NULL)
        {
          ptr1 = ptr1->next;
        }
        if (ptr2->prev != NULL)
        {
          ptr2 = ptr2->prev;
        }
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
      printf("%d\n",ptr->n);
      ptr = ptr -> next;
    }
  }
}

void DisplayRev()
{
  if (head == NULL)
  {
    printf("Empty");
  }
  else 
  {
    Node *ptr = tail;
    while (ptr!=NULL)
    {
      printf("%d\n",ptr->n);
      ptr = ptr -> prev;
    }
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

  DisplayRev();

  // Search(99);
  // // Search(9);
  // Search(10);

  // DeleteAtBegin();
  // Display();
  // printf("\n");

  // DeleteAtBegin();
  // Display();
  // printf("\n");

  // DeleteAtEnd();
  // Display();
  // printf("\n");

  // DeleteAtEnd();
  // Display();
  // printf("\n");

  return 0;
}