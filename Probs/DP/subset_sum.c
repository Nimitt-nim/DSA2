#include<stdio.h>

int subset_sum(int* arr, int n, int t){
    int dp_mat[n][t+1];
    for (int i = 0; i < n; i++){
        dp_mat[i][0] = 1;
    }
    for (int i = 1; i < t+1; i++){
        if (arr[0] == i){
            dp_mat[0][i] = 1;
        }
        else{
            dp_mat[0][i] = 0;
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < t+1; j++){
            if (dp_mat[i-1][j] - arr[i] > 0){
                dp_mat[i][j] = dp_mat[i-1][j-arr[i]] || dp_mat[i-1][j];
            }
            else{
                dp_mat[i][j] = dp_mat[i-1][j];
            }
        }
    }
    return dp_mat[n-1][t];
}


int main(){
    int arr[5] = {1,2,3,4,5};
    printf("%d",subset_sum(&arr, 5, 100));
    return 0;
}