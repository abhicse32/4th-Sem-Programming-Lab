#include<cstdlib>
#include<string>
#include<cmath>
#include"Leftist.h"
using namespace std;

void pre_order(LH*root){
   if(root==NULL)  return ;
   else {
      cout <<root->data <<" ";
      pre_order(root->left);
      pre_order(root->right);
   }
  return;
}

void in_order(LH*root)
{
   if(root==NULL) return ;
   else{
      in_order(root->left);
      cout <<root->data <<" ";
      in_order(root->right);
   }
   return;
}

void post_order(LH*root)
{
    if(root==NULL)  return ;
    else{
        post_order(root->left);
        post_order(root->right);
        cout <<root->data <<" ";
    }
    return ;
}



LH* LH_Create_Node(int num)
{
   LH* new_node=new LH ;
   new_node->data=num;
   new_node->npl=0;
   new_node->left=NULL;
   new_node->right=NULL;
   new_node->parent=NULL;
   return new_node;
}
LH* LH_Merge(LH*lh1 , LH* lh2)
{
     if(lh1==NULL) return lh2;
     if(lh2==NULL) return lh1;
     
     if(lh1->data >lh2->data){
        LH*temp=lh1;
        lh1=lh2;
        lh2=temp;
     }
     if(lh1->left==NULL){
       lh1->left=lh2;
       lh2->parent=lh1;
       }
     
     else{
        lh1->right=LH_Merge(lh1->right,lh2);
        lh2->parent=lh1;
        if(lh1->left->npl < lh1->right->npl)
         {
           LH*temp=lh1->left;
           lh1->left=lh1->right;
           lh1->right=temp;
         }
         lh1->npl=lh1->right->npl+1;
     }
     return lh1;
}

LH* LH_Insert(LH* root, int data){
   LH* new_node=LH_Create_Node(data);
   
   root=LH_Merge(root,new_node);
   return root;
    }
    queue* queue_push(queue* q,LH*node)
{
    queue* new_q=new queue;
    new_q->lh_node=node;
    new_q->next=NULL;
    queue* temp=q;
    if(temp!=NULL){
       while(temp->next!=NULL)
       temp=temp->next;
       temp->next=new_q;
    }else q=new_q;
    return q;
}  

queue*queue_pop(queue*q)
{
    if(q!=NULL){
       queue*temp=q;
       q=temp->next;
       free(temp);
       return q;
    }else return q;
}

LH* LH_DeleteMax(LH*root){
       LH*temp1=root->left;
       LH*temp2=root->right;
       temp1->parent=NULL;
       temp2->parent=NULL;
       return LH_Merge(temp1,temp2);
}

