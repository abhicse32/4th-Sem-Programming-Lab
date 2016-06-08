#include<cstdlib>
#include<cmath>
#include"Skew_heap.h"

SK_H* SK_H_Create_Node(int num)
{
   SK_H* new_node=new SK_H ;
   new_node->data=num;
   new_node->left=NULL;
   new_node->right=NULL;
   return new_node;
}
SK_H* SK_H_Merge(SK_H* SK_H1 , SK_H* SK_H2)
{
   SK_H*temp=NULL;
     if(SK_H1==NULL) return SK_H2;
    else if(SK_H2==NULL) return SK_H1;
     else{
     if(SK_H1->data < SK_H2->data){
        temp=SK_H1;
        SK_H1=SK_H2;
        SK_H2=temp;
     }
     temp=SK_H1->left;
     SK_H1->left=SK_H1->right;
     SK_H1->right=temp;
     SK_H1->left=SK_H_Merge(SK_H2, SK_H1->left);
     }
     return SK_H1;
}

SK_H* SK_H_Insert(SK_H* root, int data){
   SK_H* new_node=SK_H_Create_Node(data);
   
   root=SK_H_Merge(root,new_node);
   return root;
    }
SK_H* SK_H_DeleteMax(SK_H*root){
            if (root == NULL) {
                cout << "The heap is empty"<<endl;
                
            }else  root=SK_H_Merge(root->left,root->right);
             return root;     
}

