#include <stdio.h>
#include <stdlib.h>

int main(void) { 
    int length;
    printf("Enter length of drawing:");
    scanf("%d", &length);

    int height_of_pyramid = 2*length - 1;
    int width_of_pyramid = length + 1;
 
    for (int i = 0; i < height_of_pyramid ; i++) { 
        for (int j = abs(width_of_pyramid - i - 2); j > 0; j--) { 
            printf(" ");
        }
        // ujung ujung jadi eksepsi:
        if (i == 0 || i == height_of_pyramid - 1) { 
            printf("*\n");
            continue;
        } 
        printf("*");
        for (int j = width_of_pyramid - 2 - abs(width_of_pyramid - 2 - i) ; j > 0; j--) { 
            printf(" ");
        }
        printf("*\n");
    }


    return 0;
}