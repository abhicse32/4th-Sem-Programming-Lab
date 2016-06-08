#include<iostream>
#include<string>
#include<cmath>
#include"Deap.cpp"
using namespace std;

int main(){

    int i=1,j,k,n;
    int *deap_arr=new int[100];
     cout <<"currently deap doesn't have any entries, would like to insert:\n";
     cin>> k;
     while(k){
         Insert_deap(deap_arr,k,i);
         i++;
         cout <<"current deap is: \n";
         for(k=0;k<i;k++)
           cout <<deap_arr[k] <<" ";
         cout <<endl;
         cout<<"Please Enter another entry(any character input to exit): ";
         cin >>k;
     }
     cout <<"largest element is: ";
     cout <<Find_Max(deap_arr,i) <<endl;
     cout <<"Smallest is deap is: ";
     cout <<Find_Min(deap_arr,i) <<endl;
     cout <<"After Deleting maximum element : \n";
      Delete_Max(deap_arr,i);
      for(k=0;k<i-1;k++)
           cout <<deap_arr[k] <<" ";
           cout <<endl;
           i--;
      cout <<"After deleting min element from the heap:\n";
      Delete_Min(deap_arr,i);
       for(k=0;k<i-1;k++)
           cout <<deap_arr[k] <<" "; 
           cout <<endl;
    return 0;     
}
