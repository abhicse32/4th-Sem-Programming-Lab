#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include"double_linked_list.cpp"
using namespace std;


void multiply(list* num1, list* num2)
{
    if(num1==NULL || num2==NULL){
    cout <<"enter both numbers properly:\n";
    return ;
    }
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
     if(list_size(result)<=2){
       if(result->rear!=NULL)
       cout <<result->rear->data ;
       if(result!=NULL)
       cout <<result->data;
     }
     else{
    traverse=pos_shift;
    while(traverse->rear!=NULL)
    traverse=traverse->rear;
    
    while(traverse!=NULL){
    cout <<traverse->data ;
    traverse=traverse->front;
    }
  }
    cout <<endl;
    return;
    
}
int main()
{
      cout <<"Enter first Number(after each digit give space): \n";
      string str;
      cin>>str;
      list*long_num1=string_to_int(str);
      cout <<"Now enter second number:\n";
      cin >>str;
      list* long_num2=string_to_int(str);
     cout <<"result is : \n";
     multiply(long_num1,long_num2);
    cout <<endl;
      return 0;
 }
