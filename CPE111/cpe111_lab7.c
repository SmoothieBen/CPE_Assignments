#include <stdio.h>
#define V 5



void warshall(int matrix[V][V]){
    int i, j, k;
    for(k = 0;k<V;k++){
        for(i = 0;i<V;i++){
            for(j = 0;j<V;j++){
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
}

int main() {
    int matrix[V][V] = 
    {
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 0}
    };

    warshall(matrix);
    
    // Print result
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}