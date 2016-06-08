#include<iostream>
#include"double_linked_list.cpp"
using namespace std;
int  compare_list(list* num1, list* num2)
{
    int flag=0;
        list*l1=num1;
        list*l2=num2;
        while(l1->rear!=NULL){
            l1=l1->rear;
            l2=l2->rear;
        }
        while(flag==0 && l1!=NULL){
           if(l1->data>l2->data)
           flag++;
           else if(l1->data<l2->data)
             flag--;
             l1=l1->front;
             l2=l2->front;
        }
        return flag;
}
void sub(list* num1,list *num2,int flag1,int flag2)
{
    list *l1=NULL;
    list *l2=NULL;
    int size1=list_size(num1);
      int size2=list_size(num2);
       int k=0;
     if(num1==NULL || num2==NULL){
          cout <<"enter correct numbers\n";
          return ;
     }
     else if( list_size(num1)==list_size(num2)){
       k=compare_list(num1,num2);
          if(k==1){
             l1=num1; 
             l2=num2;
          }else if(k==-1) {
              l1=num2;
              l2=num1;
          }else { cout<<"0";
          return ; 
        }
     }else {
        l1= size1>size2 ? num1 : num2;
        l2=size1 < size2 ?num1 : num2;
    }
    
    if(flag1==1 && flag2==0 && (size1>size2) || k==-1)
         cout <<"-";
    else if(flag1==0 && flag2==1 && (size2>size1))
         cout <<"-";
    int borrow=0;
    int temp=0;
    list* temp2=NULL;
    while(l2!=NULL){
        temp=l1->data - l2->data - borrow;
        if(temp<0){
           temp+=10;
           borrow=1;
        }
        l1->data=temp;
        temp2=l1;
        l1=l1->rear;
        l2=l2->rear;
    }
    while(l1!=NULL){
        temp=l1->data - borrow;
         if(temp<0){
           temp+=10;
           borrow=1;
        }
        l1->data=temp;
        temp2=l1;
        l1=l1->rear;
     }
     while(temp2->rear!=NULL)
      temp2=temp2->rear;
      
      while(temp2!=NULL)
      {
           cout << temp2->data;
           temp2=temp2->front;
      }
      cout <<endl;
      return;
    
     
}
void add(list* num1,list*num2, int flag1,int flag2){

     if(num1==NULL || num2==NULL){
          cout <<"enter correct numbers\n";
          return ;
     }
     int size1=list_size(num1);
     int size2=list_size(num2);
      if(flag1==1 && (flag2==1 || flag2==0))
      cout <<"-";      
   
    list *l1= size1>=size2? num1 : num2;
    list *l2=size1 < size2 ?num1 : num2;
    int carry=0;
    int temp=0;
    list* temp2=NULL;
    while(l2!=NULL){
        temp=l1->data+l2->data+carry;
        carry=temp/10;
        l1->data=temp%10;
        temp2=l1;
        cout <<l1->data <<endl;
        l1=l1->rear;
        l2=l2->rear;
    }
    while(l1!=NULL){
        temp=l1->data+carry;
        carry=temp/10;
        l1->data=temp%10;
        temp2=l1;
        l1=l1->rear;
    }
    if(l1==NULL && carry!=0){
      list* l=list_new(carry);
      l->front=temp2;
      temp2=l; 
      }
     while(temp2!=NULL)
      {
          cout <<temp2->data;
          temp2=temp2->front;
      }
     return;
}
int main(){
      int flag1=0,flag2=0;
      
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
          char ch;
        cout <<"enter the type of operation(+ or -) you want to perform:";
        cin >>ch;
        if((ch=='+' && !(flag1^flag2)) || (ch=='+' && (flag1*flag2)))
          add(long_num1, long_num2,flag1,flag2);
        else if(ch=='+' && (flag1^flag2))
           sub(long_num1, long_num2,flag1,flag2);
           
        else if((ch=='-' && !(flag1^flag2)) || (ch=='-' && (flag1*flag2)))
          sub(long_num1, long_num2,flag1,flag2);
        else if(ch=='-' && (flag1^flag2))
              add(long_num1, long_num2,flag1,flag2);
         cout <<endl;
      return 0;
}
