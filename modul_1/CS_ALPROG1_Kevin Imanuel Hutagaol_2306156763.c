#include <stdio.h>

void calculator(void);

int main(void) { 
    printf("----Welcome to Brainrot Calculator----\n");
    calculator();
}

void calculator() 
{   
    for(;;) { 
        printf("=====Menu=====\n");
        printf("1. Tambah\n");
        printf("2. Kurang\n");
        printf("3. Kali\n");
        printf("4. Quit\n");

        int option;
        printf("Select Operator: ");
        scanf("%d", &option);
        if (option == 4) { 
            printf("Quitting Calculator, Thank You!!!!");
            break;
        }
        int num1, num2;
        int ans = 0;

        switch (option)
        {
        case 1:
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            ans = num1 + num2;
            break;

        case 2:
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            ans = num1 - num2;
            break;

        case 3:
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
            ans = num1 * num2;
            break;
        
        default:
            printf("Wrong input! try again\n");
            break;
        }


        for (int i = 0; i < ans; i++) { 
            for (int j = 0; j < ans; j++) { 
                if (i == ans -1 || j == 0){ 
                    printf("*");
                } 
                else { 
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}