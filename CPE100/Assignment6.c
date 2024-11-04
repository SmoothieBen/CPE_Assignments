//ข้อ 1

#include <stdio.h>

long int factorial (int n)
{
     int i;
     long int product = 1;
     for (i = n; i>1; i--)
          product *= i;
     return product;
}

long int combination (int n, int r)
{
     long int ans = 1;
     ans = factorial(n) / (factorial(r) * factorial(n-r)); 
     return ans; 
}

int main() 
{ 
     int n, r;
     int ans;
     printf("To calculate nCr, enter n and r: "); 
     scanf("%d %d", &n, &r); 
     ans = combination(n, r); 
     printf("\n%dC%d = %d", n, r, ans);
     return 0; 
}

//--------------------------------------------------------------------------------------------

//ข้อ 2

#include <stdio.h>

int findMinimum(int num1, int num2)
{
    if (num1 > num2)
        return num2;
    else 
        return num1;
}

void findMaximum(int num1, int num2)
{

    int max;
    if (num1 > num2)
        max = num1;
    else
        max = num2;
    printf("\nMaximum value is: %d", max);
}

int main()
{
    int num1, num2, option, min;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
    while (option != 3)
    {
        printf("\nChoose what to do from options below");
        printf("\n1. Find minimum");
        printf("\n2. Find maximum");
        printf("\n3. Exit program");
        printf("\nEnter option no. : ");
        scanf("%d", &option);
        if (option == 1)
        {
            min = findMinimum(num1, num2);
            printf("\nMinimum value is: %d", min);
        }
        else if (option == 2) {
            findMaximum(num1, num2);
        }
        else {
            printf("\nEnd of program. Goodbye.");
        }
    }
    return 0;
}
//-------------------------------------------------------------------------------------------------

//ข้อ 3

#include <stdio.h>
#include <string.h>

int max_student = 10;
int max_name_length = 8;

int main() {
    char Name[max_student][max_name_length + 1]; 
    int count = 0; 
    char input[max_name_length + 20];

    printf("Enter student names (type END to print all names)\n");

    while (count < max_student) {
        printf("Enter name of student %d: ", count + 1);
        scanf("%s", input);

        if (strcmp(input, "END") == 0) {
            break;
        }
        if (strlen(input) > max_name_length) {
            printf("The name is too long. Please try again.\n");
        } else {
            strcpy(Name[count], input);
            count++;
        }
    }
    printf("Name list: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", Name[i]);
    }
    printf("\n");
    if (count > 0) {
        char firstAlphabet[max_name_length + 1];
        strcpy(firstAlphabet, Name[0]);

        for (int i = 1; i < count; i++) {
            if (strcmp(Name[i], firstAlphabet) < 0) {
                strcpy(firstAlphabet, Name[i]);
            }
        }

        printf("The first order name sorted alphabetically: %s", firstAlphabet);
    }


    return 0;
}