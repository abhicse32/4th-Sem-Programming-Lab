#include"Deap.h"
#include<string>
#include<cmath>
using namespace std;

void swap(int& a,int& b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
}

bool Check_max(int n){
   int k=1;
   int x;
   while(k){
      x=pow(2,k-1);
      if((3*x-1)<=n && n<=(4*x-2))
      return true;
      else if((3*x-1)>n)
      break;
      k++;
   }
   return false;
 }
 int corresponding_min_index(int n){
      int quotient,i=0;
      quotient=n/pow(2,i);
      while(quotient!=1){
          i++;
          quotient=n/pow(2,i);
      }
      return (n-pow(2,i-1));
 }
int corresponding_max_index(int n)
{
     int i=0;
     int x=n+1;
     int quotient=x/pow(2,i);
     while(quotient!=1)
     {
        i++;
        quotient=x/pow(2,i);
     }
     return (x+pow(2,i-1))/2-1;
}
 void Insert_max(int *arr,int i)
 {
    int r=(i+1)/2-1;
   if(r>0 && arr[r]<arr[i]){
   swap(arr[i],arr[r]);
    Insert_max(arr,r);
    
     }else return;
 }
 void Insert_min(int *arr, int i)
 {
     int r=(i+1)/2-1;
   if(r>0 && arr[r]>arr[i]){
   swap(arr[i],arr[r]);
    Insert_min(arr,r);
    
     }else return;
 }
 
void Insert_deap(int *arr, int  data,int n)
{
    if(n==1) arr[1]=data;
    else {
    arr[n]=data;
    int i;
    switch(Check_max(n)){
         case true:
            i=corresponding_min_index(n); 
            if(data<arr[i])  {
            swap(arr[i],arr[n]);
            Insert_min(arr,i);
            }
            else Insert_max(arr,n);
            break;
         case false:
            i=corresponding_max_index(n);
            if(data>arr[i]){
               swap(arr[i],arr[n]);
               Insert_max(arr,i);
            }
            else Insert_min(arr,n);
    }
  }
    return ;
}
 int Find_Min(int *arr, int n )
 {
    if(n<=1) return arr[0];
    else return arr[1];
 }
int Find_Max(int *arr, int n){
      if(n<=1) return arr[0];
      else if(n==2) return arr[1];
      else return arr[2];
}

void Min_Heapify(int *arr, int i, int n)
{
    int l,r,smallest=i;
   l=2*i+1;
   r=l+1;
   if(l<n){
         if(arr[l]<=arr[r]){
            swap(arr[i],arr[l]);
            Min_Heapify(arr,l,n);
         }else
         {
              swap(arr[r],arr[i]);
              Min_Heapify(arr,r,n);
         }
      }
          return ;
}
void Max_Heapify(int *arr, int i, int n){
   int l,r,largest=i;
   l=2*i+1;
   r=l+1;
     if(l<n){
        if(arr[l]>=arr[r]){
          swap(arr[i],arr[l]);
          Max_Heapify(arr,l,n);
          
        }
        else {
        swap(arr[i],arr[r]);
        Max_Heapify(arr,r,n);
        }
     }
     return ;
}
void Delete_Min(int *arr,int n){
      if(n>1){
     int  i=1;
         arr[i]=arr[n-1];
         Min_Heapify(arr,i,n);
         Insert_min(arr,i);
      }
      return;
}
void Delete_Max(int *arr, int n){
    if(n>2){
      int i=2;
      arr[i]=arr[n-1];
      Max_Heapify(arr,i,n);
      if(i*2+1<n){
         if(arr[i]<arr[n-2])
         swap(arr[i],arr[n-2]);
      }
    }
 }
