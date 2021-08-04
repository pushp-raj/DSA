#include<stdio.h>
int add(int num)
{
    if(num!=0)
        return num + add(num-1);
    else    
        return num;
}
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int result = add(n);
    printf("Sum is : %d",result);
    return 0;
}