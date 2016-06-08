#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include"double_linked_list.cpp"
using namespace std;


list* multiply(list* num_1, list* num_2)
{
    if(num_1==NULL || num_2==NULL){
    cout <<"enter both numbers properly:\n";
    return NULL;
    }
    list *num1=num_1;
    list* num2=num_2;
    list* result=NULL;
    list* temp=NULL;
    list* pos_shift=NULL;
     list*traverse=NULL;
      while(num2!=NULL){
        int carry=0,result_digit=0;;
        int k=num2->data;
        temp=num1;
        if(result !=NULL){
           traverse=pos_shift;
           while(temp!=NULL){
           if(traverse!=NULL){
               result_digit=k*temp->data+traverse->data+carry;
               traverse->data=result_digit%10;
               carry=result_digit/10;
               traverse=traverse->rear;
               }
                 else{
                 result_digit=k*temp->data+carry;
                result=add_node_in_list(result,result_digit%10);
                 carry=result_digit/10;
                }
                                temp=temp->rear;
           }
           pos_shift=pos_shift->rear;
        }
        else if(result==NULL){
        while(temp!=NULL){
          result_digit=temp->data*k+carry;
          result=add_node_in_list(result,result_digit%10);
          carry=result_digit/10;
          temp=temp->rear;
        }
        pos_shift=result->rear;
      }
        while(carry>0){
         result=add_node_in_list(result,carry%10);
         carry/=10;  
        }
        num2=num2->rear;
     }
   /*  if(list_size(result)<=2){
       if(result->rear!=NULL)
       result=result->rear;
       return result;
    }
     else{
    result=pos_shift;
    while(result->rear!=NULL)
    result=result->rear;
    
   return result; }*/
   return result;
    
}
int main()
{     int flag1=0,flag2=0;
      cout <<"Enter first Number\n";
      string str;
      cin>>str;
      if(str[0]=='-')
      flag1++;
      list*long_num1=string_to_int(str);
      cout <<"Now enter second number:\n";
      cin >>str;
      if(str[0]=='-')
      flag2++;
      list* long_num2=string_to_int(str);
     cout <<"result is : \n";
     if(flag1^flag2)
     cout <<"-";
         list*traverse=NULL;
     int l1=list_size(long_num1);
     int l2=list_size(long_num2);
     
       list *l_num1= l1>=l2 ?long_num1 : long_num2;
       list*l_num2= l1<l2 ?long_num1: long_num2;
     traverse= multiply(l_num1,l_num2);

 while(traverse!=NULL){
    cout <<traverse->data ;
    traverse=traverse->front;
   }
    cout <<endl;
    
       return 0;
 }
