#include<stdio.h>
#include<stdlib.h>

int longest_increasing_subsequence(int* arr, int n){
    int* l = (int*)malloc(n*sizeof(int));
    l[0] = 1;
    for (int i = 1; i < n; i++){
        int max = -1;
        for (int j = i - 1; j >=0; j-- ){
            if (arr[j] < arr[i]){
                if (l[j] + 1 > max){
                    max = l[j] + 1;
                    
                }
            }
        if (max == -1){
            l[i] = 1;
        }
        else {
            l[i] = max;
        }
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
        if (l[i] > ans){
            ans = l[i];
        }
    }
    free(l);
    return ans;
}

int main(){
    int n = 3;
    int arr[3] = {1,2,3};
    int ans = longest_increasing_subsequence(arr, n);
    printf("%d",ans);
    return 0;
}