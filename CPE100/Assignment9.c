// ข้อที่ 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[10];
    int score;    
}Student;


void insertionSort(Student *students, int numStudents) {
    for (int i = 1; i < numStudents; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].score > key.score) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

int main(){
    int numStudents;
    printf("Enter a number of students in the class: ");
    scanf(" %d", &numStudents);
    Student *students = (Student *)malloc(numStudents * sizeof(Student));

    char file_path[100];
    printf("Enter a file name to load student scores: ");
    scanf(" %s", file_path);
    FILE *file;
    file = fopen(file_path,"r");
    if (file == NULL) {
        printf("Error opening file %s.\n", file_path);
        free(students);
        return 1;
    }

    int i = 0;
    for (i = 0; i < numStudents && fscanf(file, "%s %d", students[i].name, &students[i].score) == 2; i++) {
        printf("Loaded Student %d: %s, Score = %d\n", i + 1, students[i].name, students[i].score);
    }
    numStudents = i;
    fclose(file);

    int end = 0;
    while (!end) {
        char name[10];
        printf("Enter new student name (type 'END' to sort student score and end the program): ");
        scanf("%s", name);

        if (strcmp(name, "END") == 0) {
            end = 1;
        } else {
            int score;
            printf("Enter %s's score: ", name);
            scanf("%d", &score);

            students = (Student *)realloc(students, (numStudents + 1) * sizeof(Student));
            if (students == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }

            strcpy(students[numStudents].name, name);
            students[numStudents].score = score;
            numStudents++;
        }
    }

    printf("---------------Sort students by scores---------------\n");
    insertionSort(students, numStudents);
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: %s, Score = %d\n", i + 1, students[i].name, students[i].score);
    }
    
    free(students);
    printf("End of program. Goodbye.\n");
    return 0;
}

// ข้อที่ 2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[10];
    int score;    
}Student;

void insertionSort(Student *students, int numStudents) {
    for (int i = 1; i < numStudents; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].score > key.score) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

int main(){
    int numStudents;
    printf("Enter a number of students in the class: ");
    scanf(" %d", &numStudents);
    int max_student = numStudents;
    Student *students = (Student *)malloc(numStudents * sizeof(Student));

    char file_path[100];
    printf("Enter a file name to load student scores: ");
    scanf(" %s", file_path);
    FILE *file;
    file = fopen(file_path,"r");
    if (file == NULL) {
        printf("Error opening file %s.\n", file_path);
        free(students);
        return 1;
    }

    int i = 0;
    for (i = 0; i < numStudents && fscanf(file, "%s %d", students[i].name, &students[i].score) == 2; i++) {
        printf("Loaded Student %d: %s, Score = %d\n", i + 1, students[i].name, students[i].score);
    }
    numStudents = i;
    fclose(file);

    int end = 0;
    while (!end) {
        char name[10];
        printf("Enter new student name (type 'END' to sort student score and end the program): ");
        scanf("%s", name);

        if (strcmp(name, "END") == 0) {
            end = 1;
        } else {
            if(numStudents+1 > max_student){
                printf("Cannot add %s into the student list. The number of students cannot exceed %d. Please type 'END' to sort student score and end the program.\n", name, numStudents);
            }
            else{  
                int score;
                printf("Enter %s's score: ", name);
                scanf("%d", &score);

                students = (Student *)realloc(students, (numStudents + 1) * sizeof(Student));
                if (students == NULL) {
                    printf("Memory reallocation failed.\n");
                    return 1;
                }

                strcpy(students[numStudents].name, name);
                students[numStudents].score = score;
                numStudents++;
            }
        }
    }

    printf("---------------Sort students by scores---------------\n");
    insertionSort(students, numStudents);
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: %s, Score = %d\n", i + 1, students[i].name, students[i].score);
    }
    
    free(students);
    printf("End of program. Goodbye.\n");
    return 0;
}