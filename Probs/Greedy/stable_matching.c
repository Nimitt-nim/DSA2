#include<stdio.h>

void match(int n, int** s, int** c){
    for (int i = 0; i < n; i++){
        
    }
}

int main(){
    int n;
    // students
    int** s = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        s[i] = (int*)malloc(2*sizeof(int));
    }
    for (int i = 0; i < n; i++){
        s[i][1] = -1;
    }
    int** preferences_s = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        preferences_s[i] = (int*)malloc(n*sizeof(int));
    }
    //
    // colleges
    int** c = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        c[i] = (int*)malloc(2*sizeof(int));
    }
    for (int i = 0; i < n; i++){
        c[i][1] = -1;
    }
    int** preferences_c = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        preferences_c= (int*)malloc(n*sizeof(int));
    }
    //

    return 0;
}