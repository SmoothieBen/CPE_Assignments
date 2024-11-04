//ข้อ 6
#include <stdio.h>

int main() {
    int arr[10];
    int score, min, student;
    printf("Enter student score (type -1 to start calculation)\n");
    for (int i=0; i<10; i++){
        printf("Enter score of student %d: ",i+1);
        scanf("%d", &score);
        
        if (score == -1){
            break;
        }
        if (i==0) {
            min = score;
            student = i+1;
        }
        if (score < min) {
            min = score;
            student = i+1;
        }
        arr[i] = score;
    }
    printf("The minimum score is %d\n", min);
    printf("Student %d has minimum score", student);
}
//-----------------------------------------------------------------------------------------------------------------------------

//ข้อ 7
#include <stdio.h>


int main() {
    char arr[100];
    int i=0, key = 0;
    printf("Enter a word: ");
    fgets(arr, 100, stdin);

    while (arr[i] != '\0') {
        if (arr[i] == 'a' ) {
            key = key + 1;
        }
        i++;
    }
    printf("Total number of 'a' is %d.", key);
}
//--------------------------------------------------------------------------------------------------------------------------

// ข้อ 8
#include <stdio.h>
int main() {
    int row1, col1, row2, col2;
    
    printf("Matrix Addition\n");
    printf("Enter matrix dimension of M1 (rows columns): ");
    scanf("%d %d",&row1, &col1);
    int M1[row1][col1];
    printf("Enter M1 matrix elements:\n");
    for (int i=0; i<row1; i++ ) {
        for (int j=0; j<col1; j++){
            scanf("%d", &M1[i][j]);   
        }
    }
    
    printf("Enter matrix dimension of M2 (rows columns): ");
    scanf("%d %d",&row2, &col2);
    int M2[row2][col2];
    printf("Enter M2 matrix elements:\n");
    for (int i=0; i<row2; i++ ) {
        for (int j=0; j<col2; j++){
            scanf("%d", &M2[i][j]);   
        }
    }
    
    if (row1!= row2 || col1 != col2) {
        printf("Invalid matrices dimension. The 2 matrices must have the same dimension.");
        return 0;
    }
    
    printf("Resultant of Matrix Ma (M1 + M2):\n");
    for (int i=0; i<row1;i++) {
        for(int j=0; j<col1; j++) {
            printf("%d ", M1[i][j] + M2[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------

// ข้อ 9

#include <stdio.h>

int main() {
    int row1, col1, row2, col2, row, col;
    printf("Matrix Multiplication\n");
    printf("Enter matrix dimension of M1 (rows columns): ");
    scanf("%d %d", &row1, &col1);
    int M1[row1][col1];
    printf("Enter M1 matrix elements:\n");
    for(int i=0; i<row1; i++) {
        for (int j=0; j<col1; j++) {
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Enter matrix dimension of M2 (rows columns): ");
    scanf("%d %d", &row2, &col2);
    int M2[row2][col2];
    printf("Enter M2 matrix elements:\n");
    for(int i=0; i<row2; i++) {
        for (int j=0; j<col2; j++) {
            scanf("%d", &M2[i][j]);
        }
    }

    if (col1 == row2) {
        row = row1;
        col = col2;
        int M[row][col];

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                M[i][j] = 0;
            }
        }

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                for (int k=0; k<col1; k++) {
                    M[i][j] += M1[i][k] * M2[k][j]; 
                }
            }
        }

        printf("Resultant of Matrix Mb (M1 * M2):\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        } 
    } else {
        printf("Invalid matrices dimension. Number of columns in M1 must equal to the number of rows in M2."); 
    }

    return 0;
}