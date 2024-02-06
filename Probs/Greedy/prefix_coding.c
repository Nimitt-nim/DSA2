#include<stdio.h>
#include<stdlib.h>

/// Min Priority Queue
typedef struct{
    tree_node** nodes;
    int size;
}priority_q;

priority_q* init_priority_q(int capacity){
    priority_q* pq = (priority_q*)malloc(sizeof(priority_q));
    pq->nodes = (tree_node**)malloc(capacity*sizeof(tree_node*));
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

void swap(tree_node* num1, tree_node* num2){
    tree_node temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void shift_down(priority_q* q, int i){
    int l = left_child(i);
    int r = right_child(i);
    int largest = i;
    if (l < q->size && q->nodes[l] > q->nodes[i]){
        largest = l;
    }
    else if (r < q->size && q->nodes[r] < q->nodes[i]){
        largest = r;
    }
    if (largest != i){
        swap(&q->nodes[i], &q->nodes[largest]);
        shift_down(q, largest);
    }
}

void shift_up(priority_q* q, int i){
    while (i > 0 && q->nodes[parent(i)] < q->nodes[i]){
        swap(q->nodes[i], q->nodes[parent(i)]);
        i = parent(i);
    }
}

void insert(priority_q* q,  tree_node* node){
    q->size = q->size+1;
    q->nodes[q->size] = node;
    shift_up(q, q->size);
}

// void delete(priority_q* q, int value){

// }

int extract_min(priority_q* q){
    if (q->size > 0){
        int temp = q->nodes[0]->value;
        q->nodes[0] = q->nodes[q->size-1];
        q->size = q->size - 1;
        shift_down(q, 0); 
        return temp;
    }
    else {
        return -1;
    }
}
/// Min Priority Queue

// Tree
typedef struct{
    int key;
    int value;
    tree_node* left;
    tree_node* right;
}tree_node;

tree_node* init_tree_node(int key, int value){
    tree_node* tn = (tree_node*)malloc(sizeof(tree_node));
    tn -> left = NULL;
    tn -> right = NULL;
    tn -> key = key;
    tn -> value = value;
}

tree_node* combine_nodes(tree_node* node1, tree_node* node2){
    tree_node* parent_node = init_tree_node(-1, node1->value+node2->value);
    parent_node->left = node1;
    parent_node->right = node2;
}
// Tree

// what data structure to use ?: Damn, settled to a simple one

tree_node* optimal_prefix_code(int n, int* A){
    priority_q* q = init_priority_q(n);
    for (int i = 0; i < n; i++){
        tree_node* node = init_tree_node(i,A[i]);
        insert(q, node);
        free(node);
    }
    while (q->size > 1){
        int key = extract_min(q);
        tree_node* node1 = init_tree_node(key, A[key]);
        key = extract_min(q);
        tree_node* node2 = init_tree_node(key, A[key]);
        tree_node* parent_node = combine_nodes(node1,node2);
        insert(q, parent_node);
    }
    return q->nodes[0];
}

int main(){
    int n;
    // printf("Enter number of alphabets");
    // scanf("%d",&n);
    n = 4;

    int* A = (int**)malloc(n*sizeof(int*));


    A[0] = 3;        // A[i][1] = frequency of the alphabet

 
    A[1] = 6;

  
    A[2] = 4;


    A[3] = 10;

    optimal_prefix_code(n, A);    

    return 0;
}