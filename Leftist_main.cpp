#include<iostream>
#include<vector>
#include"Leftist.cpp"
using namespace std;

int main(){
         
      int n,j=0,k,i,m;
  //    vector <int>vec;
   cout <<"How many nodes do you want to enter\n";
   cin >>n;
 
   LH* lh1=NULL;
   LH* lh2=NULL;
   
   for(i=0;i<n;i++){
  cout <<"Enter "<<i+1 <<"th "<<"node: ";
   cin >>k;
   // vec.push_back(k);
    lh2=LH_Create_Node(k);
     lh1=LH_Merge(lh1,lh2);
   }
  cout <<"After entering " <<n <<" nodes heap is: \n";
  cout <<"preorder traversal of the heap is: ";
   pre_order(lh1);
   cout <<endl<<endl;
   cout <<"Inorder traversal: ";
   in_order(lh1);
   cout <<endl <<endl;
   cout <<"Post  order traversal: ";
   post_order(lh1);
   cout <<endl<<endl;
   cout <<"\n What operation do you want:\n";
   cout <<"1: Insert\n 2: DeleteMax\n";
   cin >>n;
   switch(n){
   case 1:
      cout <<"\nInsert data :\n";
  
      while(cin >>m){
   //vec.push_back(m);
     lh1=LH_Insert(lh1,m);
     cout <<"Still want to insert a node? (non-numeric, to exit):";
    }
    break;
  case 2:
       lh1=LH_DeleteMax(lh1);
       break;
    default :
        cout <<"Wrong operation selected \n";
   }
  cout <<"preorder traversal of the heap is:\n ";
   pre_order(lh1);
   cout <<endl<<endl;
   cout <<"Inorder traversal:\n ";
   in_order(lh1);
   cout <<endl <<endl;
   cout <<"Post  order traversal:\n ";
   post_order(lh1);
   cout <<endl<<endl;
    return 0;
}
