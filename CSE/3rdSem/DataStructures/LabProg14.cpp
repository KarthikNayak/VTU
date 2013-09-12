#include<iostream>
#include<stdlib.h>
struct node
{
	int info;
	node *llink;
	node *rlink;
};
class tree
{
	node *root
	public:tree()
		{
			root=NULL;
		}
		void inorder(node  *);
		void preorder(node *);
		void postorder(node *);
		void display(int);
		void create(int);
};
void tree :: display(int choice)
{
	switch(choice)
		 {	 
		 	case 1:if(root==NULL)
		 				cout<<"tree is empty"<<endl;
		 				else
		 				{		 				
		 					cout<<"preorder traversal is"<<endl;
		 					preorder(root);
		 				}
		 				break;
		 	case 2:if(root==null)
		 				cout<<"tree is empty"<<endl;
		 				else
		 				{
		 					cout<<"inorder travrsal is"<<endl;
		 					inorder(root);
		 				}	
		 				break;
		 	case 3:if(root==NULL)
		 				cout<<"tree is empty"<<endl;
		 				else
		 				{		 				
		 					cout<<"postorder traversal is"<<endl;
		 					postorder(root);
		 				}
		 				break;
		 }				
}
void tree :: inorder(node *root)	
	{	
		if(root!=NULL);
		{
			inorder(root->llink);
			cout<<root->info<<endl;
			inorder(root->rlink);
		}
	}	
void tree :: preorder(node *root)
	{	
		if(root!=NULL)
		{
			cout<<root->info<<endl;
			preorder(root->llink);
			preorder(root->rlink);
		}
	}
void tree :: postorder(node *root)
	{
		if(root!=NULL)
		{	
			postorder(root->llink);
			postorder(root->rlink);
			cout<<root->info<<endl;	
		}	
	}
void tree :: create(int item)
	{
	  node *temp,*cur,*prev;
	  temp= new node;
	  temp->info=item;
	  temp->llink=NULL;
	  temp->rlink=NULL;
	  if(root==NULL)
	  {
	  	root=temp;
	  	return;
	  }
	 cur=root;
	 prev=NULL;
	 while(cur!=NULL)
	 {
	 	prev=cur;
	 	if(item<cur->info)
	 		cur=cur->llink;
	 	else
	 		cur=cur->rlink;
	 }
	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	}
void main()
{
	tree ob;
	int item,choice;
	for(;;)
	{
		cout<<"1:insert\n 2:preorder"<<endl;
		cout<<"3:inorder\n 4:postorder"<<endl;
		cout<<"5:exit \n";
		cout<<"enter the choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"enter the item";
					cin>>item;
					ob.create(item);
					break;
			case 2:
			case 3:
			case 4: ob.display(choice);
					break;
			default:exit(0);
		}
	}
}		

