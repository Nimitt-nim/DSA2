#include<stdio.h>

int maximal_square(int** mat, int n){
    int** M = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        M[i] = (int*)malloc(n*sizeof(int));
    }
    for (int i = 0; i < n; i++){
        if (mat[i][0] == 1){
        M[i][0] = 1;
        }
        else{
            M[i][0] = 0;
        }

        if (mat[0][i] == 1){
            M[0][i] = 1;
        }
        else{
            M[0][i] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == 0){
                M[i][j] = 0;
            }
            int flag = 1;
            for (int k = 0; k < M[i-1][j-1] + 1; k++){
                if (M[i-k][j] != 1 && M[i][j-k] != 1){
                    flag = 0;
                    break;
                }
            }
            if (flag){
                M[i][j] = M[i-1][j-1] + 1;
            }
        }
    }
}

int main(){
    return 0;
}