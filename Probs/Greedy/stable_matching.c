#include<stdio.h>
#include<stdlib.h>

void print_stable_matching(int n, int*s){
    for (int i = 0; i < n; i++){
        printf("%d -> %d\n",i,s[i]);
    }
}

int check_preference(int n, int* preferences, int c1, int c2){
    int watched_c2 = 0;
    for (int i = 0; i < n; i++){
        if (preferences[i] == c2){
            watched_c2 = 1;
        }
        else if (preferences[i] == c1 && watched_c2 == 0){
            return 1;
        }
    }
    return 0;
}

void stable_matching(int n, int*s, int*c, int** preferences_s, int** preferences_c){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (c[j] == -1){  // c is unmatched
                int preferred_s = preferences_c[j][i];
                if (s[preferred_s] == -1){    // student is unmatched
                    s[j] = j;
                    c[j] = preferred_s;
                }
                // j  has more preference than
                // already matched college
                else if (s[preferred_s] != -1){
                    if (check_preference(n, preferences_s[preferred_s], j, s[preferred_s])){
                        s[j] = j;
                        c[j] = preferred_s;
                    }                        
                }
            }
        }
    }
}

int main(){
    int n;
    // students
    int* s = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        s[i] = -1;
    }
    int** preferences_s = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        preferences_s[i] = (int*)malloc(n*sizeof(int));
    }
    //
    // colleges
    int* c = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        c[i] = -1;
    }
    int** preferences_c = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        preferences_c[i] = (int*)malloc(n*sizeof(int));
    }
    // Initialising
    
    n = 3;
    for (int i = 0; i <n; i++){
        s[i] = -1;
        c[i] = -1;
    }
    preferences_s[0][0] = 0;
    preferences_s[0][1] = 1;
    preferences_s[0][2] = 2;
    preferences_s[1][0] = 2;
    preferences_s[1][1] = 0;
    preferences_s[1][2] = 1;
    preferences_s[2][0] = 2;
    preferences_s[2][1] = 0;
    preferences_s[2][2] = 1;

    preferences_c[0][0] = 0;
    preferences_c[0][1] = 2;
    preferences_c[0][2] = 1;
    preferences_c[1][0] = 2;
    preferences_c[1][1] = 0;
    preferences_c[1][2] = 1;
    preferences_c[2][0] = 0;
    preferences_c[2][1] = 1;
    preferences_c[2][2] = 2;

    stable_matching( n, s, c, preferences_s, preferences_c);
    print_stable_matching(n, s);

    for (int i = 0; i < n; i++){
        free(preferences_c[i]);
        free(preferences_s[i]);
    }
    free(c);
    free(s);
    free(preferences_c);
    free(preferences_s);
    return 0;
}