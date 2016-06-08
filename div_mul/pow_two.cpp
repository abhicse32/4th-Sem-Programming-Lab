/********************************************************************
 * pow.cpp  : Is a function that calculates power of given number with
 * in long long int limit.
 * Authors: CS12B032, CS12B035, CS12B012.
 ********************************************************************/
#include<iostream>
#include"double_linked_list.cpp"
using namespace std;

/********************************************************************
 * pow_of_any_number is a function that calculates power of a number
 * with in long long int.
 * Arguments : base and power are arguments.
 * It returns nothing.
 *******************************************************************/
void pow_of_any_number(int num,int power)
{
	int temp1,temp2,carry,i;
	int pow=power;
	list* base_list=NULL;
	if(num<0)
		num*=-1;
	temp1=num;
	if(num!=0 && power!=0){
		while(temp1>0){
			base_list=add_node_in_list(base_list,temp1%10);				//storing base in a 2-way linked list.
			temp1/=10;
		
		}
		list* temp_list=NULL;
		list* last_temp=NULL;

		while(pow>1)																		//calculating power iteratively.
		{
			carry=0;
			temp_list=base_list;
			i=list_size(base_list);
			while(i>0){
			 		temp2=temp_list->data*num+carry;
			 		temp_list->data=temp2%10;
			 		carry=temp2/10;
			 		last_temp=temp_list;
			 		temp_list=temp_list->rear;
			 		i--;
			}
			while(carry>0){																//if carry is left.
				base_list=add_node_in_list(base_list,carry%10);
				carry/=10;
			}
			pow--;
		}

		while(last_temp->rear!=NULL)
			last_temp=last_temp->rear;
		if(num<0 && power%2!=0)
			cout <<"-";
		while(last_temp!=NULL){
				cout <<last_temp->data;
				last_temp=last_temp->front;
				}
				cout <<endl;
	}
	else if(power==0){																			
		cout<< 1<<"\n";
		return;
	}		
	else cout <<0 <<endl;
		return ;
}
		
int main()									// main function calls pow_of_any_number function which calcultes power.
{
   cout <<"enter the number and power" <<endl;
    long long int n,power;     
    cin >>n >>power;
    pow_of_any_number(n , power);
    return 0;
}
    
