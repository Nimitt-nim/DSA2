#include<stdio.h>

/// Min Priority Queue

typedef struct{
    int* array;
    int size;
}priority_q;



priority_q* init_priority_q(int capacity){
    priority_q* pq = (priority_q*)malloc(sizeof(priority_q));
    pq->array = (int*)malloc(capacity*sizeof(int));
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
    if (l < q->size && q->array[l] > q->array[i]){
        int temp = q->array[i];
        q->array[i] = q->array[l];
        q->array[l] = temp;
        shift_down(q, l);
    }
    else if (r < q->size && q->array[r] < q->array[i]){
        int temp = q->array[i];
        q->array[i] = q->array[l];
        q->array[l] = temp;
        shift_down(q, r);
    }
}

void shift_up(priority_q* q, int i){
    int p = parent(i);
    while (i > 0 && q->array[p] < q->array[i]){
        int temp = q->array[i];
        q->array[i] = q->array[p];
        q->array[p] = temp;
        i = p;
    }
}

void insert(priority_q* q,  int key, int value){
    q->size = q->size+1;
    q->array[q->size] = key;
    shift_up(q, q->size);
}

void delete(priority_q* q, int value){

}

void extract_min(priority_q* q){
    if (q->size > 0){
        int temp = q->array[0];
        q->array[0] = q->array[q->size-1];
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
    return 0;
}