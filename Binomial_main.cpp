#include<iostream>
#include<cmath>
#include<vector>
#include"Binomial_heap.cpp"

using namespace std;
int main()
{
   int n=0,j,k,i=0,m,l=0;
   cout <<"Enter the number of nodes in the first tree:\n";
   cin >>n;
   vector<int> vec;
   cout <<"Enter the data:\n";
  for(i=0;i<n;i++)
  {
      cin >>k;
      vec.push_back(k);
  }   
   BH* head=NULL;
   i=0;
   while(n>0){
      if(n%2){
       m=pow(2,i);
       BH*node=Create_Binomial_Tree(vec,l,m+l);
       //cout << l <<" " <<m <<endl;
       if(head!=NULL)
      {
           BH* temp=head;  
           while(temp->sibling!=NULL)
           temp=temp->sibling;
           temp->sibling=node;
       }
       else 
           head=node;
           //cout <<"\n" <<head->data <<endl;
           l+=m;
      }
       i++;
      n/=2;
   }
   
   
   //cout <<head->data << " " <<head->sibling->data <<" "<<head->sibling->child->data <<"  "
   //<<head->sibling->child->sibling->data <<"  "<<head->sibling->child->child->data<< endl;
   cout <<"\nAfter inserting these elements levelwise heap is:\n ";
   queue* q=NULL;
   q=Enqueue(q,head);
   BH*temp=NULL;
   int p=queue_size(q);
   while(q!=NULL){
      if(p==0){
      p=queue_size(q);
      cout <<endl;
    }
    temp=q->bh;
    while(temp!=NULL){
       if(temp->child!=NULL)
         q=Enqueue(q,temp->child);
        cout <<temp->data <<" ";
        temp=temp->sibling;
    }p--;   
    q=Dequeue(q); 
  }
  cout <<"\nWhat operation do you want to perform:\n";
  cout <<"1: Insert\n" <<"2: Delete_Min\n" <<"3: Meld\n" <<"4: Decrease Key\n";
  cin >>n;
  switch(n){
         case 1:
            cout <<"\nplease Enter data:\n";
            cin >>j;
            head=BH_Insert(head,j);
            break;
         case 2:
            head=Binomial_Extract(head);
            break;
         case 3:
		      cout <<"Enter the number of nodes in the second tree:\n";
		      cin >>n;
		       vector<int>vec2;
		       cout <<"now enter the data elements:\n";
		      for(i=0;i<n;i++)
		       {
		         cin >>k;
		           vec2.push_back(k);
		     }   
		   BH* head2=NULL;
		   i=0; l=0;m=0;
		   while(n>0){
		      if(n%2){
		       m=pow(2,i);
		       BH*node=Create_Binomial_Tree(vec2,l,m+l);
		       //cout << l <<" " <<m <<endl;
		       if(head2!=NULL)
		      {
			   BH* temp=head2;  
			   while(temp->sibling!=NULL)
			   temp=temp->sibling;
			   temp->sibling=node;
		       }
		       else 
			   head2=node;
			   //cout <<"\n" <<head->data <<endl;
			   l+=m;
		      }
		       i++;
		      n/=2;
		   }
		   head=Binomial_Union(head,head2);
		   break;
	    case 4:
	        cout <<"Enter the value to be increased:\n";
	         cin >>n;
	          cout <<"Give the node location:\n";
	     /*  default:  
	          cout <<"Sorry, no operation selected:\n";
	           break;*/
	       	  
  }
        cout <<"\nAfter the above operation heap is :\n";
                 q=NULL;
		   q=Enqueue(q,head);
		   temp=NULL;
		    p=queue_size(q);
		   while(q!=NULL){
		      if(p==0){
		      p=queue_size(q);
		      cout <<endl;
		    }
		    temp=q->bh;
		    while(temp!=NULL){
		       if(temp->child!=NULL)
			 q=Enqueue(q,temp->child);
			cout <<temp->data <<" ";
			temp=temp->sibling;
		    }p--;   
		    q=Dequeue(q); 
		  }
		  cout <<endl;
         return 0;
   
}
