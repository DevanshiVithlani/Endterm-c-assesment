#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

// Structure to store student details
struct Student {
    int roll;
    char name[50];
    char status;   // 'P' for Present, 'A' for Absent
};

int main() {
    struct Student s[MAX_STUDENTS];
    int n, i;
    FILE *fp;

    printf("---- Student Attendance Management System ----\n\n");

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid number of students!\n");
        return 1;
    }

    // Clear input buffer after scanf
    getchar();

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
        getchar();  // clear newline left by scanf

        // Input full name with spaces
        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);

        // Remove newline from fgets
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        // Mark attendance
        do {
            printf("Mark Attendance (P/A): ");
            scanf(" %c", &s[i].status);

            if (s[i].status != 'P' && s[i].status != 'A' &&
                s[i].status != 'p' && s[i].status != 'a') {
                printf("Invalid input! Enter only P or A.\n");
            }

        } while (s[i].status != 'P' && s[i].status != 'A' &&
                 s[i].status != 'p' && s[i].status != 'a');
    }

    // Save attendance to file
    fp = fopen("attendance.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "---- Attendance Record ----\n\n");
    fprintf(fp, "Roll\tName\t\tStatus\n");
    fprintf(fp, "----------------------------------\n");

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\t%-15s\t%c\n", s[i].roll, s[i].name, s[i].status);
    }

    fclose(fp);

    // Display attendance on screen
    printf("\nAttendance Recorded Successfully!\n");
    printf("\nRoll\tName\t\tStatus\n");
    printf("----------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%-15s\t%c\n", s[i].roll, s[i].name, s[i].status);
    }

    printf("\nAttendance saved in 'attendance.txt'.\n");

    return 0;
}
