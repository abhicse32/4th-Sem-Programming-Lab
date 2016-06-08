#include<cstdlib>
#include"string"
#include"Binomial_heap.h"
using namespace std;  


st* stack_push(st*st_,BH* bh_node)
{
   st*temp=new st;
   temp->bh=bh_node;
   temp->link=st_;
   return temp;
}
st* stack_pop(st*st_)
{
   if(st_!=NULL){
     st*temp=st_;
     st_=temp->link;
     delete temp;
   }return st_;
}
queue* Enqueue(queue*q,BH* bh_node)
{
    queue*q_local=q;
    queue*q_new=new queue;
    q_new->bh=bh_node;
    q_new->next=NULL;
    if(q!=NULL){
        while(q_local->next!=NULL)
        q_local=q_local->next;
        q_local->next=q_new;
    }else q=q_new;
    return q;
}
queue* Dequeue(queue*q){
   if(q!=NULL){
      queue* temp=q;
      q=temp->next;
      delete temp;
   }return q;
}
int  queue_size(queue*q){
    int i=0;
    queue*temp=q;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }return i;
}
void queue_print(queue*q){

      queue*temp=q;
      while(temp!=NULL){
          cout <<temp->bh->data <<" ";
          temp=temp->next;
      }
      cout <<endl;
}

 BH* Create_New_Node(int num)
 {
    BH* new_node=new BH;
    new_node->parent=NULL;
    new_node->data=num;
    new_node->degree=0;
    new_node->child=NULL;
    new_node->sibling=NULL;
    return new_node;
 }
 
BH *Binomial_Link(BH* bh1, BH* bh2 ){
      bh1->parent=bh2;
      bh1->sibling=bh2->child;
      bh2->child=bh1;
      bh2->degree+=1;   
      return bh2;
}

BH* Create_Binomial_Tree(vector<int>arr,int low,int high)
{
   int i=0,j=0,k=0;
   BH** node_array=new BH*[high-low+1];
   while(low<high)
     node_array[i++]=Create_New_Node(arr[low++]);
      
     while(j<=i && i>=2){
        node_array[k++]=node_array[j]->data >node_array[j+1]->data ?\
          Binomial_Link(node_array[j],node_array[j+1] ): Binomial_Link(node_array[j+1],node_array[j] ) ;
        j+=2;
        if(j==i && j>2){
           i=k;j=0;
           k=0;
        }
        else if(j==i && j<=2)break;
     }
     return node_array[0];
}

BH* BH_Insert(BH* B_heap ,int num )
{
    BH*node=Create_New_Node(num);
  return Binomial_Union(B_heap,node);
  
}

BH* BH_Decrease_key(BH*Head, BH* node, int new_value)
{
  if(Head!=NULL && node!=NULL){
    if(new_value >= node->data){
      cout <<"New data is greater than the current data:";
      return Head;
    }
     node->data=new_value;
       BH* temp1=node;
       BH *temp2=temp1->parent;
       while(temp2!=NULL && temp1->data < temp2->data){
       int flag_reg=temp1->data;
       temp1->data=temp2->data;
       temp2->data=flag_reg;
         temp1=temp2;
         temp2=temp1->parent;
       }
 }
 return Head;   
    
}


BH* Binomial_Merge(BH*bh1, BH* bh2)
{
     BH* Head=NULL;
     BH*flag=NULL;
     if(bh1!=NULL && bh2!=NULL){
          Head=bh1->degree >= bh2->degree ? bh2 :bh1 ;
          BH* temp=bh1->degree >= bh2->degree ?bh1 :bh2;
          BH* temp2=Head;
          while(temp!=NULL && temp2->sibling!=NULL){
                 if(temp->degree >temp2->sibling->degree){
                     temp2=temp2->sibling;
                 }else if(temp->degree <= temp2->sibling->degree)
                 flag=temp;
                 temp=temp->sibling;
                 flag->sibling=temp2->sibling;
                 temp2->sibling=flag;
                 temp2=temp2->sibling;
          }if(temp2->sibling==NULL && temp!=NULL){
             temp2->sibling=temp;
             Head=temp2;
             }
          
     }else if(bh1==NULL) Head=bh2;
     else if(bh2==NULL) Head=bh1;
       
       return Head;
}

BH* Binomial_Union(BH* bh1, BH* bh2){
   BH* Head=Binomial_Merge(bh1,bh2);
   if(Head==NULL) return Head;
  BH* prev_x=NULL;
   BH* x=Head;
   BH*next_x=x->sibling;
    while(next_x!=NULL){
               if(x->degree!=next_x->degree ||( next_x->sibling!=NULL && next_x->sibling->degree==x->degree)){
                  prev_x=x;
                  x=next_x;
                  }
                 else if(x->data <= next_x->data){
                     x->sibling=next_x->sibling;
                     x=Binomial_Link(next_x,x);           
               }else {
                 if(prev_x==NULL)
                    Head=next_x;
               else prev_x->sibling=next_x; 
               x=Binomial_Link(x,next_x);
               }  
              next_x=x->sibling;   
    }
    return Head;
}
BH* Reverse_list_order(BH* root_node){
if(root_node->child!=NULL){
    BH*Head=NULL;
    BH* temp=root_node->child;
    st*stack=NULL;
    while(temp!=NULL){
    stack=stack_push(stack,temp);
    temp=temp->sibling;
    }
    Head=stack->bh;
    while(stack->link!=NULL)
    {
       stack->bh->sibling=stack->link->bh;
       stack=stack->link;
    }stack->bh->sibling=NULL;
    return Head;
 }else return NULL;
}

BH* Binomial_Extract(BH* bh)
{
     if(bh!=NULL){
       BH* Head=bh;
       BH* prev_node=NULL;
       BH* min_node=bh;
       while(bh->sibling!=NULL){
           if(min_node->data >= bh->sibling->data){
                min_node=bh->sibling;
                prev_node=bh;
           }
           bh=bh->sibling;
       }
       if(prev_node!=NULL)
         prev_node->sibling=min_node->sibling;
       else if(prev_node==NULL)
          Head=min_node->sibling;
        
       BH*Head2=Reverse_list_order(min_node);
       return Binomial_Union(Head,Head2);
     }
}
