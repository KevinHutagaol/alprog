#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN_BUF_SIZE 8
#define MAX_STR_SIZE 256


typedef struct {
    char name[MAX_STR_SIZE];
    char npm[MAX_STR_SIZE];
    char address[MAX_STR_SIZE];
} PersonalInformation;

typedef struct {
    int semester;
    float gpa;
    char major[MAX_STR_SIZE];
} AcademicInformation;

typedef struct {
    PersonalInformation personal_information;
    AcademicInformation academic_information;
    char activities[MAX_STR_SIZE];
} Student;

int editor(Student **student_data_arr, int *num_students);

void print_student_data(Student **student_data_arr, int num_students);

void add_student_data(Student **student_data_arr, int *num_students);

int main() {
    int current_buffer_size = MIN_BUF_SIZE;
    Student *student_database = (Student *) malloc(current_buffer_size * sizeof(Student));
    if (student_database == NULL) {
        printf("Memory allocation error\n");
        return -1;
    }

    int num_students = 0;
    for (;;) {
        if (num_students == current_buffer_size) {
            current_buffer_size = current_buffer_size + (current_buffer_size / 2);
            void *temp = realloc(student_database, current_buffer_size * sizeof(Student));
            if (temp == NULL) {
                printf("Memory allocation error\n");
                free(student_database);
                exit(1);
            }
            student_database = temp;
        }

        int loop_flag = editor(&student_database, &num_students);
        if (loop_flag == 0) {
            break;
        }
    }

    free(student_database);
    return 0;
}


int editor(Student **student_data_arr, int *num_students) {
    printf("----------------\n");
    printf("Student Database\n");
    printf("----------------\n");
    printf("  1. Show students data\n");
    printf("  2. New student\n");
    printf("  3. Exit\n");

    int choice = 0;
    printf("Enter option: ");
    scanf(" %d", &choice);

    while (getchar() != '\n') {
    }

    switch (choice) {
        case 1:
            print_student_data(student_data_arr, *num_students);
            break;
        case 2:
            add_student_data(student_data_arr, num_students);
            break;
        case 3:
            printf("Exiting editor........\n\n");
            return 0;
        default:
            printf("Invalid Choice, try again\n\n");
    }

    return 1;
}

void add_student_data(Student **student_data_arr, int *num_students) {
    char buffer[MAX_STR_SIZE];
    printf("Enter student's data:\n");

    printf("  Name: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].personal_information.name, buffer);

    printf("  NPM: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].personal_information.npm, buffer);

    printf("  Address: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].personal_information.address, buffer);

    printf("  Major: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].academic_information.major, buffer);

    printf("  Semester: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    (*student_data_arr)[*num_students].academic_information.semester = strtol(buffer, NULL, 10);

    printf("  GPA : ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    (*student_data_arr)[*num_students].academic_information.gpa = strtof(buffer, NULL);

    printf("  Activities: ");
    fgets(buffer, MAX_STR_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    strcpy((*student_data_arr)[*num_students].activities, buffer);

    *num_students += 1;
}

void print_student_data(Student **student_data_arr, const int num_students) {
    printf("Data of students:\n");
    printf("----------------\n");
    if (num_students == 0) {
        printf("Empty student data\n\n");
        return;
    }
    for (int i = 0; i < num_students; i++) {
        printf("%d %s - %s\n", i + 1, (*student_data_arr)[i].personal_information.name,
               (*student_data_arr)[i].personal_information.npm);
        printf("  Address: %s\n", (*student_data_arr)[i].personal_information.address);
        printf("  Major: %s\n", (*student_data_arr)[i].academic_information.major);
        printf("  Semester: %d\n", (*student_data_arr)[i].academic_information.semester);
        printf("  GPA: %.2f\n", (*student_data_arr)[i].academic_information.gpa);
        printf("  Activities: %s\n", (*student_data_arr)[i].activities);
        printf("\n");
    }
}
