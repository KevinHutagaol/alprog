#include "stdio.h"
#include "myheader.h"

void add(int a, int b)
{
	printf("\nAdded value=\n%d\n", a + b);
}
void multiply(int a, int b)
{
    printf("\nMultiplied value=\n%d\n", a * b);
}

void div(int a, int b)
{
    printf("\nDivided value=\n%d\n", a / b);
}

void sub(int a, int b)
{
    printf("\nsubtracted value=\n%d\n", a - b);
}

void modu(int a, int b)
{
    printf("\nmodulo value=\n%d\n", a % b);
}
