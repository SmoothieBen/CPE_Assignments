// ข้อที่ 1 ----------------------------------------------------------------
#include <stdio.h>
#include <string.h>

int main() {
    FILE *input, *output;
    int i = 0, min = 1000, max = 0;
    int score[10];
    char name[10][10];
    char fname[10];
    float avg = 0, sum;

    printf("Enter a file name to load student scores: ");
    scanf("%s", &fname);

    input = fopen(fname, "r");
    output = fopen("./stat.txt", "w");

    while (fscanf(input, "%s %d ", name[i], &score[i]) != EOF) {
        i++;
    }
    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j+1, name[j], score[j]);
        sum += score[j];
        if (score[j] < min) {
            min = score[j];
        }
        if (score[j] > max) {
            max = score[j];
        }
    }
    avg = sum / i;
    printf("Average score is %.0f\n", avg);
    printf("Minimum score id %.d\n", min);
    printf("Maximum score id %.d\n", max);

    fprintf(output, "Average score is %.0f\n", avg);
    fprintf(output, "Minimum score id %.d\n", min);
    fprintf(output, "Maximum score id %.d\n", max);

    printf("Save statistics in file stat.txt successfully.\n");
    printf("End of program. Goodbye.");
    return 0;
}

// ข้อที่ 2 ------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

typedef struct {
    int score;
    char name[20];
} Data;

void swapData(Data *a, Data *b);
void selectionSort(Data data[], int count);

int main() {
    Data data[20];
    FILE *input, *output;
    int i = 0;
    char fname[10];

    printf("Enter a file name to load student scores: ");
    scanf("%s", fname);

    input = fopen(fname, "r");
    if (input == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    while (fscanf(input, "%s %d ", data[i].name, &data[i].score) != EOF) {
        i++;
    }
    fclose(input);

    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j+1, data[j].name, data[j].score);
}
    while(1) {
        printf("Enter new student name (type 'END' to sort student score and end the program): ");
        scanf("%s", data[i].name);
        if (strcmp(data[i].name, "END")==0) {
            break;
        }
        printf("Enter %s's score: ", data[i].name);
        scanf("%d", &data[i].score);
        i++;
    }

    printf("------------------Sort students by scores-------------------\n");
    selectionSort(data, i);

    output = fopen(fname, "w");
    if (output == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int j = 0; j < i; j++) {
        printf("Student %d: %s, Score = %d\n", j+1, data[j].name, data[j].score);
        fprintf(output, "%s %d\n", data[j].name, data[j].score);
}
fclose(output);
return 0;
}

void swapData(Data *a, Data *b) {
    Data tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(Data data[], int count) {
    int i, j, minpos;
    for (i=0; i < count -1; i++) {
        minpos = i;
        for (j = i +1; j < count ; j++) {
            if (data[j].score < data[minpos].score)
            minpos = j;
        }
        swapData(&data[i], &data[minpos]);
    }
}




