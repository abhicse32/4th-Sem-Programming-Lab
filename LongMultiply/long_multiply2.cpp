#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include"double_linked_list.cpp"
using namespace std;


list* multiply(string &str1,int len1, string &str2,int len2)
{
 
    if(len1<=0 || len2<=0){
    cout <<"enter both numbers properly:\n";
    return NULL;
    }
    string str3;
    string str4=str2;
    int i,j,k;
    list*result=NULL;
        list* pos_shift=NULL;
     list*traverse=NULL;
      for(i=len2-1;i>=0;i--){
        int carry=0,result_digit=0;;
        int k=str2[i]-'0';
        if(result !=NULL){
           traverse=pos_shift;
           for(j=len1-1;j>=0;j--){
             if(traverse!=NULL){
               result_digit=k*(str1[j]-'0')+traverse->data+carry;
               traverse->data=result_digit%10;
               carry=result_digit/10;
               traverse=traverse->rear;
               }
                 else{
                 result_digit=k*(str1[j]-'0')+carry;
                result=add_node_in_list(result,result_digit%10);
                 carry=result_digit/10;
                }
           }
           pos_shift=pos_shift->rear;
        }
        else if(result==NULL){
        for(j=len1-1;j>=0;j--){
          result_digit=(str1[j]-'0')*k+carry;
          result=add_node_in_list(result,result_digit%10);
          carry=result_digit/10;
        }
        pos_shift=result->rear;
      }
        while(carry>0){
         result=add_node_in_list(result,carry%10);
         carry/=10;  
        }
     }
     if(list_size(result)<=2){
       if(result->rear!=NULL)
       result=result->rear;
       return result;
    }
     else{
    result=pos_shift;
    while(result->rear!=NULL)
    result=result->rear;
    
   return result; }
    
}
int main()
{     int flag1=0,flag2=0,token=0;
     int decimal_pos1=0,decimal_pos2=0;
      cout <<"Enter first Number\n";
      string str;
      cin>>str;
      string str1,str2;
      int len=str.length();
      int i=0,j;
      j=str[0]=='-' ?1:0;
      flag1=j;
      while(str[j]=='0')
      j++;  i=j;
      j=0;
      str1=str;
      while(i<len){
          if(isdigit(str[i]))
            str1[j++]=str[i++];
          else if(str[i]=='.' && !token){
            decimal_pos1=i;
            token++;
            }
           else break;
      }
      
      if(i<len){
          cout <<"Enter first number properly: \n";
          return 0;
      }
      token=0;
      cout <<"Enter second number: \n";
      cin >> str;
      int len2=str.length();
      
      int  j1=str[0]=='-' ?1:0;
      flag2=j1;
      while(str[j1]=='0')
      j1++;  
      i=j1;
      j1=0;
      str2=str;
      while(i<len2){
          if(isdigit(str[i]))
            str2[j1++]=str[i++];
            else if(str[i]=='.' && !token){
                token++;
                decimal_pos2=i;
            }
            
           else break;
      }
      
      if(i<len2){
          cout <<"Enter second number properly: \n";
          return 0;
      }
       cout <<"result is : \n";
     if(flag1^flag2)
     cout <<"-";
     list*traverse= multiply(str1,j,str2,j1);
     token=decimal_pos1+decimal_pos2;
    // cout <<decimal_pos1 <<"  " <<decimal_pos2 <<endl;
     //cout <<j <<"  " <<j1 <<endl; 
     while(traverse!=NULL){
      token--;
    cout <<traverse->data ;
    //if()
    traverse=traverse->front;
   }
    cout <<endl;
 
           return 0;
 }
