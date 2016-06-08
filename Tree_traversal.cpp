#include<iostream>
using namespace std;
#include"stack.cpp"

void Inorder_traversal(TNode* root)
{
	TNode* new_ = root;
	stack* stack_in = stack_new_();
	if(new_==NULL)
		cout <<endl;
	else{
		push(stack_in,new_);										//pushing address of root element
		while(stack_in->head!=NULL){
			if(new_->left!=NULL){
				push(stack_in,new_->left);						//pushing address of left child of new_
				new_ = new_->left;			
			}
			else if(new_->left==NULL && new_->right==NULL){
				while(new_->right==NULL){
					cout <<new_->data <<"\t";					//if no right child then print the node & pop it
					pop(stack_in);
					if(stack_in->head==NULL)
						break;
					new_=stack_in->head->address;
				}
				if(new_->right!=NULL){	
					cout <<new_->data <<"\t";
					new_=new_->right;
					pop(stack_in);								//if node has right child then poping the node 
					push(stack_in,new_);							// then pushing right child
				}
			}
			else if(new_->left==NULL && new_->right!=NULL){		 
				cout <<new_->data <<"\t";
				new_=new_->right;
				pop(stack_in);									//when no left child then pop the node
				push(stack_in,new_);								//and push its right child
			}									
		}
		delete(stack_in);
	}
}

void Preorder_traversal(TNode* root)
{
	TNode* new_ = root;
	stack* stack_pre=stack_new_();
	if(new_==NULL)
		cout <<endl;
	else{
		cout <<new_->data <<"\t";
		push(stack_pre,new_);									//pushing address of root element
		while(stack_pre->head!=NULL){
			if(new_->left!=NULL){
				cout <<new_->left->data<<"\t";
				push(stack_pre,new_->left);						//pushing address of left child of new_
				new_=new_->left;
			}	
			else if(new_->left==NULL && new_->right==NULL){
				while(new_->right==NULL){
					pop(stack_pre);								//if no right child then pop it
					if(stack_pre->head==NULL)
						break;
					new_=stack_pre->head->address;
				}
				if(new_->right!=NULL){
					new_=new_->right;
					pop(stack_pre);								//if node has right child then poping the node 
					cout <<new_->data <<"\t";					
					push(stack_pre,new_);						// then pushing right child
				}
			}
			else if(new_->left==NULL && new_->right!=NULL){
				new_=new_->right;
				pop(stack_pre);									//when no left child then pop the node
				cout <<new_->data <<"\t";						//and push its right child
				push(stack_pre,new_);							
			}
		}
		delete(stack_pre);
	}
}

void Postorder_traversal(TNode* root)
{
	TNode* new_ = root;
	stack* stack_post=stack_new_();								//stac_post is used for traversal of tree in N-R-L order
	stack* stack_true=stack_new_();								//stack_ture has Post order elements
	if(new_==NULL)
		cout<<"\n";
	else{
		push(stack_post,new_);									//pushing address of root element
		push(stack_true,new_);									//pushing address of root element
		while(stack_post->head!=NULL){
			if(new_->right!=NULL){
				push(stack_post,new_->right);					//pushing address of right child of new_
				new_=new_->right;
				push(stack_true,new_);							//pushing address of right child of new_
			}	
			else if(new_->left==NULL && new_->right==NULL){
				while(new_->left==NULL){
					pop(stack_post);							//popping stack_post if left child is NULL
					if(stack_post->head==NULL)
						break;
					new_=stack_post->head->address;
				}
				if(new_->left!=NULL){
					new_=new_->left;
					pop(stack_post);							//popping stack_post to ensure it will not be reached again
					push(stack_post,new_);						//pushing address of left child of new_
					push(stack_true,new_);						//pushing address of left child of new_
				}
			}
			else if(new_->left!=NULL && new_->right==NULL){
				new_=new_->left;
				pop(stack_post);								//popping stack_post to ensure it will not be reached again
				push(stack_post,new_);							//pushing address of left child of new_
				push(stack_true,new_);							//pushing address of left child of new_
			}			
		}
		stack_print(stack_true);
		delete(stack_post);
		delete(stack_true);
	}
}
				
int main()
{
	TNode* tree=NULL;
	TNode* tmp;
	cout <<"Enter tree-size: ";
	int n,i,temp;
	cin >>n;
	if(n>0){
	    cout <<"enter the entries in the tree\n";
		for(i=0;i<n;i++){
			cin >>temp;
			if(tree==NULL){
				tree=TNode_new_();
				tree->data=temp;
				tmp=tree;		
			}
			else{
				tmp=tree;
				while(1){										//binary tree construction
					if(tmp->data>=temp){
						if(tmp->left!=NULL)
							tmp=tmp->left;						//go to left if data is less than or equal to poinnting node
						else{
							tmp->left=TNode_new_();
							tmp->left->data=temp;
							break;
						}					
					}
					else if(tmp->data<temp){					//go to right if data is more than the pointing node
						if(tmp->right!=NULL)
							tmp=tmp->right;
						else{
							tmp->right=TNode_new_();
							tmp->right->data=temp;
							break;
						}
					}
				}
			}
		}
		cout <<"Inorder :: \n";
		Inorder_traversal(tree);								//In-order function call
		cout <<endl;
		cout<<"Preorder :: \n";
		Preorder_traversal(tree);								//Pre-order function call
		cout<<"\n";
		printf("Postorder :: \n");
		Postorder_traversal(tree);								//Post-order function call
		cout<<"\n";		
	}
	else
		cout<<"Enter positive value\n";
}
