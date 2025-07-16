#include<stdio.h>
    int add(int a,int b);
    int sub(int a,int b);
    int div(int a,int b);
    int mul(int a,int b);

int main()
{
    int num1,num2,result,choice;
    printf("----------MENU-----------\n");
    printf("1.add\n2.sub\n3.div\n4.mul\n");
    printf("enter your choice::");
    scanf("%d",&choice);
    printf("enter num1::");
    scanf("%d",&num1);
    printf("enter num2::");
    scanf("%d",&num2);
    printf("------------------\n");
    switch (choice)
    {
    case 1:
        result=add(num1,num2);
        printf("result=%d\n",result);
        break;
     case 2:
        result=sub(num1,num2);
        printf("result=%d\n",result);
        break;
    case 3:
        result=div(num1,num2);
        printf("result=%d\n",result);
        break;
    case 4:
        result=mul(num1,num2);
        printf("result=%d\n",result);
        break;
    default:
        printf("invalid choice.\n");
        break;
    }
    return 0;
}
int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int div(int a, int b)
{
    return a/b;
}
int mul(int a, int b)
{
    return a*b;
}