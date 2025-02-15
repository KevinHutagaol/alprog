#include <stdio.h>
#include "myheader.h"
int main()
{
    int num1, num2;
    
	printf("input first integer numbers\n");
	scanf("%d",&num1);
	printf("input second integer numbers\n");
	scanf("%d",&num2);
	
	add(num1, num2);
	multiply(num1, num2);
	div(num1, num2);
  	sub(num1, num2);
  	modu(num1, num2);
  
    // Same for the multiply function in myhead.h
    printf("\nYour first user defined function was successfully created\n");
    return 0;
}
