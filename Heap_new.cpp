#include"Heap_new.h"
#include<vector>
#include<cmath>
using namespace std;

queue* queue_push(queue*q, h*heap_)
 {
    queue*q1=q;
    queue* q2=new queue;
    q2->node=heap_;
    q2->next=NULL;
    if(q!=NULL)
    {
        while(q1->next!=NULL)
           q1=q1->next;
           q1->next=q2;
      }
      else q=q2;
      return q;
 }
queue* queue_pop(queue* q)
{
   if(q==NULL)
   return q;
        queue *q1=q;
      q=q1->next;
      delete q1;
      return q;
}

int queue_size(queue*q)
{
   int i=0;
   for(;q!=NULL;q=q->next)
   i++;
   return i;
}

h* heap_extract_max(vector<int>& arr,int n){
    if(n<=0)
      return NULL;
       h*root=NULL;
    arr[0]=arr[n-1];
    max_heapify(arr,0,n-1);
   return root=heap_create(arr,n-1);
}
void swap(int& a,int& b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
}
h* heap_create(vector<int>&arr,int n)
{
     int i;
      h*root=create_heap_node(arr[0]);
     queue*q=NULL;
     q=queue_push(q,root);
     for(i=1;i<n;i++)
     {
        h*h1=create_heap_node(arr[i]);
        if(q->node->left==NULL){
        h1->parent=q->node;
        q->node->left=h1;
      }
        else if(q->node->right==NULL)
        {
           h1->parent=q->node;
            q->node->right=h1;
            q=queue_pop(q);
        }
        q=queue_push(q,h1);
    }
  return root;
}

void max_heapify(vector<int> &arr,int i,int n)
{
   int l,r,largest=i;
   l=2*i+1;
   r=l+1;
   if(l<n && arr[l]>arr[i])
     largest=l;
   if(r<n && arr[r]>arr[largest])
     largest=r;
   if(largest!=i){
     swap(arr[i],arr[largest]);
     max_heapify(arr,largest,n);
     }
     return ;
}

void build_max_heap(vector<int>&arr,int n)
{
  int i;
   for(i=(n-1)/2;i>=0;i--){
   max_heapify(arr,i,n);
   }
}

void print_levelwise(h*root,queue*q, int level)
{
   if(q==NULL)
   return ;
  else {
     if(level==0){
      cout <<endl ;
      level=queue_size(q);
      }
      cout <<root->data <<" ";
      if(root->left!=NULL)
      q=queue_push(q,root->left);
      if(root->right!=NULL)
      q=queue_push(q,root->right);
      q=queue_pop(q);
      level--;
      if(q!=NULL)
      print_levelwise(q->node,q,level);
   }
 }
h* create_heap_node(int key)
{ 
     h* heap_=new h;
   heap_->parent=NULL;
   heap_->data=key;
   heap_->right=NULL;
   heap_->left=NULL;
 return heap_;
}




h* heap_increase_key(vector<int>&arr, int i , int n, int key)
{
     if(key<arr[i] || i>=n)
     {
         cout <<"Invalid operation:\n";
         return NULL;
     }
     h* root=NULL;
     arr[i]=key;
     int parent;
     parent = i%2==0 ? (i/2)-1 : i/2;
     while(parent>=0 && arr[parent] <arr[i]) {
         swap(arr[i],arr[parent]);
         i=parent;
         parent = i%2==0 ? (i/2)-1 : i/2;
       //  cout <<arr[i]<<" " <<arr[parent] <<"  " <<i <<" " <<parent <<endl;
     
     }
     return root=heap_create(arr,n);
}
void Max_Heap_Insert(vector<int>&arr,int n)
{
   int parent= n%2 ?n/2 : n/2-1;
  // cout <<arr[n] <<" " <<arr[parent] <<endl;
     while(parent>=0 && arr[parent] <arr[n] ){
         swap(arr[n],arr[parent]);
         n=parent;
         parent=n%2?n/2:n/2-1;
        // cout <<arr[n] <<" " <<arr[parent] <<endl;
     }
}
