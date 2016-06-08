#include<iostream>
#include<cmath>
using namespace std;
#include"double_linked_list.cpp"

void divide(long double num, long double denom,unsigned long long n)
{
    if(denom==0){
     cout <<"infinity\n";
    return ;
    }
    long double temp1,temp2,temp3;
    //counts how many digits are there in numerator after decimal
    int count_after_decimal_num=0;
    //counts digits after decimal in denominator
    int count_after_decimal_denom=0;
    temp1=num;
    temp2=denom;
    if(num<0)
       num*=-1;
    if(denom<0)
       denom*=-1;
    if(num==denom){
          cout << temp1/temp2 <<" " <<endl;
          return;
      }
      // if the numerator is a fraction make it an integer
       unsigned long long temp=ceil(num);

	      while(num<temp){
	       num*=10;
	       temp=ceil(num);
	       cout <<temp  <<" " <<num <<endl;
	       count_after_decimal_num++;
	      }
	   
	unsigned long long temp_=ceil(denom);
	      while(denom<temp_){
	        denom*=10;
	        temp_=ceil(denom);
	        count_after_decimal_denom++;
	     }
	 
	unsigned long long counter=0;
	int count_upto_decimal=0;
	int count_num=0;
	 list* div_list=NULL;
	
	
	 if(temp<temp_){
	     while(temp<temp_)
	     {
	        temp*=10;
	        count_num++;
	     }
	 }
	 if(temp>temp_){
	        int local=temp/temp_;
	       while(local>0){
	         div_list=add_list_in_reverse(div_list,local%10);
	           count_upto_decimal++;
	           local/=10;
	        }
	        temp%=temp_;
	     }
	    
             while(temp<temp_){
                if(counter==n|| temp==0)
                 break;
                   int flag=0;
                     while(temp<temp_){
                        temp*=10;
                        if(flag>=1)
                          div_list=add_node_in_list(div_list,0);
                     flag++;
                 }
                 div_list=add_node_in_list(div_list,temp/temp_);
                 temp%=temp_; 
                 counter++;
                 
	      }
	     
	      if((temp2<0 && temp1>0) || (temp2>0 &&temp1<0))
	      cout <<"-";
	      temp3= count_after_decimal_denom - count_after_decimal_num - count_num + count_upto_decimal;
	      cout <<temp3  <<" " <<count_after_decimal_denom <<" "<<count_after_decimal_num
	      <<" " << count_num <<" " <<count_upto_decimal <<endl;
	      if(temp3<0){
	      cout <<".";
	          while(temp3<0){
	          cout <<"0" ;
	          temp3+=1;
	          }
	           list *flag_list=div_list;
	      while(flag_list!=NULL){
	      cout <<flag_list->data;
	      flag_list=flag_list->rear;
	      }
	     
	   }else {
	      list *flag_list=div_list;
	      while(flag_list!=NULL){
	      if(temp3==0)
	      cout <<".";
	      cout <<flag_list->data;
	      flag_list=flag_list->rear;
	      --temp3;
	      }
	     
	   }
	      cout <<endl;
	      return ;
 }
int main()
{
    long double numerator, denominator;
    cout <<"enter Numerator : ";
    cin >>numerator; 
    cout <<"Enter denominator: ";
    cin>> denominator;
    cout <<"After Decimal, upto how many digits do you want the result:? \n";
    unsigned long long n;
    cin >>n; 
     cout <<"result of division is: \n";  
   divide(numerator,denominator,n);
   return 0;
}
