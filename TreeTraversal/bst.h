typedef struct node_struct{
    int key;
    int flag_ind;
    struct node_struct* left;
    struct node_struct* right;
} node;

typedef struct new_Queue{
       struct new_Queue*next;
       struct node_struct *node1;
}My_queue;
typedef struct stack_{
     struct stack_*next2;
     struct node_struct* s_node;
}stack;
   
My_queue*add_node(My_queue*,node*);

My_queue* queue_new2();

My_queue* queue_push2(My_queue*,node*);
int my_queue_size(My_queue*);

My_queue* queue_pop2(My_queue*);
node* bst_add_num(node* root, int);

void print_treestyle(node*,My_queue*,int);
node* create_node(int data);
void preOrder(node*,stack* );
void postOrder(node*,stack*,int *, int );
void inOrder(node*,stack*,int*,int);
//adding stack functions
stack* pop_st(stack*);
stack* st_push(stack*,node*);
stack * st_new();
int st_size(stack*);


