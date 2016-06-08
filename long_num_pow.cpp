#include<iostream>
#include"double_linked_list.cpp"
using namespace std;

list* pow_of_any_number(list* fact_list,int pow_index)
 {
    int temp1,temp2,carry,i;
    int temp4=pow_index;
    	
        list*last_temp=fact_list;

    while(pow_index>1)
    {
        last_temp=multiply(fact_list,last_temp);
        	pow_index--;
	}
	
	while(last_temp->rear!=NULL)
	last_temp=last_temp->rear;
	//if(temp3<0 && temp4%2!=0)
	//cout <<"-";
	while(last_temp!=NULL){
			cout <<last_temp->data;
			last_temp=last_temp->front;
			}
			cout <<endl;
			return last_temp;
   }
 
int main()
{
   cout <<"enter the number and power index" <<endl;
    long long int pow_index; 
    string str;    
    cin >> str ;
    cin >> pow_index;
    int flag1=0,token=0,decimal_pos1=0;
    int len=str.length();
      int i=0,j;
      j=str[0]=='-' ?1:0;
      flag1=j;
      while(str[j]=='0')
      j++;  i=j;
      j=0;
      list* fact_list=NULL;
      len--;
      int temp=len;
      cout <<len <<endl;
      while(len>=i){
          if(isdigit(str[len]))
            fact_list=add_node_in_list(fact_list,str[len]-'0');
          else if(str[len]=='.' && !token){
            decimal_pos1=temp-len;
            token++;
            }
           else break;
           len--;
      }
      
      if(i<len){
          cout <<"Enter the number properly: \n";
          return 0;
      }
      /*while(fact_list->rear!=NULL)
      {
         cout <<fact_list->data ;
         fact_list=fact_list->rear;
      }*/
      
  pow_of_any_number(fact_list, pow_index);
    return 0;
}
    
