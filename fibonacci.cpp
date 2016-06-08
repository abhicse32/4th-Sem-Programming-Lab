#include<cstdlib>
#include"Fibonacci.h"
#include<string>

Fib* Create_Node(int data)
{
      Fib* new_node=new Fib;
      new_node->key=data;
      new_node->left=new_node;
      new_node->right=new_node;
      new_mode->degree=0;
      new_node->mark=FALSE;
      new_node->child=NULL;
      new_node->parent=NULL;
      return new_node;
}

Fib* Insert(Fib*Head,int data){
    
      Fib* new_node=Create_Node(data);
      if(Head!=NULL){
           Head->left->right=new_node;
            new_node->left=Head->left;
            Head->left=new_node;
            new_node->right=Head;
            if(Head->key > new_node->key)
            Head=new_node;
       }
      else {
         Head=new_node;
      }
      return Head;
      
}
Fib* Delete_Min(Fib*Head)
{
      if(Head==NULL)
        return NULL;
      else if(Head->right==Head){
          delete Head;
          return NULL;
      }
      else {
         Fib* temp=Head->child;
         Fib*temp2=Head->right;
         Head->child->left->right=Head->right;
         Head->right->left=Head->child->left;
          Head->child->left=Head->left;
          Head->left->right=Head->child;
          delete Head;
          Head=temp2;
          while(temp2->data!=temp->data){
             temp2->parent=NULL;
             temp2=temp2->left;
             }
             temp2->parent=NULL;
             Head=Consolidate(Head);
             return Head;
      }
      
}
Fib* Meld(Fib*,Fib*);
Fib* Decrease_Key(Fib*, Fib*);
Fib* Consolidate(Fib*Head)
{
    
      Fib**double_ptr=new Fib*[8];
      int i;
      for(i=0;i<8;i++)   double_ptr[i]=NULL;
       Fib* temp=Head;
       Fib*temp2=Head->left;
      while(temp!=temp2){
         
      }
}
Fib* Heap_Link(Fib*Head,Fib*x,Fib*y){
            
}
