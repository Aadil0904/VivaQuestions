#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int precedence(char x) 
{
    switch (x)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
          return 4;
    }
}

int main()
{
  char exp[25];
  int len = 0;
  int top = -1;
  int topf = -1;
  printf("Enter an expression: ");
  scanf("%s", exp);
  len = strlen(exp);
  char stack[len];
  char final[len];

  for (int i = len-1; i >= 0; i--) 
  {
    if (exp[i]==')' || isalnum(exp[i]))
    {
      stack[++top] = exp[i];
    }
    else if (exp[i]=='(')
    {
      while (stack[top] != ')') 
      {
        final[++topf] = stack[top--];
      }
      top--;
    }
    else if (precedence(exp[i])>precedence(stack[top]))
    {
      stack[++top] = exp[i];
    }
    else if (precedence(exp[i])<precedence(stack[top]))
    {
      while(top >= 0 && precedence(exp[i])<precedence(stack[top]))
      {
        final[++topf] = stack[top--];
      }
      stack[++top] = exp[i];
    }
  }

  while (top >= 0)
  {
    final[++topf] = stack[top--];
  }

  for (int i = topf; i >=0; i--) 
  {
    printf("%c",final[i]);
  }
  return 0;
}
