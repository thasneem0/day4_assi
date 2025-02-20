university record manaegment'
#include <stdio.h>

struct student {
    int rollno;
    char name[200];
    char course[100];
    int marks;
};
typedef struct student s;

void readstudents(s stu[], int n);
void displaystudents(s stu[], int n);
void searchstudent(s stu[], int n, int roll);
void saveToFile(s stu[], int n);

int main() {
    int num;
    printf("Enter number of students: ");
    scanf("%d", &num);

    s students[1000];

    readstudents(students, num);
    displaystudents(students, num);
    saveToFile(students, num);

    int roll;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);
    searchstudent(students, num, roll);

    return 0;
}

void readstudents(s stu[], int n) {
    printf("Enter details of the students (Roll No, Name, Course, Marks):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d %s %s %d", &stu[i].rollno, stu[i].name, stu[i].course, &stu[i].marks);
    }
}

void displaystudents(s stu[], int n) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, Course: %s, Marks: %d\n", stu[i].rollno, stu[i].name, stu[i].course, stu[i].marks);
    }
}

void searchstudent(s stu[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (stu[i].rollno == roll) {
            printf("Student Found: %s, %s, Marks: %d\n", stu[i].name, stu[i].course, stu[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

void saveToFile(s stu[], int n) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %s, %d\n", stu[i].rollno, stu[i].name, stu[i].course, stu[i].marks);
    }
    fclose(file);
    printf("Record saved in \"students.txt\"\n");
}
