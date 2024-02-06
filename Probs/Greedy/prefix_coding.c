#include<stdio.h>

#include<stdio.h>

/// Min Priority Queue

typedef struct{
    int* keys;
    int* values;
    int size;
}priority_q;

priority_q* init_priority_q(int capacity){
    priority_q* pq = (priority_q*)malloc(sizeof(priority_q));
    pq->keys = (int*)malloc(capacity*sizeof(int));
    pq->values = (int*)malloc(capacity*sizeof(int));
    pq->size = 0;
    return pq;
}

int left_child(int i){
    return (2*i+1);
}

int right_child(int i){
    return (2*i+2);
}

int parent(int i){
    return (i-1)/2;
}

void shift_down(priority_q* q, int i){
    int l = left_child(i);
    int r = right_child(i);
    if (l < q->size && q->keys[l] > q->keys[i]){
        int temp = q->keys[i];
        q->keys[i] = q->keys[l];
        q->keys[l] = temp;
        shift_down(q, l);
    }
    else if (r < q->size && q->keys[r] < q->keys[i]){
        int temp = q->keys[i];
        q->keys[i] = q->keys[l];
        q->keys[l] = temp;
        shift_down(q, r);
    }
}

void shift_up(priority_q* q, int i){
    int p = parent(i);
    while (i > 0 && q->keys[p] < q->keys[i]){
        int temp = q->keys[i];
        q->keys[i] = q->keys[p];
        q->keys[p] = temp;
        i = p;
    }
}

void insert(priority_q* q,  int key, int value){
    q->size = q->size+1;
    q->keys[q->size] = key;
    shift_up(q, q->size);
}

void delete(priority_q* q, int value){

}

void extract_min(priority_q* q){
    if (q->size > 0){
        int temp = q->keys[0];
        q->keys[0] = q->keys[q->size-1];
        q->size = q->size - 1;
        shift_down(q, 0); 
        return temp;
    }
    else {
        return -1;
    }
}

/// Min Priority Queue


int main(){
    int n;
    // printf("Enter number of alphabets");
    // scanf("%d",&n);
    n = 4;

    int** A = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        A[i] = (int*)malloc(2*sizeof(int));
    }
    A[0][0] = 0;
    A[0][1] = 3;

    A[1][0] = 1;
    A[1][1] = 6;

    A[2][0] = 2;
    A[2][1] = 4;

    A[3][0] = 3;
    A[3][1] = 10;

    optimal_prefix_code(n, A);    

    return 0;
}