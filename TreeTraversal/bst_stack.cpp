#include"bst.h"
stack* pop_st(stack*st)
{
   if(st!=NULL){
    stack*p=st;
    st=p->next2;
    delete p;}
    return st;
}
stack* st_push(stack*st,node*root)
{
     stack*k=st;
     stack*p=new stack;
     p->s_node=root;
     p->next2=NULL;
     if(st==NULL)
      st=p;
     else {
             p->next2=st;
             st=p;
          }
         return st;  
}
stack * st_new()
{
stack*st=new stack;
    st=NULL;
    return st;
}
int st_size(stack*st)
{   
   stack*p=st;
   int i=0;
     for(p;p!=NULL;p->next2)
     i++;
     return i;
}

