#include<string>
using namespace std;
typedef struct Binomial_{
     struct Binomial_ *parent;
     int data;
     int degree;
     struct Binomial_ *child;
     struct Binomial_ *sibling;
}BH;
typedef struct BH_queue{
     BH* bh;
     struct BH_queue* next;
}queue;

typedef struct BH_stack{
    BH* bh;
    struct BH_stack*link;
}st;
st* stack_push(st*,BH*);
st* stack_pop(st*);
//queue* queue_new(BH*);
queue* Enqueue(queue*,BH*);
queue* Dequeue(queue*);
int queue_size(queue*);
BH* Create_New_Node(int);
BH *Binomial_link(BH* bh1, BH* bh2);
BH* Create_Binomial_Tree(int*,int,int);
BH* BH_Insert(BH *, int );
BH* BH_Delete(BH*, BH*);
BH* Binomial_Union(BH*,BH*);
BH* Binomial_Merge(BH* bh1, BH*bh2);
BH* Binomial_Extract(BH*);



