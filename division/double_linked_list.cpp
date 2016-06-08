using namespace std;
typedef struct linked_list list;
struct linked_list{
       list* rear;
       int data;
       list* front;
};
typedef struct list_ptr ptrs;
struct list_ptr{
    list* lst1;
    list* lst2;
};

 
list* list_new(int num){
    list *new_node=new list;
     new_node->rear=NULL;
     new_node->data=num;
     new_node->front=NULL;
    return new_node;
}

list *add_node_in_list(list*l,int data_element){
     list*flag_node=l;
     list*new_node=list_new(data_element);
          if(l==NULL)
        l=new_node;
     else{
          while(flag_node->rear!=NULL)
          flag_node=flag_node->rear;
          
          new_node->front=flag_node;
          flag_node->rear=new_node;
     }
     return l;
}

list * add_list_in_reverse(list* l,int data_element)
{
    list*flag_node=l;
     list *new_node=new list;
     new_node->rear=NULL;
     new_node->data=data_element;
     new_node->front=NULL;
     if(l!=NULL){
          new_node->rear=flag_node;
          flag_node->front=new_node;
          l=new_node;
     }
     else if(l==NULL)
        l=new_node;
        return l;
   
}

int list_size(list*l)
{
   list*temp_list=l;
   int counter=0;
   while(temp_list!=NULL)
   {
       temp_list=temp_list->rear;
       counter++;
   }
   return counter;
}
list* string_to_int(string& str)
{
   int l=str.length();
   list* long_num1=NULL ;
   int p,i=0;
   while(str[i]=='0' && i<l)
   i++;
   if(i==l){
   long_num1=add_node_in_list(long_num1,0);
   return long_num1;
   }else{
   while(i<l){
     if(isdigit(str[i])){
        p=str[i++]-'0';
        long_num1=add_list_in_reverse(long_num1,p);
        }else if(str[0]=='-')
             i++;
        else break;
   } 
  }   
   if(i<l)
   return NULL;
   else return long_num1;
   
}
list**string_to_int_for_division(string &str){
           int len=str.length();
   list** l=new list* [2];
   l[0]=NULL;
   l[1]=NULL;
   int p,i=0;
   while(str[i]=='0' && i<len)
   i++;
   
   if(i==len){
    l[0]=add_node_in_list(l[0],0);
    l[1]=add_list_in_reverse(l[1],0);
    return l; 
   }else{
   int temp=len-1;
   int q;
   while(i<len){
     if(isdigit(str[i])){
        p=str[i++]-'0';
        q=str[temp--]-'0';
         l[0]=add_node_in_list(l[0],p);
         l[1]=add_list_in_reverse(l[1],q);
        }else if(str[0]=='-')
             i++;
        else break;
   }
 }
   if(i<len)
   return NULL;
   else return l;
        
}




