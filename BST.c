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

int Count(Node *ptr)
{
  int c = 0;
  while (ptr != NULL)
  {
    c++;
    ptr = ptr->next;
  }
  return c;
}

Node* Insert(Node *ptr, int x)
{
  if (ptr == NULL)
  {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->n = x;
    newNode->next = NULL;
    return newNode;
  }

  if (x < ptr->n)
  {
    ptr->prev = Insert(ptr->prev, x);
  }
  else if (x > ptr->n)
  {
    ptr->next = Insert(ptr->next, x);
  }

  return ptr;
}

void Search(Node *ptr, int x)
{
  if (ptr == NULL)
  {
    printf("Not found %d\n", x);
    return;
  }

  if (x < ptr->n)
  {
    Search(ptr->prev,x);
  }
  else if (x > ptr->n)
  {
    Search(ptr->next,x);
  }
  else
  {
    printf("Found %d\n",ptr->n);
  }
}

void Display(Node *ptr)
{
  if (ptr != NULL)
  {
    Display(ptr->prev);
    printf("%d ", ptr->n);
    Display(ptr->next);
  }
}

int main()
{
  head = Insert(head, 10);
  head = Insert(head, 12);
  head = Insert(head, 8);
  head = Insert(head, 11);
  head = Insert(head, 45);
  head = Insert(head, 2);
  head = Insert(head, 7);

  printf("Number of nodes: %d\n", Count(head));
  printf("Sorted numbers: ");
  Display(head);

  printf("\n");

  Search(head, 10);
  Search(head, 2);

  return 0;
}
