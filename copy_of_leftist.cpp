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
        LH*retain_root=root;
        if(root!=NULL){
        queue*q1=NULL;
        queue*q2=NULL;
          q1=queue_push(q1,root);
          while(q1!=NULL){
             if(q1->lh_node->left !=NULL)
              q1=queue_push(q1,q1->lh_node->left);
             if(q1->lh_node->right!=NULL)
               q1=queue_push(q1,q1->lh_node->right);
             if(q1->lh_node->left==NULL && q1->lh_node->right==NULL)
             q2=queue_push(q2,q1->lh_node);
             q1=queue_pop(q1);
          }
          LH* max=q2->lh_node;
          while(q2!=NULL){
            if( max->data< q2->lh_node->data)
            max=q2->lh_node;
            q2=q2->next;
          }
          LH*temp=max->parent;
          if(temp->left==max) temp->left=NULL;
          else temp->right=NULL;
        }     return root;
}
LH* Traverse_Heap(LH*root,LH*Max_Node)
{
   if(root->right!=NULL)
    Max_Node=Traverse_Heap(root->right,Max_Node);
   if(root->left!=NULL)
    Max_Node=Traverse_Heap(root->left,Max_Node);
    if(root->right==NULL && root->left==NULL){
      
    cout <<root->data << " " ;
    return Max_Node->data >root->data ? Max_Node : root;}
     // return queue_push(q,root);
}

