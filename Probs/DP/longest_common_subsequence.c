#include<stdio.h>
#include<stdlib.h>

int** longest_common_subsequence(int n, int m, int* x1, int* x2){
    int** dp_mat = (int**)malloc((n+1)*sizeof(int*));
    for (int i = 0; i < n+1; i++){
        dp_mat[i] = (int*)malloc((m+1)*sizeof(int));
    }

    for (int i = 0; i < n + 1; i++){
        dp_mat[i][0] = 0;
    }

    for (int j = 0; j < m + 1; j++){
        dp_mat[0][j] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j<=n; j++){
            if (x1[i] == x2[j]){
                dp_mat[i][j] = 1 + dp_mat[i-1][j-1];
            }
            else{
                int a = dp_mat[i-1][j];
                int b = dp_mat[i][j-1];
                if (a>b){
                    dp_mat[i][j] = a;
                }
                else {
                    dp_mat[i][j] = b;
                }
            }
        }
        return dp_mat;
    }
    for (int i = 0; i < n+1; i++){
        free(dp_mat[i]);
    }
    free(dp_mat);
}


int main(){
    int n = 3;
    int m = 3;
    int x_1[3] = {1,2,3};
    int x_2[3] = {3,2,1};
    int** out = longest_common_subsequence(n,m,&x_1, &x_2);
    for (int i = 0; i <n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ",out[i][j]);
        }
        printf("\n");
    }
    return 0;
}