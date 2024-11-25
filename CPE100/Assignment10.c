//ข้อที่ 1.1
#include <stdio.h>

int isAllDigit (char string[]) {
    while (*string != '\0') {
        if(*string < '0' || *string > '9') {
            return 0;
        }
        string++;
    }
    return 1;
} 

int main() {
    char someString[10] = "123456";
    if (isAllDigit(someString))
        printf("All digit");
    else 
        printf("Not all digit");
        return 0;
}

//---------------------------------------------------------------------------
//ข้อที่ 1.2

#include <stdio.h>

int isAllDigit (char string[]) {
    while (*string != '\0') {
        if(*string < '0' || *string > '9') {
            return 0;
        }
        string++;
    }
    return 1;
} 

int main() {
    char someString[10] = "123456";
    if (isAllDigit(someString))
        printf("All digit");
    else 
        printf("Not all digit");
        return 0;
}

//------------------------------------------------------------------------------
//ข้อที่ 1.3

#include <stdio.h>

int isAllDigit (char string[]) {
    if (string[0] == 'E' && string[1] == 'N' && string[2] == 'D' && string[3] == '\0') {
        return -1;
    }
    while (*string != '\0') {
        if (*string < '0' || *string > '9') {
            return 0;
        }
        string++;
    }
    return 1;
}

void getInput() {
    char stringPass[100][100];
    int i = 0;
    printf ("Enter strings (type 'END' to stop):\n");
    while (1){
        scanf("%s", stringPass[i]);
        int result = isAllDigit(stringPass[i]);

        if(result == -1) {
            break;
        }
        if (result == 1) {
            printf("String %d: All digit\n", i+1);
        } else {
            printf("String %d: Not all digit\n", i+1);
        }
        i++;
    }
}

int main() {
    getInput();
    return 0;
}

//-------------------------------------------------------------------------
//ข้อที่ 2.1

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guessNumber;
    srand(time(NULL));
    number = rand()%100+1;
    printf("Number Guesser!!\n");
    printf("Guess the number: ");
    for (int i=0; i<=7;i++) {
        scanf("%d", &guessNumber);
        if (i==7) {
            printf("You are out of guess!! END of program.");
            break;
        }
        if (guessNumber > number) {
            printf("You have %d guess left.\n", 6-i);
            printf("Incorrect!!, Guess less than it: \n");
        } 
        else if (guessNumber < number) {
            printf("You have %d guess left.\n", 6-i);
            printf("Incorrect!!, Guess more than it: \n");
        }
        else {
            printf("You are correct!! END of Program.");
            break;
        }
    }
    return 0;
}

//----------------------------------------------------------------------
//ข้อที่ 2.2

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int correctNumber;
    int guess[7];
    int totalGuesses;
} GameRound;

GameRound guessNumber() {
    GameRound round;
    round.totalGuesses = 0;
    
    int number, guessNumber;
    srand(time(NULL));
    number = rand() % 100 + 1;
    round.correctNumber = number;

    printf("Number Guesser!!\n");
    printf("Guess the number: ");

    for (int i=0;i<7;i++) {
        scanf("%d", &guessNumber);
        round.guess[round.totalGuesses++] = guessNumber;

        if (guessNumber > number) {
            printf("You have %d guess left.\n", 6-i);
            printf("Incorrect!!, Guess less than it: \n");
        } 
        else if (guessNumber < number) {
            printf("You have %d guess left.\n", 6-i);
            printf("Incorrect!!, Guess more than it: \n");
        }
        else {
            printf("You are correct!! END of Game.");
            break; 
         }  
    }
        if (round.totalGuesses == 7 && round.guess[6] != number) {
            printf("You are out of guesses!! The correct number was %d.\n", number);
         }
             return round;
     }

void scoreResult(int finalScore, GameRound rounds[], int totalRounds) {
    printf("\nYour Final Score is: %d\n", finalScore);

    for (int i = 0; i < totalRounds; i++) {
        printf("Round %d:\n", i + 1);
        printf("  Correct Number: %d\n", rounds[i].correctNumber);
        printf("  Your Guesses: ");
        for (int j = 0; j<rounds[i].totalGuesses; j++) {
            printf("%d ", rounds[i].guess[j]);
        }
        printf("\n");
    }
}

int main() {
    char status[10];
    int score = 0;

    GameRound rounds[100];
    int roundCount = 0;

    printf("Welcome to the Number Guessing Game!\n");

    while (1) {
        GameRound round = guessNumber();
        rounds[roundCount++] = round;

        if (round.guess[round.totalGuesses - 1] == round.correctNumber) {
            score++;
        }
        printf("Do you want to play again? (Type END to finish or any key to continue): ");
        scanf("%s", status);

        if(strcmp(status, "END") == 0) {
            break;
        }
    }

    scoreResult(score, rounds, roundCount);
    return 0;
}

//-----------------------------------------------------------------------------
//ข้อที่ 3

#include <stdio.h>

int findStringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int findSubString(char str1[], char str2[]) {
    int len1 = findStringLength(str1);
    int len2 = findStringLength(str2);

    for(int i=0; i <= len1 - len2;i++ ) {
        int j;
        for(j=0; j<len2; j++) {
            if (str1[i+j] != str2[j]) {
                break;
            }
        }
        if (j == len2) {
            return i;
        }
    }
    return -1;
}

int main() {
    char *string1 = "I love CPE";
    char *string2 = "love";

    int output = findSubString(string1,string2);

    if (output != -1)
    printf("Index of the first occurrence = %d\n", output);
    else
    printf("string2 is not a substring of string1\n");
    return 0;
} 

