// Fibonacci 5

#include <stdio.h>

int fibonacci(int n) {
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i=1; i<=n; i++) {
        printf("%d ", fibonacci(i));
    }
}
//------------------------------------------------------------------------------------------------------

// Linear search 6

#include <stdio.h>

int arr[15] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
int search(int i, int j, int x){
    if (arr[i] == x)
        return i+1;
    else if (i == j)
        return -1;
    else 
        return search(i+1, j, x);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", search(0,14,n));
}
//------------------------------------------------------------------------------------------------------

// Binary search

#include<stdio.h>

int arr[15] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29};
int binary_search(int i, int j, int x) {
    int m = (i+j) / 2;
    if (x == arr[m])
        return m+1;
    else if (x < arr[m] && i < m)
        return binary_search(i,m-1,x);
    else if (x > arr[m] && j > m)
        return binary_search(m+1,j,x);
    else 
        return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", binary_search(0,14,n));
}




