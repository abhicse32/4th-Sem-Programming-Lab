
typedef struct Fibonacci_ Fib;
struct Fibonacci_{
    Fib *left;
    Fib* parent;
    int key;
    int degree;
    bool mark;
    Fib* child;
    Fib* right;
};
Fib* Create_Node(int data);
Fib* Insert(Fib*,int data);
Fib* Delete_Min(Fib*Head);
Fib* Meld(Fib*,Fib*);
Fib* Decrease_Key(Fib*, Fib*);
Fib* Consolidate(Fib*);
Fib* Heap_Link(Fib*,Fib*,Fib*);
