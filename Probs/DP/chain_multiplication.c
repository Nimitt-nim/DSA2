#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int** chain_multiplication(int n, int* p){
    int dp_mat[n][n];
    int traceback[n][n];

    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < n; j++){
            dp_mat[i][j] = 0;
            traceback[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        dp_mat[i][i] = 0;
    }


    for (int l = 2; l <= n; l++){
        for (int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            dp_mat[i][j] = __INT_MAX__;
            for (int k = i; k < j; k++){
                if (dp_mat[i][k] + dp_mat[k+1][j] + p[i]*p[k+1]*p[j] < dp_mat[i][j]){
                    dp_mat[i][j] = dp_mat[i][k] + dp_mat[k+1][j] + p[i]*p[k+1]*p[j+1];
                    traceback[i][j] = k;
                }
            }
        }
    }


    int** t = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        t[i] = (int*)malloc(n * sizeof(int));
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            t[i][j] = traceback[i][j];
        }
    }
    return t;
}

void print_order(int** trace, int i, int j){
    if (i == j){
        return ;
    }

    int k = trace[i][j];
    print_order(trace, i, k);
    print_order(trace, k+1,j);
    if (k == i && k+1 == j){
        printf("(%d,%d)\n",i, j);
    }
    else if (k+1 == j){
        printf("(%d,%d)(%d)\n",i,k,j);
    }
    else if (k == i){
        printf("(%d)(%d,%d)\n",i,k+1,j);
    }
    else {
        printf("(%d,%d)(%d,%d)\n",i,k,k+1,j);
    }
}

char* print_order_2(int** trace, int i, int j) {
    int k = trace[i][j];
    char *left, *right;

    if (k == i && k+1 == j) {
        char* result = malloc(10);
        sprintf(result, "%d %d", i, j);
        return result;
    }
    else if (k+1 == j){
        char* left = print_order_2(trace, i, k);
        char* result = malloc(strlen(left) + 10);
        sprintf(result, "(%s)(%d)",left,j);
        free(left);  
        return result;
    }
    else if (k == i){
        char* right = print_order_2(trace, k+1, j);
        char* result = malloc(strlen(right)+10);
        sprintf(result, "(%d)(%s)",i,right);
        free(right); 
        return result;
    }
    else {
        char* left = print_order_2(trace, i, k);
        char* right = print_order_2(trace, k+1, j);
        char* result = malloc(strlen(right)+strlen(left) + 10);
        sprintf(result, "(%s)(%s)", left, right);
        free(left);  
        free(right); 
        return result;
    }
}

int main(){
    int n = 6;
    // {0,1,2,3,4}
    int p[6] = {2,3,41,5,6,45};
    int** dp_m = chain_multiplication(n-1, p);
    printf("Order of Multiplications Steps form :\n");
    print_order(dp_m, 0, n-2);
    printf("\n");
    printf("Order of Multiplications Braces form :\n");
    printf("%s",print_order_2(dp_m, 0, n-2));
    for (int i = 0; i < n-1; i++){
        free(dp_m[i]);
    }
    free(dp_m);
    return 0;
}