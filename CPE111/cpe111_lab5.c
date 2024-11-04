// ข้อที่ 1
void insertionSort(int arr[], int n){
	int j = 1;
	while(j<n){
		int i = 0;
		int temp = arr[j];
		while (i < j && arr[i] < temp){
			i++;
		}
		int k = j;
		while(k>i){
			arr[k] = arr[k-1];
			k--;
		}
		arr[i] = temp;
		j++;
	}

}

int main() {
   int n = 11;
   int arr[] = {2, 8, 3, 39, 1, 25, 70, 5, 6, 10, 44};
   int i = 0;
   printf("unsorted array:\n");
   while (i < n) {
      printf("%d ", arr[i]);
      i++;     
   }

    printf("\n");
    
   
    insertionSort(arr, n);
    printf("Sorted array:\n");
    

    print("%d ",arr[0]);
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }

   return 0;
}


// ข้อที่ 2

#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() { 
   int n = 11;
   int arr[] = {2, 8, 3, 39, 1, 25, 70, 5, 6, 10, 44};
   int i = 0;
   printf("unsorted array:\n");
   while (i < n) {
      printf("%d ", arr[i]);
      i++;     
   }

   bubbleSort(arr, n);
   printf("\n");

   i = 0;
   printf("sort array:\n");
   while (i < n) {
      printf("%d ", arr[i]);
      i++;     
   }
   return 0;
}



#include <stdio.h>

int main() {
    int score[];
    int sum = 0;
    float avg = 0.0;
    int i;

    for (i=0; i<3; i++) {
        printf("Enter score of student %d\n", i+1 );
        scanf("%d", &score[i]);
        sum += score[i];

    } 
    avg = sum / 3;
    printf("The average score of 3 students is: %.3f",avg );
    return 0;
}



#include <stdio.h>

int main() {
    char str[100];  
    int count = 0;  
    printf("Enter a word: ");
    fgets(str, sizeof(str), stdin);
    
   
    while (str[count] != '\0') {
        count++;
    }

    
    if (str[count - 1] == '\n') {
        str[count - 1] = '\0';
        count--; 
    }

    printf("Total alphabets in '%s' = %d.", str,count);
    
    return 0;
}




