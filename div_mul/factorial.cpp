/***************************************************************************
 * factorial.cpp  : Is a function that calculates factorial of given number.
 * Authors: CS12B032, CS12B035, CS12B012.
 ***************************************************************************/
#include<iostream>
#include"double_linked_list.cpp"
using namespace std;
 
int main()					// main function calls pow_of_any_number function which calcultes power.
{
    int i=0;
    int temp1,temp2,num,k;
    int carry;
    cout <<"enter the number\n";
    cin >>num;
    list* fact_list=NULL;
    temp1=num;
    if(temp1>1){
		while(temp1>0){
			fact_list=add_node_in_list(fact_list,temp1%10);				//storing base in a 2-way linked list.
			temp1/=10;
		}
		list* temp_list=NULL;
		list*last_temp=NULL;

		while(num>1)																		//calculating factorial iteratively.
		{
		  temp_list=fact_list;
			--num;
			i=list_size(fact_list);
			carry=0;
			while(i>0){
		   		temp2=temp_list->data*num+carry;
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
	else if(num==0 || num==1)
	  cout <<"1 \n";
	else 
		cout <<"Enter Positive Number\n";
return 0;
}
