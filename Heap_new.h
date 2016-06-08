#include<vector>
using namespace std;
typedef struct heap__ {
       struct heap__*parent ;
       int data;
       struct heap__ *left;
       struct heap__ *right;
}h;
typedef struct array_and_index{
      int *ar;
      int index;
}ar_ind;

typedef struct heap_Queue{
      h*node;
      struct heap_Queue*next;
}queue;
//h* heap_new();
h* create_heap_node(int key);

h* heap_extract_max(vector<int>&arr,int);
queue * queue_new();
queue* queue_push(queue*,h*);
queue* queue_pop(queue);
int queue_size(queue*);
void queue_print(queue*q);
void print_levelwise(h*root,queue*q, int level);
void build_max_heap(vector<int>&arr,int n);
void max_heapify(vector<int>&arr,int i,int n);
h* heap_create(vector<int>& arr,int n);
void swap(int& a,int& b);
void Max_Heap_Insert(vector<int>&arr,int);
h* heap_increase_key(vector<int>&arr, int , int);

