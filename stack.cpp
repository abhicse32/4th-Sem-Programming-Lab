/***********************************************************
 * stack.cpp: It is a cpp file having stack related functions.
 * Authors: CS12B035, CS12B012, CS12B032.
 **********************************************************/
#include<iostream>
#include<cstdlib>
#include<new>
using namespace std;

typedef struct tnode TNode;
struct tnode{									//structure tnode is a node of tree
	int data;									//It has data, 2 TNode*
	TNode* left;
	TNode* right;
};

typedef struct node Node;
struct node{									//structure node is a node of stack
	TNode* address;								//It has TNode* and node*
	Node* next;
};

typedef struct Stack stack;
struct Stack{
	Node* head;
};


TNode* TNode_new();
Node* Node_new();
stack* stack_new();
stack* push(stack* ptr,TNode* val);
stack* pop(stack* temp);
TNode* stack_top(stack* temp,int* error);
void stack_print(stack* ptr);
void stack_delete(stack* ptr);
int stack_size(stack* temp);

TNode* TNode_new()								//creates new TNode* and returns it.
{
	TNode* temp=new TNode;
	temp->left=NULL;
	temp->right=NULL;
	return temp;	
}	

Node* Node_new()								//creates new Node* and returns it.
{
	Node* temp=new Node;
	temp->next=NULL;
	return temp;	
}

stack* stack_new()								//creates stack pointer and returns it.
{
	stack* temp=new stack;
	temp->head=NULL;
	return temp;
}

stack* push(stack* ptr,TNode* val)				//pushes data on to the stack.
{
	if(ptr->head==NULL)
	{
		ptr->head=Node_new();
		ptr->head->address=val;
		return ptr;
	}
	else
	{
		Node* temp=Node_new();
		temp->address=val;
		temp->next=ptr->head;
		ptr->head=temp;
		return ptr;
	}
}

stack* pop(stack* temp)							//pops elements of stack
{
	if(temp->head==NULL)
	{
		return temp;
	}
	else
	{
		temp->head=temp->head->next;
		return temp;
	}
}

TNode* stack_top(stack* temp,int* error)		//Gives top element if stack is not empty
{
	if(temp->head==NULL)
		*error = 1;
	else{
		*error = 0;
		return temp->head->address;
	}
}

void stack_print(stack* ptr)					//Prints elements in stack.
{
	Node* temp;
	temp=ptr->head;
	while(temp!=NULL)
	{
		cout<<temp->address->data<<"\t";
		temp=temp->next;
	}
}
	
	
void stack_delete(stack* ptr)							//deletes stack.
{	
	while(ptr->head!= NULL)
	{
		ptr=pop(ptr);
	}
}

int stack_size(stack* temp)						//Gives size of stack.
{
	int a=0;
	Node* ptr = temp->head;
	while(ptr!=NULL)
	{
		a++;
		ptr = ptr->next;
	}
	return a;
}
		
	 
