//ข้อที่ 5
#include <stdio.h>
int main() {
    int n,m; // n = start num, m = end num
    char ans;
    do {
        printf("Enter start number: ");
        scanf("%d", &n);
        printf("Enter end number: ");
        scanf("%d", &m);

        int counter = 1;
        while (counter <= n) {
            int i =n;
            while(i <= m) {
                printf("%d ", i*counter);
                i++;
            }
            counter++;
            printf("\n");
        }
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ans);
    } while (ans != 'n');
    printf("End of program. Goodbye.");
}


#include <stdio.h>
int main() {
    int n, m;
    char ans = 'y';
    while (ans == 'y') {
        printf("Enter start number: ");
        scanf("%d", &n);
        printf("Enter end number: ");
        scanf("%d", &m);

        int counter = 1;
        while (counter <= n) {
            int i =n;
            while(i <= m) {
                printf("%d ", i*counter);
                i++;
            }
            counter++;
            printf("\n");
    }
    printf("Do you want to continue (y/n)? ");
    scanf(" %c", &ans);

}
printf("End of program. Goodbye.");
}


//ข้อ 5

#include <stdio.h>
#include <math.h>

int main (){
    int score[100];
    int i, count = 0;
    int sum = 0;
    float avg = 0.0, temp = 0.0, sd = 0.0;
    printf("Input student scores (type -1 to start calculation)\n");
    for (i = 0; i<100; i++){
        printf("Enter score of student %d: ", i+1);
        scanf("%d", &score[i]);
        

        if (score[i] == -1) {
            break;
        }
        sum += score[i];
        count++;
        
    }
    
    if (count > 0) {
        avg = (float)sum / count;

        for (i = 0; i < count; i++) {
            temp += pow(score[i] - avg, 2);
        }
        temp /= count;
        sd = sqrt(temp);
        printf("Mean score of %d students = %.1f, SD = %.2f", count, avg ,sd);
    }
    return 0;
}




