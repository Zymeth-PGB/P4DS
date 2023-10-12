#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Multiply two matrix
void mul_matrix(int n, long long matrix1[][n], long long matrix2[][n], long long matrix[][n]) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }

    int i = 0, h = 0;

    while(i != n) {
        int temp = 0;
        for(int j = 0; j < n; ++j) {
            temp += matrix1[i][j] * matrix2[j][h];
        }
        matrix[i][h] = temp;
        h++;
        if(h == n) {
            h = 0;
            i++;
        }
    }
}

double solve() {
    FILE *fp = NULL;

    // Open file 
    fp = fopen("generate_matrix.txt", "r");

    // Read size of matrix
    int n;
    fscanf(fp, "%d\n", &n);

    long long matrix1[n][n], matrix2[n][n], matrix[n][n];

    // Read matrix A
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fscanf(fp, "%d ", &matrix1[i][j]);
        }
    }
    
    // Read matrix B
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            fscanf(fp, "%d ", &matrix2[i][j]);
        }
    }

    clock_t start, end;
    // Record start time
    start = clock();

    mul_matrix(n, matrix1, matrix2, matrix);

    // Record end time
    end = clock();

    // Calculate runtime of function multiply two matrix
    double duration = ((double)end - start) / ((double)CLOCKS_PER_SEC);

    fclose(fp);
    
    return duration;
}

int main() {

    double duration = solve();
    
    printf("%0.10f", duration);

    return 0;
}
