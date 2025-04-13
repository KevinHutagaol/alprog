#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    char *category;
} Product;

void search_keyword(Product **products, char* keyword, char* category, int num_product);

int main() {
    printf("Masukan Jumlah Produk:");
    int num_products;
    scanf(" %d", &num_products);
    while (getchar() != '\n') {
    }
    printf("\n");
    Product* products = malloc(sizeof(Product) * num_products);
    if (products == NULL) {
        printf("Error allocating memory");
        exit(-1);
    }

    for (int i = 0; i < num_products; i++) {
        char buffer[128];
        printf("Enter name of product %d: ", i + 1);
        fgets(buffer, 128, stdin);
        buffer[strcspn(buffer, "\r\n")] = 0;
        products[i].name = malloc(strlen(buffer) + 1);
        strcpy(products[i].name, buffer);

        printf("Enter category of product %d: ", i + 1);
        fgets(buffer, 128, stdin);
        buffer[strcspn(buffer, "\r\n")] = 0;
        products[i].category = malloc(strlen(buffer) + 1);
        strcpy(products[i].category, buffer);

        printf("\n");
    }

    printf("Enter keyword to search: ");
    char key_word[128];
    fgets(key_word, 128, stdin);
    key_word[strcspn(key_word, "\r\n")] = 0;


    printf("Enter category to search: ");
    char category[128];
    fgets(category, 128, stdin);
    category[strcspn(key_word, "\r\n")] = 0;


    search_keyword(&products, key_word, category, num_products);

    free(products);
    return 0;
}

void search_keyword(Product **products, char* keyword, char* category, int num_product) {
    int found = 0;
    for (int i = 0; i < num_product; i++) {
        char* name_lowercase = (*products)[i].name;
        for (int j = 0; j < strlen(name_lowercase); j++) {
            name_lowercase[j] = tolower(name_lowercase[j]);
        }

        char* keyword_lowercase = keyword;

        for (int j = 0; j < strlen(keyword_lowercase); j++) {
            keyword_lowercase[j] = tolower(keyword_lowercase[j]);
        }

        char* product_category_lowercase = (*products)[i].category;
        for (int j = 0; j < strlen(product_category_lowercase); j++) {
            product_category_lowercase[j] = tolower(product_category_lowercase[j]);
        }

        char* category_lowercase = category;
        for (int j = 0; j < strlen(category_lowercase); j++) {
            category_lowercase[j] = tolower(category_lowercase[j]);
        }

        char* found = strstr(name_lowercase, keyword_lowercase);
        if (found) {
            printf("Products with keyword %s and category %s\n", keyword, category);
            if (strcmp(product_category_lowercase, category_lowercase) != 0) {
                printf("%d. %s", i + 1, (*products)[i].name);
            }
        }
    }
}












