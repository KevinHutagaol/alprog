#include <stdio.h>
#include <string.h>


typedef struct PlayerRank {
    char rank_name[100];
    int value;
} PlayerRank;

void display_player_ranks(PlayerRank *playerRank, size_t array_size);

int get_rank_value(const char *rank);

int compare_player_rank(const PlayerRank *rank1, const PlayerRank *rank2);

void swap(void *x, void *y, size_t size);

void quick_sort(void *arr, size_t member_size, int array_size, int (*compare)(const void *, const void *));

void quick_sort_internal(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *));

int partition(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *));

void bubble_sort(PlayerRank array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (compare_player_rank(&array[i], &array[i + 1]) > 0) {
                PlayerRank temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void bubble_sort_generic(void *array, size_t member_size, int array_size, int (*compare)(const void *, const void *)) {
    for (int step = 0; step < array_size - 1; ++step) {
        for (int i = 0; i < array_size - step - 1; ++i) {
            void *arr1 = &array[i * member_size];
            void *arr2 = &array[(i + 1) * member_size];

            if (compare(arr1, arr2) > 0) {
                char temp[member_size];
                memcpy(temp, arr2, member_size);
                memcpy(arr2, arr1, member_size);
                memcpy(arr1, temp, member_size);
            }
        }
    }
}

int main() {
    PlayerRank players[] = {
        {"bronze", 2},
        {"diamond", 2},
        {"bronze", 1},
        {"gold", 2},
        {"gold", 3},
        {"silver", 1}
    };

    int member_size = sizeof(players[0]);
    int array_size = sizeof(players) / sizeof(players[0]);

    display_player_ranks(players, array_size);

    bubble_sort_generic(players, member_size, array_size, compare_player_rank);

    printf("\nSorted Ranks:\n");

    display_player_ranks(players, array_size);
}

void display_player_ranks(PlayerRank *playerRank, size_t array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d. Rank: %s %d\n", i + 1, playerRank[i].rank_name, playerRank[i].value);
    }
}

int get_rank_value(const char *rank) {
    if (strcmp(rank, "bronze") == 0) return 0;
    if (strcmp(rank, "silver") == 0) return 1;
    if (strcmp(rank, "gold") == 0) return 2;
    if (strcmp(rank, "diamond") == 0) return 3;
    return -1;
}

int compare_player_rank(const PlayerRank *rank1, const PlayerRank *rank2) {
    // ascending
    if (get_rank_value(rank1->rank_name) > get_rank_value(rank2->rank_name)) return 1;
    if (get_rank_value(rank1->rank_name) < get_rank_value(rank2->rank_name)) return -1;

    // descending
    if (rank1->value > rank2->value) return -1;
    if (rank1->value < rank2->value) return 1;

    return 0;
}

void swap(void *x, void *y, size_t size) {
    char temp[size];
    memcpy(temp, y, size);
    memcpy(y, x, size);
    memcpy(x, temp, size);
}

void quick_sort(void *arr, size_t member_size, int array_size, int (*compare)(const void *, const void *)) {
    quick_sort_internal(arr, member_size, 0, array_size - 1, compare);
}

void quick_sort_internal(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *)) {
    if (low < high) {
        int pivot_index = partition(arr, member_size, low, high, compare);

        quick_sort_internal(arr, member_size, low, pivot_index - 1, compare);
        quick_sort_internal(arr, member_size, pivot_index + 1, high, compare);
    }
}

int partition(void *arr, size_t member_size, int low, int high, int (*compare)(const void *, const void *)) {
    void *pivot = arr + high * member_size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr + (j * member_size), pivot) < 0) {
            i++;
            swap(arr + i * member_size, arr + j * member_size, member_size);
        }
    }

    swap(arr + (i + 1) * member_size, arr + high * member_size, member_size);

    return i + 1;
}
