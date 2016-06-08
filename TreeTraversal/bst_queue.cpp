#include"bst.h"
My_queue* queue_new2()
{
    My_queue*q=new My_queue;
    q=NULL;
    return q;
}

My_queue*add_node(My_queue*queue,node*root)
{
    My_queue*k=queue;
     My_queue*p=new My_queue;
     p->node1=root;
     p->next=NULL;
     if(queue==NULL)
      queue=p;
     else {
           while(k->next!=NULL)
           k=k->next;
            k->next=p;
         }
         return queue;  
}

My_queue* queue_pop2(My_queue*q)
{
    if(q==NULL)
    return q;
   My_queue*p;
   p=q;
   q=p->next;
   delete p;
   return q;
}
int my_queue_size(My_queue*q)
{
    int i=0;
    while(q!=NULL)
    {
       q=q->next;
       i++;
    }
    return i;
}
int search_array(int *ar,int t,int k)
{
   int x=0,flag=0;;
   while(x<=k){
   if(ar[x]==t)
   flag++;
   x++;
   }
   return flag;
   
}
