#include<stdio.h>
#include<stdlib.h>

void sort_intervals(int** S, int n){
    for (int j = n-2; j > 0; j--){
        for (int i = 0; i < j; i++){
            if (S[i][1] > S[i+1][1]){
                int temp1 = S[i+1][0];
                int temp2 = S[i+1][1];
                S[i+1][1] = S[i+1][1];
                S[i+1][0] = S[i+1][0];
                S[i][1] = temp1;
                S[i][0] = temp2;
            }
        }
    }
}

int* maximum_disjoint_intervals(int** S, int n){

    int* intervals = (int*)malloc(n*sizeof(int));
    sort_intervals(S, n);

    intervals[0] = 1;
    int current = 0;
    for (int i = 1; i < n; i++){
        if (S[current][1] < S[i][0]){
            current = i;
            intervals[i] = 1;
        }
        else {
            intervals[i] = 0;
        }
    }
    return intervals;
}

int main(){
    // int n;
    // printf("Enter n");
    // scanf("%d",&n);
    int n = 3;
    int** S = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        S[i] = (int*)malloc(2*sizeof(int));
    }
    
    S[0][0] = 0;
    S[0][1] = 3;

    S[1][0] = 4;
    S[1][1] = 6;

    S[2][0] = 7;
    S[2][1] = 9;

    // int start;
    // int end;
    // for (int i = 0; i < n;i++){
    //     printf("%dth Interval \n",i);
    //     printf("Enter Start");
    //     scanf("%d",&start);
    //     printf("Enter End");
    //     scanf("%d",&end);
    //     S[i][0] = start;
    //     S[i][1] = end;
    // }

    int* intervals = maximum_disjoint_intervals(S,n);

    for (int i = 0; i < n; i++){
        printf("%d ",intervals[i]);
    }

    for (int i = 0; i < n; i++){
        free(S[i]);
    }
    free(S);
    return 0;
}