#include <stdio.h>
#define max 5
int a[max];
int front = -1;
int rear = -1;

void Insert(int x)
{
  if ((front == rear + 1) || front == 0 && rear == (max-1))
  {
    printf("Overflow\n");
  }
  else if (front == -1 && rear == -1)
  {
    front = 0;
    rear = 0;
  }
  else if (rear == (max-1))
  {
    rear = 0;
  }
  else
  {
    rear += 1;
  }
  a[rear] = x;
}

void Delete()
{
  if (front == -1 && rear == -1)
  {
    printf("Empty\n");
  }
  else if (front == (max-1))
  {
    front = 0;
  }
  else if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front += 1;
  }
}
void Display()
{
  if (front == -1 && rear == -1)
  {
    printf("Empty\n");
  }
  else if (front < rear)
  {
    for (int i = front; i<=rear; i++)
    {
      printf("%d\n",a[i]);
    }
  }
  else if (front > rear)
  {
    for (int i = front; i<max; i++)
    {
      printf("%d\n",a[i]);
    }
    for (int i = 0; i<=rear; i++)
    {
      printf("%d\n",a[i]);
    }
  }
}

int main()
{
    int ch,n;
    do
    {
        printf("\nMENU\n");
        printf("1) Insert\n");
        printf("2) Delete\n");
        printf("3) Display\n");
        printf("4) Exit\n");
        printf("Enter Choice ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1:
                printf("Enter a Number ");
                scanf("%d",&n);
                Insert(n);
                break;
            case 2:
                Delete ();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Thank You");
                break;
            default:
                printf("Invalid Option");
        }
    }while(ch!=4);
}