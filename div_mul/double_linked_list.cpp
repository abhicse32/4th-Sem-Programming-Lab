using namespace std;
typedef struct linked_list list;
struct linked_list{
       list* rear;
       int data;
       list* front;
};
/********************************************************************
 * add_node is a function that adds digit to the list.
 * Arguments : list* and digit to be added.
 * It returns llist*.
 *******************************************************************/


list *add_node_in_list(list*l,int data_element){
     list*flag_node=l;
     list *new_node=new list;
     new_node->rear=NULL;
     new_node->data=data_element;
     new_node->front=NULL;
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
/********************************************************************
 * list_size is a function that gives size of list.
 * Arguments : llist* is argument.
 * It returns size of list.
 *******************************************************************/

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
   while(l>0){
     if(isdigit(str[i])){
        p=str[i++]-'0';
        long_num1=add_list_in_reverse(long_num1,p);
        }else break;
     l--;
   }
   if(l>0)
   return NULL;
   else return long_num1;
   
}

