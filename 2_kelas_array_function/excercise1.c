#include <stdio.h>

unsigned long long factorialRecursive(int n);
unsigned long long factorialForLoop(int n);

int main(void) {
    printf("Enter number: ");
    int number;
    scanf("%d", &number);

    unsigned long long ans1 = factorialRecursive(number);
    unsigned long long ans2 = factorialForLoop(number);

    printf("%d! %-20s = %llu\n", number, "(recursive function)", ans1 );
    printf("%d! %-20s = %llu", number, "(for loop)", ans2 );
    
    return 0;
}

unsigned long long factorialRecursive(int n) 
{
    if (n == 1) {
        return 1;
    }
    return n * factorialRecursive(n-1);
}

unsigned long long factorialForLoop(int n)
{   
    unsigned long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans*i;
    }
    return ans;
}
