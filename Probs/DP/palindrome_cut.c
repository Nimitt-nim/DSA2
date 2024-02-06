#include<stdlib.h>
#include<stdio.h>

int check_palindrome(int* arr, int i, int j){
    while (i<j){
        if (arr[i] != arr[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void print_mat(int** arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int palindrome_cut(int* arr, int n){
    int** M = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        M[i] = (int*)malloc(n*sizeof(int));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            M[i][j] = -1;
        }
    }
        for (int i = 0; i < n; i++){
        M[i][i] = 0;
    }

    for (int l = 2; l <= n; l++){
        for (int i = 0; i < n - l + 1; i++){

            int j = i + l - 1;
            if (check_palindrome(arr, i , j)){
                M[i][j] = 0;
            }
            else {
                int min = 100;
                for (int k = i; k < j; k++){
                    if (M[i][k] + M[k+1][j] + 1 < min){
                        min = M[i][k] + M[k+1][j] + 1;
                    }
                }
                M[i][j] = min;
            }
        }
        
    }

    int ans = M[0][n-1]; 
    for (int i = 0; i < n; i++){
        free(M[i]);
    }
    free(M);

    return ans;
}

int main(){
    int n = 5;
    int arr[5] = {1,2,1,0,1};
    int m = palindrome_cut(arr, n);
    printf("%d",m);
    return 0;
}