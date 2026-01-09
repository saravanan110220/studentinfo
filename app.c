#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

void addStudent(struct Student students[], int *count) {
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    students[*count] = s;
    (*count)++;
}

void displayStudents(struct Student students[], int count) {
    int i;
    printf("\n--- Student List ---\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-------------------\n");
    }
}

void searchStudent(struct Student students[], int count) {
    int id, i, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

void updateStudent(struct Student students[], int count) {
    int id, i, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", students[i].name);
            printf("Enter new Age: ");
            scanf("%d", &students[i].age);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    struct Student students[100];
    int count = 0;
    int choice;
    while (1) {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}