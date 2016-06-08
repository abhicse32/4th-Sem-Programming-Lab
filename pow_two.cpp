#include<iostream>
#include"double_linked_list.cpp"
using namespace std;


 void pow_of_any_number(int num,int pow_index)
 {
    int temp1,temp2,carry,i;
    int temp3=num;
    int temp4=pow_index;
     list* fact_list=NULL;
    if(num<0)
    num*=-1;
     temp1=num;
    if(num!=0){
		while(temp1>0){
			fact_list=add_node_in_list(fact_list,temp1%10);
			temp1/=10;
			
		}
		list* temp_list=NULL;
		list*last_temp=NULL;

    while(pow_index>1)
    {
        
        carry=0;
           temp_list=fact_list;
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
		pow_index--;
	}
	
	while(last_temp->rear!=NULL)
	last_temp=last_temp->rear;
	if(temp3<0 && temp4%2!=0)
	cout <<"-";
	while(last_temp!=NULL){
			cout <<last_temp->data;
			last_temp=last_temp->front;
			}
			cout <<endl;
            }
            else cout <<num <<endl;
		return ;
		}
 
int main()
{
   cout <<"enter the number and power index" <<endl;
    long long int n,pow_index;     
    cin >>n >>pow_index;
    pow_of_any_number(n , pow_index);
    return 0;
}
    
