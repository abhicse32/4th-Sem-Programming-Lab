#include<iostream>
using namespace std;
int main()
{
    int i=0;
    int temp1,temp2,n,k;
    int carry;
    cout <<"enter the number\n";
    cin >>n;
    int *arr1=new int[2*n];
    temp1=n;
    if(temp1>0){
		while(temp1>0){
			arr1[i++]=temp1%10;
			temp1/=10;
		}
		while(n>1)
		{
			--n;
			k=0;
			carry=0;
			while(k<i){
		   		temp2=arr1[k]*n+carry;
		   		arr1[k]=temp2%10;
		   		carry=temp2/10;
		   		k++;
			}
			while(carry>0){
				arr1[k++]=carry%10;
				carry/=10;
				i=k;
			}
		}	
		for(i=k-1;i>=0;i--)
			cout <<arr1[i];
			cout <<endl;
		}
		else if(n==0)
        cout <<"1 \n";
		else 
		cout <<"Enter Positive Number\n";
return 0;
}
