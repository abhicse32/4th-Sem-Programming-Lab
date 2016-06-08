#include<iostream>
#include"double_linked_list.cpp"
#define TRUE 1
#define FALSE 0
#include<string>
list * mul(list *lst, int num);
using namespace std;
bool sub_div(list* l1_, list* l2_){
   list * l1=l1_;
   list* l2=l2_;
    while(l2!=NULL){
       if(l2->data > l1->data)
       return FALSE;
       else if(l1->data > l2->data)
       return TRUE;
       l2=l2->rear;
       l1=l1->rear;
    }
    return TRUE;
}

void sub_from_index(list * lst1, list* lst2, int i){
     while(i>1){
         lst1=lst1->rear;
         if(lst2->rear!=NULL)
         lst2=lst2->rear;
         i--;
     }
     int borrow=0, step_res=0;
     while(lst2!=NULL){
        step_res=lst1->data-borrow-lst2->data;
        if(step_res<0){
          step_res+=10;
          borrow=1;
        }
        lst1->data=step_res;
        lst1=lst1->front;
        lst2=lst2->front;
     }
    while(lst1!=NULL){
        step_res=lst1->data - borrow;
         if(step_res<0){
           step_res+=10;
           borrow=1;
        }
        lst1->data=step_res;
        lst1=lst1->front;
     }
     return;
}
list** long_div(list* num,list*denom, list* denom_rev){
    list **ptr=new list* [2];
    
    ptr[0]=NULL;
    ptr[1]=NULL;
        if(num==NULL || denom==NULL){
          cout <<"enter correct numbers\n";
     }else if(denom->data==0){
        cout <<"infinity\n";
     }else{
     
      int size1=list_size(num);
      int size2=list_size(denom);
      
      list* qotient=NULL;
      list* remainder=NULL;
     if(size1<size2){
        qotient=add_node_in_list(qotient ,0);
        remainder=num;

        }else {
         int temp=0;
         int flag1,flag2;
         list * temp_list=NULL;
                while(size1 >= size2){
                flag1=0;flag2=0;
                       if(num->data >= denom->data)
                         temp=num->data/denom->data;
                       else if(num->data < denom->data){
                        temp=(num->data + num->rear->data)/denom->data ;
                          flag1++;
                        } 
                        temp_list=mul(denom_rev,temp);
                        bool boolean=sub_div(num,temp_list);
                        if(boolean)
                            sub_from_index(num,temp_list,size2+flag1);
                        
                        else if(!boolean && (size2==size1)){
                           remainder =num;
                           break;
                        }else {
                            temp_list=mul(denom_rev,temp-1);
                            sub_from_index(num,temp_list, temp+flag1);
                            flag2++;
                        }
                        if(flag1=1)
                         qotient= add_node_in_list(qotient,0);
                         if(flag2==1)
                        qotient= add_node_in_list(qotient,temp-1);
                        else qotient= add_node_in_list(qotient,temp);
                        
                        delete [] temp_list;
                        while(num->data==0){
                        temp_list=num;
                        num=temp_list->rear;
                        delete temp_list;
                        qotient= add_node_in_list(qotient,0);
                        }
                        size1=list_size(num);
             } 
        }
        ptr[0]=qotient;
        ptr[1]=remainder;
        
     }
     return ptr;
}
int main(){
      string str;
      list **num=NULL;
      list **denom=NULL;
      int flag1=0,flag2=0;
      cout <<"Enter the numerator:\n";
      cin >> str;
      if(str[0]=='-')
          flag1++;
       
      num=string_to_int_for_division(str);
       delete [] num[1];
      cout <<"Now enter the denominator:\n";
      cin>> str;
      
      if(str[0]=='-')
      flag2++;
      denom=string_to_int_for_division(str);
      list** ptr=NULL;
      
      ptr=long_div(num[0],denom[0], denom [1]);
      cout <<"qotient is: \n";
         while(ptr[0]!=NULL){
             cout <<ptr[0]->data;
             num[0]=ptr[0]->rear;
         }     
         cout <<"\n and remainder is :\n";
         while(ptr[1]!=NULL){
             cout <<ptr[1]->data;
             num[1]=ptr[1]->rear;
         }    
         cout <<endl; 

      return 0;
}


list * mul(list *lst, int num){
    list *local =lst;
    list *result=NULL;
    int tmp=0,carry=0;
     while(local!=NULL){
         tmp=carry+local->data *num;
         result=add_list_in_reverse(result,tmp%10);
         carry=tmp/10;
         local=local->rear; 
     }
     while(carry>0)
     {
         result=add_list_in_reverse(result, carry);
         carry/=10;
     }
     return result;
}

