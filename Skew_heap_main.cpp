#include<iostream>
#include<string>
#include<vector>
#include"Skew_heap.cpp"
using namespace std;

void pre_order(SK_H*root){
   if(root==NULL)  return ;
   else {
      cout <<root->data <<" ";
      pre_order(root->left);
      pre_order(root->right);
   }
  return;
}

void in_order(SK_H*root)
{
   if(root==NULL) return ;
   else{
      in_order(root->left);
      cout <<root->data <<" ";
      in_order(root->right);
   }
   return;
}

void post_order(SK_H*root)
{
    if(root==NULL)  return ;
    else{
        post_order(root->left);
        post_order(root->right);
        cout <<root->data <<" ";
    }
    return ;
}
using namespace std;
int main(){
        
   int n,j,k,l=0,m;
   cout <<"How many nodes do you want to enter in the heap to begin with:\n";
   cin >>n;
   vector<int> vect;
   SK_H*SK_H1=NULL;
   SK_H*SK_H2=NULL;
  for(j=0;j<n;j++)
    {
    cout <<"Enter " <<j+1 <<"th element: ";
      cin >>m;
     // vect.push_back(m);
    SK_H2=SK_H_Create_Node(m);
     SK_H1=SK_H_Merge(SK_H1,SK_H2);
   }
   cout <<"\nAfter entering " <<n <<" nodes in the heap:\n";
   cout <<"preorder traversal is: ";
   pre_order(SK_H1);
   cout <<endl<<endl;
   cout <<"Inorder traversal: ";
   in_order(SK_H1);
   cout <<endl <<endl;
   cout <<"Post  order traversal: ";
   post_order(SK_H1);
   cout <<endl<<endl;
   cout <<"\nWhat operation do you want to perform:\n";
   cout <<"1: Insert\n 2: DeleteMax\n";
   cin >>m;
   switch(m){
    case 1:
       cout <<"Now enter the nodes:\n";
        while(cin >>n){
      // vect.push_back(n);
       SK_H1=SK_H_Insert(SK_H1,n);
       cout <<"Want to insert any more nodes: ";
     }
     break;
     case 2: 
        SK_H1=SK_H_DeleteMax(SK_H1);
      break;
    default:
        cout<<"Wrong Operation selected:\n";
       break;
   }
  cout <<"preorder traversal : ";
   pre_order(SK_H1);
   cout <<endl<<endl;
   cout <<"Inorder traversal: ";
   in_order(SK_H1);
   cout <<endl <<endl;
   cout <<"Postt  order traversal: ";
   post_order(SK_H1);
   cout <<endl<<endl;
  return 0;
   
}
