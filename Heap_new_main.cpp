#include<iostream>
#include"Heap_new.cpp"
#include<vector>
using namespace std;

int main()
{
     int i,j,k,n;
     cout <<"Enter the number of elements in the heap:\n";
     cin >> n;
     vector<int>arr;
     cout <<"Enter the entries: \n";
     for(i=0;i<n;i++){
     cin >>k;
      arr.push_back(k);
      }
     build_max_heap(arr,n);
     
     cout <<"array after build_max_heap: \n";
     for(i=0;i<n;i++)
     cout <<arr[i] <<" ";
     cout <<endl;
     
     h* root_=heap_create(arr,n);
     queue* q=NULL;
     q=queue_push(q,root_);
     int level=queue_size(q);
     cout <<"levelwise tree is: \n";
     print_levelwise(root_,q,level);
     cout <<"\nWhat operation do you want:\n";
     
     cout <<"1: Insert\n" <<"2: Extract_Max\n" <<"3: Increase-Key\n";
     cin >>j;
     switch(j){
      case 1:
         cout <<"\nInsert an element:\n";
         cin >> k;
         arr.push_back(k);
     
          Max_Heap_Insert(arr,n);
          n++;
          cout <<"after Inserting " <<k <<" array is:\n";
          for(i=0;i<n;i++)  cout <<arr[i] <<" ";
          cout <<endl;
          break;
       case 2:
           root_=heap_extract_max(arr,n);
            cout <<"\nafter Extract_max :\n";
            n--;
           for(i=0;i<n;i++)
             cout <<arr[i] <<" ";
             cout <<endl;
             break;
       case 3:
            int key;
            cout <<"Enter the increase-key and the index:\n";
            cin >> key >>i;
            root_=heap_increase_key(arr,i,n,key);
              if(root_==NULL)  return 0;
            cout <<"after increasing the key of " <<i << ", heap is: \n";
           for(i=0;i<n;i++)
              cout <<arr[i] <<" ";
             cout <<endl;
             break;
        default :
            cout <<"Wrong Operation:\n";
            break;
      }
          root_=heap_create(arr,n);
     q=NULL;
     q=queue_push(q,root_);
      level=queue_size(q);
     cout <<"levelwise tree is: \n";
     print_levelwise(root_,q,level);
    cout <<"\n";
     return 0;
}

