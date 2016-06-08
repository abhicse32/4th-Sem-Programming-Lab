#include"bst.h"
#include <cstdlib>
#include<iostream>
using namespace std;
//queue starts here
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
}

//stack starts here
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
     p->s_node->flag_ind=0;
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
     while(p!=NULL){
     p=p->next2;
     i++;}
     return i;
}


node* create_node(int data)
{
   node*p=new node;
   p->key=data;
   p->left=NULL;
   p->right=NULL;
   return p;
}
node* bst_add_num(node* root, int num)
{
   
   if(root==NULL)
   return (create_node(num));
   else if(num<=root->key)
     root->left=bst_add_num(root->left,num);
    else if(num>root->key)
    root->right=bst_add_num(root->right,num);
    return root;
}
void print_treestyle(node* root,My_queue*t,int level)
{
    if(root==NULL || t==NULL)
    return;
    else 
    {
    
         if(level==0){
         level=my_queue_size(t);
         cout <<endl;
         }
        cout << t->node1->key <<" "; 
        if(t->node1->left!=NULL)
         t=add_node(t,t->node1->left);
         if(t->node1->right!=NULL)
         t=add_node(t,t->node1->right);
         
         t=queue_pop2(t);
         if(t!=NULL)
         print_treestyle(t->node1,t,--level);
   }
   return ;
}

void preOrder(node*root,Stack*st)
{
   cout <<"sytert";
   if(st==NULL || root==NULL)
   return ;
   else{
   int flag=0;
  if(root->flag_ind==1)
    cout << root->key <<" ";
  
   if(root->left!=NULL){
             if(root->left->flag_ind!=1){
             st=st_push(st,root->left);
           flag++;}
    }
   else if(root->right!=NULL){
   if(root->right->flag_ind!=1){
   st=st_push(st,root->right);
    flag++;}
   }
   if(flag==0)
   st=pop_st(st);
   st->s_node->flag_ind++;
  preOrder(st->s_node,st);
}
}
void postOrder(node*root,Stack*st,int* arr, int i)
{
    if(root==NULL || st==NULL)
    return ;
    else{
    if(root->right!=NULL){
    if(root->right->flag_ind!=1)
      st=st_push(st,root->right);
    }
    if (root->left!=NULL){
     if(root->left->flag_ind!=1)
      st=st_push(st,root->left);
      }
   else if ((root->right==NULL || (root->left->flag_ind==1))&& (root->left==NULL ||(root->right->flag_ind==1))){
      cout << root->key <<" ";
      st=pop_st(st);
      }
      postOrder(st->s_node,st,arr,i); 
    }
    
}

void inOrder(node*root,Stack*st,int* arr,int i)
{
      if(root==NULL ||st==NULL )
      return ;
      else{
      if(root->left!=NULL){
           if(root->left->flag_ind==0){
              root->left->flag_ind++;
              st=st_push(st,root->left);
              }
          else if(root->right!=NULL){
               if(root->right->flag_ind==0){
                  root->right->flag_ind++;
                  st=st_push(st,root->right);
               }else  st=pop_st(st);
        } else  st=pop_st(st);
      }
      else if(root->left==NULL){
          if(root->flag_ind==1){
               cout <<root->key <<" ";
               root->flag_ind++;
               }
          if(root->right!=NULL){
               if(root->right->flag_ind==0){
               root->right->flag_ind++;
                  st=st_push(st,root->right);
                  }else   st=pop_st(st);
           }  
   }
      inOrder(st->s_node,st,arr,i);
 }
}

