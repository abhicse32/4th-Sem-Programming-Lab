#include<iostream>
using namespace std;

typedef struct linked_list list;
struct linked_list{
       list* rear;
       int data;
       list* front;
};

list *add_node_in_list(list*l,int data_element){
     list*flag_node=l;
     list *new_node=new list;
     new_node->rear=NULL;
     new_node->data=data_element;
     new_node->front=NULL;
     if(l==NULL)
        l=new_node;
     else{
          while(flag_node->rear!=NULL)
          flag_node=flag_node->rear;
          
          new_node->front=flag_node;
          flag_node->rear=new_node;
     }
     return l;
}

int list_size(list*l)
{
   list*temp_list=l;
   int counter=0;
   while(temp_list!=NULL)
   {
       temp_list=temp_list->rear;
       counter++;
   }
   return counter;
}
void factorial(int n)
{
   int i=0;
   int temp1,temp2;
   int carry;
   list* fact_list=NULL;
    temp1=n;
    if(temp1>0){
		while(temp1>0){
			fact_list=add_node_in_list(fact_list,temp1%10);
			temp1/=10;
		}
		list* temp_list=NULL;
		list*last_temp=NULL;

		while(n>1)
		{
		     temp_list=fact_list;
			--n;
			i=list_size(fact_list);
			carry=0;
			while(i>0){
		   		temp2=temp_list->data*n+carry;
		   		temp_list->data=temp2%10;
		   		carry=temp2/10;
		   		last_temp=temp_list;
		   		temp_list=temp_list->rear;
		   		i--;
			}
			while(carry>0){
				fact_list=add_node_in_list(fact_list,carry%10);
				carry/=10;
			}
		}
		
		while(last_temp->rear!=NULL)
		last_temp=last_temp->rear;
		
		while(last_temp!=NULL){
			cout <<last_temp->data;
			last_temp=last_temp->front;
			}
			cout <<endl;

		}
		else if(n==0)
             cout <<" factorial of "<<n  <<" is :" <<1 <<endl;
		else 
		cout <<"Enter Positive Number\n";
   return;
}
void power_of_any_number(int num,int pow_index)
{
   
}
 
int main()
{
    int n1,n2;
    cout <<"enter the number\n";
    cin >>n1;
    cout <<endl;
    for(n2=2;n2<=n1;n2++)
    factorial(n2);    
return 0;
}
