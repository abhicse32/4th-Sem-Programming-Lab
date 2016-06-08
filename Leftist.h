
#include<string>
using namespace std;

typedef struct Leftist_ {
      struct Leftist_ *parent;
     int data;
     int npl;
     struct Leftist_ *left;
     struct Leftist_ *right;
}LH;
typedef struct array_and_index{
      int *ar;
      int index;
}ar_ind;

typedef struct Queue_{
   LH* lh_node;
   struct Queue_ *next;
}queue;

LH* Traverse_Heap(LH*,LH*);
queue* queue_push(queue* q,LH*node);
ar_ind* string_to_int_array(string& str);

LH* LH_Create_Node(int num);
LH* LH_Merge(LH*, LH*);
LH* LH_Insert(LH*, int data);
LH* LH_DeleteMax(LH*);
