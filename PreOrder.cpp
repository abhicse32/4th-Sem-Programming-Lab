#include<iostream>
#include"bst.cpp"
using namespace std;
int main()
{
   int i,j,k,n;
   cout <<"Enter the number of elements in the tree: ";
   cin >>n;
   cout <<"Enter the entries: ";
   int *arr=new int [n];
   for(i=0;i<n;i++)
   cin >>arr[i];
   cout <<endl;
   node *root_ptr=NULL;
   for(i=0;i<n;i++)
   root_ptr=bst_add_num(root_ptr,arr[i]);
   
   int level=0,i=0;
    My_queue*t=queue_new2();
     t=add_node(t,root_ptr);
     cout <<"Levelwise Tree is: \n";
  //  print_treestyle(root_ptr,t,level);
    cout <<endl;
    stack* st_=st_new();
    st_=push_st(st_,root_ptr);
    cout <<"\n" <<st->s_node->key <<endl
    int *arr1=new int [2*n];
    if(root_ptr!=NULL)
    arr1[i++]=root_ptr->key;
    cout <<"PreOredr: ";
    preorder(root_ptr,st_,arr1,i);
    cout <<"InOrder: ";
    inOrder(root_ptr,st_,arr,i);
    cout <<"PostOrder: ";
    postOrder(root_ptr,st_,arr,i);
    return 0;
   
}
